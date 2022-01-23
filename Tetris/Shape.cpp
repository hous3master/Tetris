#include "Shape.h"
Shape::Shape(int new_x, int new_y) {
	//5 types of tetramino are established randomly
	//Each tetramino has 4 rotation positions
	//-----VISUAL EXPLANATION OF GRID FORMAT-----
	//0  1  2  3
	//4  5  6  7
	//8  9  10 11
	//12 13 14 15
	System::Random^ rnd = gcnew System::Random;
	int type = rnd->Next(0, 4);
	if (type == 0)
		shape = { { 1, 5, 9, 13 }, { 4, 5, 6, 7 }, { 1, 5, 9, 13 }, { 4, 5, 6, 7 } };
	else if (type == 1)
		shape = { { 1, 2, 5, 9 }, { 0, 4, 5, 6 }, { 1, 5, 9, 8 }, { 4, 5, 6, 10 } };
	else if (type == 2)
		shape = { { 1, 4, 5, 6 }, { 1, 4, 5, 9 }, { 4, 5, 6, 9 }, { 1, 5, 6, 9 } };
	else if (type == 3)
		shape = { { 1, 2, 5, 6 }, { 1, 2, 5, 6 }, { 1, 2, 5, 6 }, { 1, 2, 5, 6 } };
	else if (type == 4)
		shape = { { 1, 2, 6, 10 }, { 5, 6, 7, 9 }, { 2, 6, 10, 11 }, { 3, 5, 6, 7 } };
	//Establishment of the other characteristics of a tetramino
	x = new_x; //X coord
	y = new_y; //Y coord
	color = rnd->Next(0, 4); //color index (yello, lightgreen, lightblue, pink)
	rotation = 0; //the rotation is the index that defines the shape, it starts with 0
	set = false; //a tetramino is set when it can no longer fall
}
Shape::~Shape(){}
void Shape::new_set(bool new_data) {
	set = new_data;
}
bool Shape::return_set() {
	return set;
}
void Shape::new_x(int new_data) {
	x = new_data;
}
int Shape::return_x() {
	return x;
}
void Shape::new_y(int new_data) {
	y = new_data;
}
int Shape::return_y() {
	return y;
}
void Shape::Rotate(){
	//the rotation is an index (0-3 inclusive) that represents the state of the shape and is used in the Draw_Shape and return_rectangles functions.
	rotation++;
	if (rotation >= 4) rotation = 0;
}
void Shape::Move(Graphics^ g){
	//a tetramino will fall (increasing its position in the Y-coordinate) until it is set
	if (!set) y++;
}
bool Shape::Is_Able_To_Move_Left() {
	//this function creates a rectangle as if the tetramino had already moved to the left. In this way it determines if it will be outside the grid.
	vector<Rectangle*> hitboxes = return_rectangles();
	for (int i = 0; i < 4; i++) {
		hitboxes.at(i)->X -= 30;
		if (hitboxes.at(i)->X < 0 || set == true)
			return false;
	}
	return true;
}
bool Shape::Is_Able_To_Move_Right() {
	//this function creates a rectangle as if the tetramino had already moved to the right. In this way it determines if it will be outside the grid.
	vector<Rectangle*> hitboxes = return_rectangles();
	for (int i = 0; i < 4; i++) {
		hitboxes.at(i)->X += 30;
		if (hitboxes.at(i)->X + hitboxes.at(i)->Width > 600 || set == true)
			return false;
	}
	return true;
}
void Shape::Translate_Left() {
	//moves the tetramino if the conditions are met
	if (Is_Able_To_Move_Left())
		x--;
}
void Shape::Translate_Right() {
	//moves the tetramino if the conditions are met
	if (Is_Able_To_Move_Right())
		x++;
}
int Shape::Convert_To_X_Coords(int position, int grid_scale) {
	//makes use of mathematics to return the x-position in pixels of the shape format.
	return grid_scale * (position % 4 + x);
}
int Shape::Convert_To_Y_Coords(int position, int grid_scale) {
	//makes use of mathematics to return the y-position in pixels of the shape format.
	return grid_scale* ((position - position % 4) / 4 + y);
}
void Shape::Draw_Shape(Graphics^ g){
	//borders are established
	Pen^ p = gcnew Pen(Color::Black);
	p->Width = 3;
	//the brush is set depending on the previously set color
	SolidBrush^ b;
	if (color == 0) b = gcnew SolidBrush(Color::Yellow);
	else if (color == 1) b = gcnew SolidBrush(Color::LightGreen);
	else if (color == 2) b = gcnew SolidBrush(Color::LightBlue);
	else b = gcnew SolidBrush(Color::Pink);
	//Since the width of the window is 600, each piece of the grid will be 30 wide and will be 20 per side.
	int grid_scale = 30;
	for (int i = 0; i < 4; i++) {
		//detects each of the sub-squares within a tetramino
		int position = (shape.at(rotation)).at(i);
		int print_x = Convert_To_X_Coords(position, grid_scale);
		int print_y = Convert_To_Y_Coords(position, grid_scale);
		//prints the tetraminos with the corresponding pen and brush
		g->DrawRectangle(p, print_x, print_y, grid_scale, grid_scale);
		g->FillRectangle(b, print_x, print_y, grid_scale, grid_scale);
	}
}
vector<Rectangle*> Shape::return_rectangles() {
	//this function returns 4 squares based on the tetramino data, so it is a vector of rectangles.
	vector<Rectangle*> hitboxes;
	//Since the width of the window is 600, each piece of the grid will be 30 wide and will be 20 per side.
	int grid_scale = 30;
	for (int i = 0; i < 4; i++) {
		//detects each of the sub-squares within a tetramino
		int position = (shape.at(rotation)).at(i);
		int print_x = Convert_To_X_Coords(position, grid_scale);
		int print_y = Convert_To_Y_Coords(position, grid_scale);
		//inserts them into the vector to be returned
		hitboxes.push_back(new Rectangle(print_x, print_y, grid_scale, grid_scale));
	}
	return hitboxes;
}
vector<Rectangle*> Shape::return_future_rectangles() {
	//this function returns the subsquares of each tetramino in the case that they have already fallen 1 position lower
	//is used to know if it will intersect or will be outside the grid, and act accordingly.
	vector<Rectangle*> hitboxes = return_rectangles();
	for (int i = 0; i < 4; i++)
		hitboxes.at(i)->Y += 30;
	return hitboxes;
}

#include "Grid.h"
Grid::Grid() {
	key_down_pressed = false; //if true, the speed with which the tetraminos fall increases
	next_tetramino = new Shape(10, 0); //stores the next tetramino to be printed in the corresponding window and then inserted into the main tetramino array
	points = 0; //increases by 100 each time a line is completed
}
Grid::~Grid(){}
bool Grid::All_Tetraminos_Are_Set() {
	//this function returns true in case the set value of all tetraminos is true
	for (int i = 0; i < tetraminos.size(); i++) {
		if (tetraminos.at(i)->return_set() == false || tetraminos.size() < 1) return false;
	}
	return true;
}
void Grid::Insert_Tetramino() {
	//inserts a tetramino when the previous one has fallen down
	if (All_Tetraminos_Are_Set()) {
		//in case the speed has been accelerated, sets it to its standard value
		key_down_pressed = false;
		//inserts the stored tetramino
		tetraminos.push_back(next_tetramino);
		//creates a new tetramino to be stored
		next_tetramino = new Shape(10, 0);
	}
}
void Grid::Draw_Tetramino(Graphics^ g) {
	//iterates each tetramino and invokes its functions for moving and drawing
	for (int i = 0; i < tetraminos.size(); i++) {
		tetraminos.at(i)->Draw_Shape(g);
		tetraminos.at(i)->Move(g);
	}
}
void Grid::Tetramino_Hit_Bottom() {
	//detects if a tetramino touches the bottom to stop its movement
	//by means of the hitboxes of the sub-squares, in case its Y value is >= than 600
	for (int j = 0; j < 4; j++) {
		if (tetraminos.at(tetraminos.size() - 1)->return_future_rectangles().at(j)->Y >= 600) {
			tetraminos.at(tetraminos.size() - 1)->new_set(true);
			return;
		}
	}
}
void Grid::Tetraminos_Intersect() {
	//detects if a falling tetramino collides with another below tetramino to stop its movement
	//iterating each of the sub-squares of the falling tetramino and verifying intersection with the sub-squares of the other tetraminos
	Shape* falling_tetramino = tetraminos.at(tetraminos.size() - 1); //tetramino falling
	//iterates each of the sub-squares of the falling tetramino to see if it intersects
	for (int falling_hitbox_index = 0; falling_hitbox_index < 4; falling_hitbox_index++) {
		Rectangle* falling_hitbox = falling_tetramino->return_future_rectangles().at(falling_hitbox_index); //sub-square of the falling tetramino
		//iterates each tetramino that can collide with the falling one
		for (int obstruct_tetramino_index = 0; obstruct_tetramino_index < tetraminos.size() - 1; obstruct_tetramino_index++) {
			Shape* obstruct_tetramino = tetraminos.at(obstruct_tetramino_index); //potential collider
			//iterates each of the sub-squares of the potential collider to see if it intersects
			for (int obstruct_hitbox_index = 0; obstruct_hitbox_index < 4; obstruct_hitbox_index++) {
				Rectangle* obstruct_hitbox = obstruct_tetramino->return_rectangles().at(obstruct_hitbox_index); //sub-square of the potential collider
				//in case it intersects it means that the falling tetramino will be set
				if (falling_hitbox->IntersectsWith(*obstruct_hitbox)) {
					tetraminos.at(tetraminos.size() - 1)->new_set(true);
					//no further comparison is needed so the function ends.
					return;
				}	
			}
		}
	}
}
void Grid::Set_Tetramino() {
	//Invoke the functions that set the tetraminos to stop moving.
	Tetramino_Hit_Bottom();
	Tetraminos_Intersect();
}
void Grid::Rotate_Tetramino() {
	//rotates the falling tetramino, the function is invoked by keyboard input
	tetraminos.at(tetraminos.size() - 1)->Rotate();
}
bool Grid::Is_Able_To_Move_Left() {
	//detects if a falling tetramino collides with another on the left side to stop its movement
	//iterating each of the sub-squares of the falling tetramino and verifying intersection with the sub-squares of the other tetraminos
	//the function is invoked indirectly by keyboard input
	Shape* falling_tetramino = tetraminos.at(tetraminos.size() - 1);
	for (int falling_hitbox_index = 0; falling_hitbox_index < 4; falling_hitbox_index++) {
		//iterates each of the sub-squares of the falling tetramino to see if it intersects
		Rectangle* falling_hitbox = falling_tetramino->return_rectangles().at(falling_hitbox_index);
		//assumes that the tetramino is one position further to the left
		falling_hitbox->X -= 30;
		//iterates each tetramino that can collide with the falling one
		for (int obstruct_tetramino_index = 0; obstruct_tetramino_index < tetraminos.size() - 1; obstruct_tetramino_index++) {
			Shape* obstruct_tetramino = tetraminos.at(obstruct_tetramino_index); //potential collider
			//iterates each of the sub-squares of the potential collider to see if it intersects
			for (int obstruct_hitbox_index = 0; obstruct_hitbox_index < 4; obstruct_hitbox_index++) {
				Rectangle* obstruct_hitbox = obstruct_tetramino->return_rectangles().at(obstruct_hitbox_index); //sub-square of the potential collider
				//in case of collision it returns true, so that it is not allowed to move.
				if (falling_hitbox->IntersectsWith(*obstruct_hitbox))
					return false;
			}
		}
	}
	return true;
}
bool Grid::Is_Able_To_Move_Right() {
	//detects if a falling tetramino collides with another on the right side to stop its movement
	//iterating each of the sub-squares of the falling tetramino and verifying intersection with the sub-squares of the other tetraminos
	//the function is invoked indirectly by keyboard input
	Shape* falling_tetramino = tetraminos.at(tetraminos.size() - 1);
	for (int falling_hitbox_index = 0; falling_hitbox_index < 4; falling_hitbox_index++) {
		//iterates each of the sub-squares of the falling tetramino to see if it intersects
		Rectangle* falling_hitbox = falling_tetramino->return_rectangles().at(falling_hitbox_index);
		//assumes that the tetramino is one position further to the right
		falling_hitbox->X += 30;
		//iterates each tetramino that can collide with the falling one
		for (int obstruct_tetramino_index = 0; obstruct_tetramino_index < tetraminos.size() - 1; obstruct_tetramino_index++) {
			Shape* obstruct_tetramino = tetraminos.at(obstruct_tetramino_index); //potential collider
			//iterates each of the sub-squares of the potential collider to see if it intersects
			for (int obstruct_hitbox_index = 0; obstruct_hitbox_index < 4; obstruct_hitbox_index++) {
				Rectangle* obstruct_hitbox = obstruct_tetramino->return_rectangles().at(obstruct_hitbox_index); //sub-square of the potential collider
				//in case of collision it returns true, so that it is not allowed to move.
				if (falling_hitbox->IntersectsWith(*obstruct_hitbox))
					return false;
			}
		}
	}
	return true;
}
void Grid::Translate_Tetramino(direction new_direction) {
	//in case the input is correct, and the conditions are correct, the tetramino is moved
	if (new_direction == direction::left && Is_Able_To_Move_Left())
		tetraminos.at(tetraminos.size() - 1)->Translate_Left();
	else if (new_direction == direction::right && Is_Able_To_Move_Right())
		tetraminos.at(tetraminos.size() - 1)->Translate_Right();
}
bool Grid::Time_Acceleration() {
	//returns the value of key_down_pressed to be used in the forms, thus counteracting the speed of the timer.
	return key_down_pressed;
}
void Grid::Press_Key_Down() {
	//this function is invoked by the keyboard input
	key_down_pressed = true; //when the value of key_down_pressed is true, the game will accelerate the speed until the falling tetramino is set.
}
bool Grid::Any_Row_Is_Full() {
	//iterates each row to detect if the row is full of sub-squares
	for (int row_index = 0; row_index < 600 / 30; row_index++) {
		int count = 0; //count how many sub squares there are, if there are 20 it means that the row is full.
		Rectangle* detector = new Rectangle(0, 30 * row_index, 600, 30); //rectangle the size of the row is created to detect collisions.
		//iterates all the tetraminoes to see which of their subsquares intersect(or lie within) the row
		for (int i = 0; i < tetraminos.size(); i++) {
			Shape* current_tetramino = tetraminos.at(i);
			for (int rectangle_index = 0; rectangle_index < 4; rectangle_index++) {
				Rectangle* current_retangle = current_tetramino->return_rectangles().at(rectangle_index);
				//if found, the counter increases
				if (current_retangle->IntersectsWith(*detector))
					count++;
			}
		}
		//if the counter is above or equal to 20 it means that the row is full.
		if (count >= 600 / 30)
			return true;
	}
	return false;
}
void Grid::Move_Last_Row_Down() {
	//iterates each tetramino and moves them down one position
	for (int i = 0; i < tetraminos.size() - 1; i++) {
		tetraminos.at(i)->new_y(tetraminos.at(i)->return_y() + 1);
	}
}
void Grid::Clean_Last_Row() {
	//when a row is full the other tiles are moved downward
	if (Any_Row_Is_Full()) {
		Move_Last_Row_Down();
		//100 more points are assigned to the score
		points += 100;
	}
}
bool Grid::Top_Row_Is_Occupied() {
	//this function detects if specifically the topmost row is occupied
	//if it is occupied it means that the player has lost, the game is over.
	Rectangle* detector = new Rectangle(0, 0, 600, 30); //rectangle the size of the row is created to detect collisions.

	//iterates all the tetraminoes to see which of their subsquares intersect(or lie within) the row
	for (int i = 0; i < tetraminos.size(); i++) {
		Shape* current_tetramino = tetraminos.at(i);
		for (int rectangle_index = 0; rectangle_index < 4; rectangle_index++) {
			Rectangle* current_retangle = current_tetramino->return_rectangles().at(rectangle_index);
			//in case of intersection returns true, this information is used by the forms to stop the timer.
			if (current_retangle->IntersectsWith(*detector))
				return true;
		}
	}
	return false;
}
void Grid::Draw_Visuals(Graphics^ g) {
	//draws a light blue background on the right where extra information will be located.
	SolidBrush^ b = gcnew SolidBrush(Color::LightSteelBlue);
	g->FillRectangle(b, 600, 0, 200, 600);
	//use the information from the following tetramino to draw it on the screen
	Shape* next_tetramino_clone = next_tetramino;
	int next_tetramino_x = next_tetramino->return_x();
	int next_tetramino_y = next_tetramino->return_y();
	next_tetramino_clone->new_x(22);
	next_tetramino_clone->new_y(4);
	next_tetramino_clone->Draw_Shape(g);
	//-----BUG FIXING PATCH-----
	next_tetramino_clone->new_x(next_tetramino_x);
	next_tetramino_clone->new_y(next_tetramino_y);
	//--------------------------
}
System::String^ Grid::Return_Points() {
	//returns a string with the player's score
	//-----Example:-----
	//"SCORE:
	//1200"
	//------------------
	System::String^ points_text = "SCORE:\n";
	points_text += points.ToString();
	return points_text;
}
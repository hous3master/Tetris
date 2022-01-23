#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using namespace System::Drawing;
class Shape
{
private:
	int x, y, rotation, color;
	vector<vector<int>> shape;
	bool set;
public:
	Shape(int new_x, int new_y);
	~Shape();

	void new_set(bool new_data);
	void new_x(int new_data);
	void new_y(int new_data);

	bool return_set();
	int return_x();
	int return_y();

	bool Is_Able_To_Move_Left();
	bool Is_Able_To_Move_Right();
	void Translate_Right();
	void Translate_Left();

	void Move(Graphics^ g);
	void Rotate();

	int Convert_To_X_Coords(int position, int grid_scale);
	int Convert_To_Y_Coords(int position, int grid_scale);

	void Draw_Shape(Graphics^ g);

	vector<Rectangle*> return_rectangles();
	vector<Rectangle*> return_future_rectangles();
};
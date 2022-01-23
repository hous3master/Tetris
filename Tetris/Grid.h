#pragma once
#include "Shape.h"
public enum direction {left, right};
class Grid
{
private:
	Shape* next_tetramino;
	vector<Shape*> tetraminos;
	bool key_down_pressed;
	int points;
public:
	Grid();
	~Grid();

	bool All_Tetraminos_Are_Set();
	void Insert_Tetramino();

	void Tetramino_Hit_Bottom();
	void Tetraminos_Intersect();
	void Set_Tetramino();

	bool Is_Able_To_Move_Left();
	bool Is_Able_To_Move_Right();
	void Rotate_Tetramino();
	void Translate_Tetramino(direction new_direction);

	bool Time_Acceleration();
	void Press_Key_Down();

	bool Any_Row_Is_Full();
	void Clean_Last_Row();
	void Move_Last_Row_Down();
	
	bool Top_Row_Is_Occupied();

	void Draw_Tetramino(Graphics^ g);
	void Draw_Visuals(Graphics^ g);
	System::String^ Return_Points();
};


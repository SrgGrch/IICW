#pragma once

struct Pointer { // указатель для игровой доски
	int x;
	int y;
	Pointer(int _x, int _y): x(_x), y(_y) {};
	Pointer() {};
};
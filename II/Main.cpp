#include "Board.h"
#include "GameSession.h"
#include <iostream>


int main(){
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	GameSession g;
	g.run();
	return 0;
}
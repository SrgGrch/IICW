#include "Board.h"
#include "GameSession.h"
#include <iostream>


int main(){
	setlocale(LC_ALL, "rus"); //
	SetConsoleOutputCP(1251); // Строки нужны для корректной работы с русским языком
	SetConsoleCP(1251);		  //
	GameSession g; // Создание игровой сессии
	g.run(); // запуск игровой сесии
	return 0;
}
#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Utils.h"

class Board {

private:
	char board[5][5];
	std::string fileName = "words.txt";
	std::string fileNameFive = "wordsFive.txt";
	
	const int LEFT = 0;
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;

	Pointer pointer = Pointer(2, 2);

	void printRules(int line);
	void prepareBord();
	std::string randWord();
public:
	Board();
	void setCharacter(char ch);
	void movePointer(int dir);
	//char getBoard();
	bool checkWord();
	void printBoard();


};
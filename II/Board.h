#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Utils.h"
#include "Word.h"

class Board {

private:
	char board[5][5];
	bool choseBoard[5][5];
	std::string fileName = "Dictionary/words.txt";
	std::string fileNameFive = "Dictionary/wordsFive.txt";
	std::string tmpWord;
	std::vector<Word> words;
	bool isHighlighting = false;
	
	const int LEFT = 0;
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;

	Pointer pointer = Pointer(2, 2);
	Pointer tmpPosition;

	bool checkPointer(int dir);
	void printRules(int line);
	void prepareBord();
	void clearChoseBoard();

	std::string randWord();
public:
	Board();
	bool getHighlighting();
	void setCharacter(char ch);
	void movePointer(int dir);
	void startHighlighting();
	void stopHighlighting();
	bool checkWord(int turn);
	void highlightWord(bool del, int dir);
	void printBoard();


};
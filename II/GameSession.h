#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"
#include <string>
#include <Windows.h>
class GameSession {
private:
	const int LEFT = 0;
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;
	Player player1;
	Player player2;
	Board board;
	int draw = 0;

	int currentPlayer = 1;
	
	void highlightWord();
	void insertCh();
	void printTurn();
	void getMoveDirection();
	void getHighlightDirection(int &tmpDir);
	void setPlayers();
	void printBoard();
	void printScoreBoard();
public:
	GameSession() {
		setPlayers();
	}
	void run();
	void setPlayerFirst(std::string name);
	void setPlayerSecond(std::string name);
};
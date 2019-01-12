#include "GameSession.h"

void GameSession::printBoard()
{
	system("cls");
	printTurn();
	board.printBoard();
	printScoreBoard();
}

void GameSession::printScoreBoard()
{
	std::cout << std::endl << "	" << player1.name << " " << player1.getScore() << "		" << player2.name << " " << player2.getScore() << std::endl;
}

void GameSession::printTurn()
{
	std::cout << "					’од игрока ";
	if (currentPlayer == 1) std::cout << player1.getName() << std::endl << std::endl;
	else std::cout << player2.getName() << std::endl << std::endl;
}

void GameSession::getMoveDirection()
{
	bool isActive = GetConsoleWindow() == GetForegroundWindow();
	if (GetAsyncKeyState(VK_LEFT) && isActive)
	{
		system("cls");
		board.movePointer(LEFT);
		printBoard();
	} else if (GetAsyncKeyState(VK_RIGHT) && isActive)
	{
		system("cls");
		board.movePointer(RIGHT);
		printBoard();
	} else if (GetAsyncKeyState(VK_DOWN) && isActive)
	{
		system("cls");
		board.movePointer(DOWN);
		printBoard();
	} else if (GetAsyncKeyState(VK_UP) && isActive)
	{
		system("cls");
		board.movePointer(UP);
		printBoard();
	}
}

void GameSession::getHighlightDirection(int &tmpDir)
{
	bool isActive = GetConsoleWindow() == GetForegroundWindow();
	if (GetAsyncKeyState(VK_LEFT) && isActive)
	{
		system("cls");
		if (RIGHT == tmpDir) board.highlightWord(true, LEFT);
		else {
			board.highlightWord(false, LEFT);
			tmpDir = LEFT;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_RIGHT) && isActive)
	{
		system("cls");
		if (LEFT == tmpDir) board.highlightWord(true, RIGHT);
		else {
			board.highlightWord(false, RIGHT);
			tmpDir = RIGHT;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_DOWN) && isActive)
	{
		system("cls");
		if (UP == tmpDir) board.highlightWord(true, DOWN);
		else {
			board.highlightWord(false, DOWN);
			tmpDir = DOWN;
		}
		printBoard();

	} else if (GetAsyncKeyState(VK_UP) && isActive)
	{
		system("cls");
		if (DOWN == tmpDir) board.highlightWord(true, UP);
		else {
			board.highlightWord(false, UP);
			tmpDir = UP;
		}
		printBoard();
	}
}

void GameSession::setPlayers()
{
	system("cls");
	std::cout << "¬ведите им€ 1го игрока: ";
	std::cin >> player1.name;
	std::cout << "¬ведите им€ 2го игрока: ";
	std::cin >> player2.name;
	system("cls");
	printBoard();
}

void GameSession::run()
{
	bool isActive = false;
	while (true) {
		isActive = GetConsoleWindow() == GetForegroundWindow();
		getMoveDirection();
		if (GetAsyncKeyState(VK_END) && isActive)
		{
			insertCh();
		} else if (GetAsyncKeyState(VK_MENU) && isActive)
		{
			highlightWord();

		} else if (GetAsyncKeyState(VK_DELETE) && isActive)
		{
			break;
		}

		Sleep(200);
	}
}

void GameSession::highlightWord()
{
	bool isActive = false;
	int tmpDir = -1;
	int dir = -1;
	bool isHighlighting = true;
	board.startHighlighting();
	while (isHighlighting) {
		isActive = GetConsoleWindow() == GetForegroundWindow();
		getHighlightDirection(tmpDir);
		if (GetAsyncKeyState(VK_CONTROL) && isActive) {
			if (board.checkWord(currentPlayer)) {
				if (currentPlayer == 1) { 
					player1.addScore(); 
					currentPlayer = 2;
				}
				else {
					player2.addScore();
					currentPlayer = 1;
				}
				isHighlighting = false;
			}
			isHighlighting = board.getHighlighting();
		}
		Sleep(200);
	}
	board.stopHighlighting();
	printBoard();

}

void GameSession::insertCh() {
	char tmp;
	std::cin >> tmp;
	board.setCharacter(tmp);
	system("cls");
	printTurn();
	board.printBoard();
	printScoreBoard();
}

void GameSession::setPlayerFirst(std::string name)
{
	player1.setName(name);
}

void GameSession::setPlayerSecond(std::string name)
{
	player2.setName(name);
}

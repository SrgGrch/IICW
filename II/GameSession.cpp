#include "GameSession.h"

void GameSession::printBoard()
{
	system("cls");
	printTurn();
	printScoreBoard();
	board.printBoard();
}

void GameSession::printScoreBoard()
{
	std::cout << std::endl << "	" << player1.name << "		" << player2.name;
}

void GameSession::printTurn()
{
	std::cout << "					’од игрока ";
	if (currentPlayer == 1) std::cout << player1.getName() << std::endl << std::endl;
	else std::cout << player2.getName() << std::endl << std::endl;
}

void GameSession::getMoveDirection()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		system("cls");
		printTurn();
		board.movePointer(LEFT);
		printScoreBoard();
	} else if (GetAsyncKeyState(VK_RIGHT))
	{
		system("cls");
		printTurn();
		board.movePointer(RIGHT);
		printScoreBoard();
	} else if (GetAsyncKeyState(VK_DOWN))
	{
		system("cls");
		printTurn();
		board.movePointer(DOWN);
		printScoreBoard();
	} else if (GetAsyncKeyState(VK_UP))
	{
		system("cls");
		printTurn();
		board.movePointer(UP);
		printScoreBoard();
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
	while (true) {
		getMoveDirection();
		if (GetAsyncKeyState(VK_DELETE))
		{
			break;
		}
		Sleep(200);
	}
}

void GameSession::setPlayerFirst(std::string name)
{
	player1.setName(name);
}

void GameSession::setPlayerSecond(std::string name)
{
	player2.setName(name);
}

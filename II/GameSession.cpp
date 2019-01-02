#include "GameSession.h"

void GameSession::printBoard()
{
	printScoreBoard();
	board.printBoard();
}

void GameSession::printScoreBoard()
{
	std::cout << player1.name << "		" << player2.name;
}

void GameSession::setPlayers()
{
	system("cls");
	std::cout << "������� ��� 1�� ������: ";
	std::cin >> player1.name;
	std::cout << "������� ��� 2�� ������: ";
	std::cin >> player2.name;
	system("cls");
	printBoard();
}

void GameSession::run()
{
	
	setPlayers();
	while (true) {
		if (GetAsyncKeyState(VK_LEFT))
		{
			board.movePointer(LEFT);
			printScoreBoard();
		} else if (GetAsyncKeyState(VK_RIGHT))
		{
			board.movePointer(RIGHT);
			printScoreBoard();
		} else if (GetAsyncKeyState(VK_DOWN))
		{
			board.movePointer(DOWN);
			printScoreBoard();
		} else if (GetAsyncKeyState(VK_UP))
		{
			board.movePointer(UP);
			printScoreBoard();
		} else if (GetAsyncKeyState(VK_DELETE))
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

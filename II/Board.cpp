#include "Board.h"

int maxFive = 1368;

void Board::printBoard()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == pointer.x && j == pointer.y) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 2));
			else SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::prepareBord()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			board[i][j] = '*';
	}
}

std::string Board::randWord()
{
	int pos = rand() % maxFive + 1;
	std::string tmp = "";
	std::ifstream in;
	char *tmpstr = new char[100];
	in.open(fileNameFive);
	for (int i = 0; i < pos - 1; i++) {
		in.getline(tmpstr, 100, '\n');
	}
	in.getline(tmpstr, 100, '\n');
	tmp.clear();
	tmp = tmpstr;
	in.close();

	delete tmpstr;
	return tmp;
}

Board::Board()
{
	srand(time(0));
	prepareBord();
	std::string word = randWord();
	for (int i = 0; i < 5; i++) {
		board[2][i] = word[i];
	}
	printBoard();
}

void Board::setCharacter(char ch)
{
	board[pointer.x][pointer.y] = ch;
	printBoard();
}

void Board::movePointer(int dir)
{
	if (dir == LEFT && pointer.y > 0) pointer.y--;
	else if (dir == RIGHT && pointer.y < 4) pointer.y++;
	else if (dir == DOWN && pointer.x < 4) pointer.x++;
	else if (dir == UP && pointer.x > 0) pointer.x--;
	printBoard();
}

//char Board::getBoard()
//{
//	return board;
//}

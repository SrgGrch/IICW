#include "Board.h"

int maxFive = 1368;
int maxWords = 34010;

bool Board::checkWord(int turn)
{
	std::string tmp = "";
	std::ifstream in;
	in.open(fileName);
	//if (tmpWord.find("*") == std::string::npos) return false;
	int i;
	for (i = 0; i < maxWords - 1; i++) {
		getline(in, tmp);
		if (!tmpWord.compare(tmp)) {
			for (auto w : words) {
				if (w.getWord() == tmpWord) return false;
			}
			std::cout << "OK";
			words.push_back(Word(tmp, turn));
			isHighlighting = false;
			tmpWord.clear();
			return true;
		}
		tmp.clear();
	}
	std::cout << i;
	tmp.clear();
	in.close();

	board[tmpPosition.x][tmpPosition.y] = '*';
	stopHighlighting();
	return false;
}

void Board::highlightWord(bool del, int dir)
{
	if (checkPointer(dir)) {
		//tmpWord.substr(0, tmpWord.size() - 1);
		if (tmpWord.size() > 0)  tmpWord.resize(tmpWord.size() - 1);
		choseBoard[pointer.x][pointer.y] = false;
		movePointer(dir);
	} else {
		movePointer(dir);
		tmpWord += board[pointer.x][pointer.y];
		choseBoard[pointer.x][pointer.y] = true;

	}
}

void Board::printBoard()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 5; i++) {
		std::cout << "	";
		for (int j = 0; j < 5; j++) {
			if (i == pointer.x && j == pointer.y) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 2));
			else SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));

			if (choseBoard[i][j]) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 5));
			else if (isHighlighting) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));

			std::cout << board[i][j];
			if (i == 4 || j == 4) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));
		}
		printRules(i);
		std::cout << std::endl;
	}
}

void Board::printRules(int line)
{
	if (line == 0) {
		std::cout << "		Передвигайте указатель с помощью стрелочек";
	} else if (line == 1) {
		std::cout << "		Для ввода буквы выберите нужную ячейку, а затем нажмите 'home'";
	}else if (line == 2) {
		std::cout << "		пропуск - '', выделение - 'alt', конец выделения - 'ctrl'";
	} else if (line == 3) {
		std::cout << "		Для выхода из игры нажмите 'del'";
	}
}

void Board::prepareBord()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = '*';
			choseBoard[i][j] = false;
		}
	}
}

void Board::clearChoseBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			choseBoard[i][j] = false;

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
	words.push_back(Word(tmp, 0));
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

bool Board::getHighlighting()
{
	return isHighlighting;
}

void Board::setCharacter(char ch)
{
	if (pointer.x != 2) {
		board[pointer.x][pointer.y] = ch;
		tmpPosition.x = pointer.x;
		tmpPosition.y = pointer.y;
	}
}

void Board::movePointer(int dir)
{
	if (dir == LEFT && pointer.y > 0) pointer.y--;
	else if (dir == RIGHT && pointer.y < 4) pointer.y++;
	else if (dir == DOWN && pointer.x < 4) pointer.x++;
	else if (dir == UP && pointer.x > 0) pointer.x--;
	//printBoard();
}
bool Board::checkPointer(int dir)
{
	if (dir == LEFT && pointer.y > 0) return choseBoard[pointer.x][pointer.y - 1];
	else if (dir == RIGHT && pointer.y < 4) return choseBoard[pointer.x][pointer.y + 1];
	else if (dir == DOWN && pointer.x < 4) return choseBoard[pointer.x + 1][pointer.y];
	else if (dir == UP && pointer.x > 0) return choseBoard[pointer.x - 1][pointer.y];

	// Добавить проверку следующего

	return true;
}

void Board::stopHighlighting()
{
	isHighlighting = false;
	tmpWord.clear();
	clearChoseBoard();
}

void Board::startHighlighting()
{
	choseBoard[pointer.x][pointer.y] = true;
	tmpWord += board[pointer.x][pointer.y];
	isHighlighting = true;
}

//char Board::getBoard()
//{
//	return board;
//}

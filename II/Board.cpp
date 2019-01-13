#include "Board.h"


bool Board::checkWord(int turn)
{
	std::string tmp = ""; // Временная строка
	std::ifstream in; // Поток ввода
	in.open(fileName); // Открываем словарь

	for (int i = 0; i < maxWords - 1; i++) { // Ищем слово в словаре
		getline(in, tmp); // Запись с потока ввода
		if (!tmpWord.compare(tmp)) {  //Если существует
			for (auto w : words) { // Проверяем было ли оно уже введено другим игроком
				if (w.getWord() == tmpWord) return false; // Если было, слово не прошло проверку
			}
			words.push_back(Word(tmp, turn)); // Если не было, записываем в вектор (Массив) с истрией слов
			isHighlighting = false; // Заканичваем выделение
			tmpWord.clear(); // Отчищаем вспомогательную строку
			return true; // Слово прошло проверку
		}
		tmp.clear(); 
	}
	// Если не не существует
	tmp.clear(); // Отчистка временной строки
	in.close(); // Закрытие словаря

	board[tmpPosition.x][tmpPosition.y] = '*'; // Сброс введенного символа
	stopHighlighting(); // Остановка выделения
	return false; // Слово не прошло проверку

}

void Board::highlightWord(bool del, int dir) // Выделение ячейки
{
	if (checkPointer(dir)) { // Проверка на отмену выделения
		if (tmpWord.size() > 0)  tmpWord.resize(tmpWord.size() - 1); // отменяем изменения в вспомогательной строке
		choseBoard[pointer.x][pointer.y] = false;
		movePointer(dir);
	} else { // Если не отменяем
		movePointer(dir); // Перемещение курсора
		tmpWord += board[pointer.x][pointer.y]; // Добавление буквы в вспомогательную строку
		choseBoard[pointer.x][pointer.y] = true; 

	}
}

void Board::printBoard() // Вывод доски
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Для выделения цветом символов
	for (int i = 0; i < 5; i++) {
		std::cout << "	";
		for (int j = 0; j < 5; j++) {
			if (i == pointer.x && j == pointer.y) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 2)); // Выделение указателя
			else SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));

			if (choseBoard[i][j]) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 5)); // Выделение при выделении слова
			else if (isHighlighting) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));

			std::cout << board[i][j];
			if (i == 4 || j == 4) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));
		}
		printRules(i); // Вывод правил
		std::cout << std::endl;
	}
}

void Board::printRules(int line)
{
	if (line == 0) {
		std::cout << "		Передвигайте указатель с помощью стрелочек";
	} else if (line == 1) {
		std::cout << "		Для ввода буквы выберите нужную ячейку, а затем нажмите 'end'";
	}else if (line == 2) {
		std::cout << "		пропуск - 'home', выделение - 'alt', конец выделения - 'ctrl'";
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
	in.open(fileNameFive);
	for (int i = 0; i < pos - 1; i++) {
		getline(in, tmp);
	}
	getline(in, tmp);
	in.close();
	words.push_back(Word(tmp, 0));
	return tmp;
}

Board::Board()
{
	srand(time(0)); // Для функции rand
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
	if (pointer.x != 2 && board[pointer.x][pointer.y] == '*') {
		board[pointer.x][pointer.y] = ch;
		tmpPosition.x = pointer.x;
		tmpPosition.y = pointer.y;
	}
}

void Board::movePointer(int dir)
{
	// Проверка на "Стенки"
	if (dir == LEFT && pointer.y > 0) pointer.y--;
	else if (dir == RIGHT && pointer.y < 4) pointer.y++;
	else if (dir == DOWN && pointer.x < 4) pointer.x++;
	else if (dir == UP && pointer.x > 0) pointer.x--;
	//printBoard();
}
bool Board::checkPointer(int dir)
{
	// Проверка на стенки и на "отмену"
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

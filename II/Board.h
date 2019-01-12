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
	char board[5][5]; // Массив символом доски
	bool choseBoard[5][5]; // Вспомогательный массив для выделения слова
	std::string fileName = "Dictionary/words.txt"; // Путь до словаря
	std::string fileNameFive = "Dictionary/wordsFive.txt"; // Путь до словаря с начальными словами
	std::string tmpWord; // Вспомогательная строка для выделяемого слова
	std::vector<Word> words; // Массив всех введенных слов
	bool isHighlighting = false; // Флаг, который говорит о том, идет ли сейчас выделение
	
	// Кол-во слов в словарях
	int maxFive = 1368;
	int maxWords = 34010;

	// Константы для направлавления перемещения курсора
	const int LEFT = 0;
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;

	Pointer pointer = Pointer(2, 2); // Курсор
	Pointer tmpPosition; // Позиция введеного символа

	bool checkPointer(int dir); // Метод для снятия выделения
	void printRules(int line); // Метод выводящий правила игры
	void prepareBord(); // Подготовка доски (заполнение '*')
	void clearChoseBoard(); // Отчистка массива для выделения

	std::string randWord(); // Метод для определения начального слова 
public:
	Board(); // Констркутор по умолчанию
	bool getHighlighting(); // Метод, который сообщает о том, выделяется ли слово
	void setCharacter(char ch); // Метод для ввода буквы 
	void movePointer(int dir); // Метод для передвижения курсора
	void startHighlighting(); // Метод начинаюший выделение
	void stopHighlighting(); // метод заканчивающий вделение
	bool checkWord(int turn); // Метод для проверки слова с помощью словаря
	void highlightWord(bool del, int dir); // Метод выделяющий ячейку таблицы
	void printBoard(); // Вывод доски


};
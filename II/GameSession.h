#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"
#include <string>
#include <Windows.h>
class GameSession {
private:
	// Константы для направлавления перемещения курсора
	const int LEFT = 0; 
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;
	// Модели игроков
	Player player1;
	Player player2;
	Board board; // Игровая доска
	int draw = 0; // Счетчик ничьи
	bool isInserted = false; // Флаг показывающий была ли введена буква

	int busyCells = 5; // Кол-во занятых ячеек

	int currentPlayer = 1; // Переменная показыающая чей сейчас ход

	void highlightWord(); // Функция для выделения слова
	void insertCh();  // Ввод буквы
	void printTurn(); // Вывод текущей очереди на экран
	void getMoveDirection(); // Получение направления движения курсора
	void getHighlightDirection(int &tmpDir); // Получение направления движения курсора при выделении
	void setPlayers(); // Ввод имен игроков
	void printBoard(); // Вывод игровой доски
	void endGame(); // Метод заканивающий игру и подводящий итоги
	void skipTurn(); // Пропуск хода
	void printScoreBoard(); // Вывод информации о счете
public:
	GameSession() {
		setPlayers(); // Констркутор по умолчанию запрашивает ввод имен игроков
	}
	void run(); // Функция запуска игры
	void setPlayerFirst(std::string name); 
	void setPlayerSecond(std::string name);
};
#pragma once
#include <iostream>

class Word { // Модель (класс) для хранения информации о слове вместе с ID игрока, который его ввел
public:
	Word(std::string _word, int _playerId) : word(_word), playerId(_playerId) {}
	std::string getWord() {
		return word;
	}
private:
	std::string word;
	int playerId;
	
};
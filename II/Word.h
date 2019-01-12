#pragma once
#include <iostream>

class Word {
public:
	Word(std::string _word, int _playerId) : word(_word), playerId(_playerId) {}
	std::string getWord() {
		return word;
	}
private:
	std::string word;
	int playerId;
	
};
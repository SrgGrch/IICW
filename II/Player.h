#pragma once
#include <iostream>
#include <string>
class Player {

private:
	int id;
	int score = 0;
	int color;
public:
	Player(int _id, std::string _name, int _score, int _color): id(_id), name(_name), score(_score), color(_color) {};
	Player() {};
	std::string name = "";
	int getId();
	int getScore();
	void addScore();
	std::string getName();
	int getColor();
	void setName(std::string _name);

};
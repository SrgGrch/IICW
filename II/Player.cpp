#include "Player.h"

int Player::getId()
{
	return id;
}

int Player::getScore()
{
	return score;
}

std::string Player::getName()
{
	return name;
}

int Player::getColor()
{
	return color;
}

void Player::setName(std::string _name)
{
	name = _name;
}

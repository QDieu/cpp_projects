#include "../stdafx.h"
#include "player.h"

player::player()
{ 
}

player::player(std::string character)
{
	if (character == "1") {
		cout << "You picked Knight" << endl;
		character_ = "Knight";
		hero = new knight();
	}
	else if (character == "2") {
		cout << "You picked Mage" << endl;
		character_ = "Mage";
		hero = new mage();
	}
	else if (character == "3") {
		cout << "You picked Goblin" << endl;
		character_ = "Goblin";
		hero = new goblin();
	}
}

std::string player::getCharacter()
{
	return character_;
}

int player::getPosition() const
{
	return currentPosition_;
}

void player::setPosition(int position)
{
	currentPosition_ = position;
}

int player::getHp() const
{
	return hero->getHp();
}

int player::getMp() const
{
	return hero->getMp();
}

int player::getArmor() const
{
	return hero->getArmor();
}

int player::getRange() const
{
	return hero->getRange();
}

int player::getAttack() const
{
	return hero->getAttack();
}

int player::takeDamage(int damage)
{
	return hero->takeDamage(damage);
}

int player::skill()
{
	return hero->skill();
}

void player::getStats() const
{
	hero->getStats();
	cout << "Position = " << getPosition() << endl;
}

void player::setDirection(int value)
{
	currentDirection_ = value;
	currentPosition_ = value;
}

int player::getDirection()
{
	return currentDirection_;
}

player::~player()
{
	delete hero;
}
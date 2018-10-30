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
	}
	else if (character == "2") {
		cout << "You picked Mage" << endl;
		character_ = "Mage";
	}
	else if (character == "3") {
		cout << "You picked Goblin" << endl;
		character_ = "Goblin";
	}
}

void player::getStats()
{
	if (character_ == "Knight")
		knight.getStats();
	else if (character_ == "Mage")
		mage.getStats();
	else if (character_ == "Goblin")
		goblin.getStats();
	cout << "Position = " << getPosition() << endl;
}

int player::getAttack()
{
	if (character_ == "Knight")
		return knight.getAttack();
	else if (character_ == "Mage")
		return mage.getAttack();
	else if (character_ == "Goblin")
		return goblin.getAttack();
}

int player::getHp()
{
	if (character_ == "Knight")
		return knight.getHp();
	else if (character_ == "Mage")
		return mage.getHp();
	else if (character_ == "Goblin")
		return goblin.getHp();
}

int player::getRange()
{
	if (character_ == "Knight")
		return knight.getRange();
	else if (character_ == "Mage")
		return mage.getRange();
	else if (character_ == "Goblin") 
		return goblin.getRange();
}

std::string player::getCharacter()
{
	return character_;
}

bool player::skill()
{
	if (character_ == "Knight")
	{
		knight.eatArmor();
		return 0;
	}
	else if (character_ == "Mage")
	{
		mage.oneOfEight();
		return 0;
	}
	else if (character_ == "Goblin")
		return goblin.bomb();
}

int player::takeDamage(int damage)
{
	if (character_ == "Knight")
		return knight.takeDamage(damage);
	else if (character_ == "Mage")
		return mage.takeDamage(damage);
	else if (character_ == "Goblin")
		return goblin.takeDamage(damage);
}

int player::getPosition()
{
	return currentPosition_;
}

void player::setPosition(int position)
{
	currentPosition_ = position;
}
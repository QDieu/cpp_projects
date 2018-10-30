#include "../stdafx.h"
#include "knight.h"

knight::knight()
{
	hp_ = 35;
	range_ = 1;
	armor_ = 15;
	attack_ = 5;
}

void knight::getStats()
{
	cout << "hp = " << getHp() << endl;
	cout << "armor = " << getArmor() << endl;
	cout << "attack = " << getAttack() << endl;
}

int knight::getHp()
{
	return hp_;
}

int knight::getArmor()
{
	return armor_;
}

int knight::getAttack()
{
	return attack_;
}

int knight::getRange()
{
	return range_;
}

int knight::takeDamage(int damage)
{
	if (getArmor() > 0) 
	{
		if (getArmor() > damage)
		{
			armor_ -= damage;
		}
		else
		{
			damage -= armor_;
			hp_ -= damage;
		}		
	}
	else hp_ -= damage;
	return damage;
}

void knight::eatArmor()
{
	int eatAtOnce = 4;
	if (getArmor() > eatAtOnce)
	{
		attack_ += eatAtOnce;
		armor_ -= eatAtOnce;
	}
	else
	{
		eatAtOnce = getArmor() - 1;
		attack_ += eatAtOnce;
		armor_ -= eatAtOnce;
	}
	cout << "You eat " << eatAtOnce << "armor" << endl;
}
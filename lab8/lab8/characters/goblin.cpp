#include "../stdafx.h"
#include "goblin.h"

bool goblin::DodgeDice()
{
	srand(time(NULL));
	int DodgeChance = 50 * (1 + ((maxHp_ - hp_) / maxHp_));
	return (DodgeChance > (rand() % 100));
}

bool goblin::HitUDice()
{
	srand(time(NULL));
	int HitUsl = 50 * (1 - ((maxHp_ - hp_) / maxHp_));
	return (HitUsl > (rand() % 100));
}

goblin::goblin()
{
	hp_= 40;
	maxHp_ = hp_;
	attack_ = 10;
	range_ = 1;
	bombStatus_ = 0;
}

void goblin::getStats()
{
	cout << "HP = " << getHp() << endl;
	cout << "attack = " << getAttack() << endl;
}

int goblin::getHp()
{
	return hp_;
}

int goblin::getAttack()
{
	return attack_;
}

int goblin::getRange()
{
	return range_;
}

int goblin::takeDamage(int damage)
{
	if (DodgeDice())
	{
		cout << "MISS" << endl;
		return 0;
	}
	else if (HitUDice())
	{
		hp_ -= attack_ * 2;
		return attack_ * 2;
	}
	else
	{
		hp_ -= damage;
		return damage;
	}
}

int goblin::bomb()
{
	if (bombStatus_ == 0)
	{
		cout << "Bomb created" << endl;
		bombStatus_++;
		return 0;
	}
	else
	{
		cout << "Bomb ready" << endl;
		bombStatus_--;
		return 1;
	}
	return 0;
}
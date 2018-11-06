#include "../stdafx.h"
#include "goblin.h"

bool goblin::DodgeDice()
{
	srand(time(NULL));
	int DodgeChance = 50 * (1 + ((maxHp_ - getHp()) / maxHp_));
	return (DodgeChance > (rand() % 100));
}

bool goblin::HitUDice()
{
	srand(time(NULL));
	int HitUsl = 50 * (1 - ((maxHp_ - getHp()) / maxHp_));
	return (HitUsl > (rand() % 100));
}

goblin::goblin():Hero(40,0,0,1,10)
{
	maxHp_ = getHp();
	bombStatus_ = 0;
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
		decHp(getAttack() * 2);
		return getAttack()*2;
	}
	else
	{
		decHp(damage);
		return damage;
	}
}

int goblin::skill()
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
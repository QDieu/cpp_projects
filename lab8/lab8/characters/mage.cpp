#include "../stdafx.h"
#include "mage.h"

bool MagicShield()
{
	srand(time(NULL));
	int shieldChance = 30;
	if (rand() % 100 < shieldChance) return 1;
	return 0;
}

mage::mage()
{
	hp_ = 25;
	attack_ = 6;
	range_ = 2;
	armor_ = 0;
	mp_ = 30;
}

void mage::getStats()
{
	cout << "hp = " << getHp() << endl;
	cout << "mp = " << getMp() << endl;
	cout << "attack = " << getAttack() << endl;
	if (getArmor() > 0) cout << "armor = " << getArmor() << endl;
}

int mage::getHp()
{
	return hp_;
}

int mage::getArmor()
{
	return armor_;
}

int mage::getMp()
{
	return mp_;
}

int mage::getAttack()
{
	return attack_;
}

int mage::getRange()
{
	return range_;
}

int mage::takeDamage(int damage)
{
	if (getMp())
	{
		if (MagicShield()) {
			mp_ -= damage * 2;
			if (getMp() < 0) mp_ = 0;
			cout << "Magic shiled protected Mage" << endl;
			return 0;
		}
	}
	hp_ -= damage;
	return damage;
}

void mage::oneOfEight()
{
	if (getMp()) 
	{
		srand(time(NULL));
		mp_ = 0;
		switch(rand() % 4)
		{
		case 0: 
		{
			mp_ *= 2;
			cout << "Mana doubled" << endl;
			break;
		}
		case 1:
		{
			hp_ *= 2;
			cout << "HP doubled" << endl;
			break;
		}
		case 2:
		{
			hp_ = 0;
			cout << "HP dropped to zero" << endl;
			break;
		}
		case 3:
		{
			armor_ = rand() % 15 + 1;
			cout << "Armor up " << endl;
			break;
		}
		}
	}
	else cout << "You don't have MP" << endl;
}
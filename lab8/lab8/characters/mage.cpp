#include "../stdafx.h"
#include "mage.h"

bool MagicShield()
{
	srand(time(NULL));
	int shieldChance = 30;
	if (rand() % 100 < shieldChance) return 1;
	return 0;
}

mage::mage(): Hero(35,0,60,2,6)
{
}

int mage::takeDamage(int damage)
{
	if (getMp())
	{
		if (MagicShield()) {
			decMp(damage * 2);
			if (getMp() < 0) decMp(getMp());
			cout << "Magic shiled protected Mage" << endl;
			return 0;
		}
	}
	decHp(damage);
	return damage;
}

int mage::skill()
{
	if (getMp()) 
	{
		srand(time(NULL));
		decMp(getMp());
		switch(rand() % 4)
		{
		case 0: 
		{
			decMp(-getMp());
			cout << "Mana doubled" << endl;
			break;
		}
		case 1:
		{
			decHp(-getHp());
			cout << "HP doubled" << endl;
			break;
		}
		case 2:
		{
			decHp(getHp());
			cout << "HP dropped to zero" << endl;
			break;
		}
		case 3:
		{
			decArmor(rand() % 15 - 15);
			cout << "Armor up " << endl;
			break;
		}
		}
	}
	else cout << "You don't have MP" << endl;
	return 0;
}
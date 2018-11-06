#include "../stdafx.h"
#include "knight.h"

knight::knight(): Hero(35,15,0,1,5)
{
}

int knight::getAttack() const
{
	if (getArmor() > 0) return Hero::getAttack();
	else return Hero::getAttack() * 2;
}

int knight::skill()
{
	if (getArmor() > 0) {
		int eatAtOnce = 4;
		if (getArmor() > eatAtOnce)
		{
			incAttack(eatAtOnce);
			decArmor(eatAtOnce);
		}
		else
		{
			eatAtOnce = getArmor() - 1;
			incAttack(eatAtOnce);
			decArmor(eatAtOnce);
		}
		cout << "You eat " << eatAtOnce << "armor" << endl;
	}
	else cout << "Nothing to eat" << endl;
	return 0;
}
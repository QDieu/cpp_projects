#include "../stdafx.h"
#include "Hero.h"

Hero::Hero(int hp, int armor, int mp, int range, int attack)
{
	this->hp_ = hp;
	this->armor_ = armor;
	this->mp_ = mp;
	this->range_ = range;
	this->attack_ = attack;
}

Hero::Hero(){}

Hero::~Hero() {}

int Hero::takeDamage(int damage)
{
	if (getArmor() > 0) {
		if (getArmor() >= damage) {
			decArmor(damage);
			damage = 0;
		}
		else {
			damage -= getArmor();
			armor_ = 0;
			hp_ -= damage;
		}
	}
	else hp_ -= damage;
	return damage;
}

int Hero::getHp() const
{
	return hp_;
}

int Hero::getArmor() const
{
	return armor_;
}

int Hero::getMp() const
{
	return mp_;
}

int Hero::getRange() const
{
	return range_;
}

int Hero::getAttack() const
{
	return attack_;
}

void Hero::getStats() const
{
	cout << "hp = " << getHp() << endl;
	cout << "mp = " << getMp() << endl;
	cout << "armor = " << getArmor() << endl;
	cout << "attack = " << getAttack() << endl;
}

void Hero::decHp(int value)
{
	hp_ -= value;
}

void Hero::decArmor(int value)
{
	armor_ -= value;
	if (armor_ < 0) armor_ = 0;
}

void Hero::decMp(int value)
{
	mp_ -= value;
}

void Hero::incAttack(int value)
{
	attack_ += value;
}
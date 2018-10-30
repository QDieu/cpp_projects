#pragma once
class mage
{
public:
	mage();
	void getStats();
	int getHp();
	int getArmor();
	int getMp();
	int getAttack();
	int getRange();
	int takeDamage(int damage);
	void oneOfEight();

private:
	int hp_, mp_, armor_, attack_, range_;
};


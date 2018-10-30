#pragma once
class knight {
public:
	knight();
	void getStats();
	int getHp();
	int getArmor();
	int getAttack();
	int getRange();
	int takeDamage(int damage);
	void eatArmor();
private:
	int hp_, armor_, attack_, range_;
};


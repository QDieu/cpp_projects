#pragma once
class goblin
{
public:
	goblin();
	void getStats();
	int getHp();
	int getAttack();
	int getRange();
	int takeDamage(int damage);
	int bomb();
	bool DodgeDice();
	bool HitUDice();
private:
	int hp_, attack_, range_, bombStatus_, maxHp_;
};


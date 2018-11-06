#pragma once
class goblin: public Hero
{
public:
	goblin();
	int takeDamage(int damage) override;
	int skill() override;
private:
	bool DodgeDice();
	bool HitUDice();
	int bombStatus_, maxHp_;
};


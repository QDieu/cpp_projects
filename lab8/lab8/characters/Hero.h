#pragma once

class Hero {
public:
	Hero(int hp, int armor, int mp, int range, int attack);
	Hero();
	virtual ~Hero();
	virtual int skill() = 0;
	virtual int takeDamage(int damage);

	int getHp() const;
	int getArmor() const;
	int getMp() const;
	int getRange() const;
	virtual int getAttack() const;
	void getStats() const;

protected:
	void decHp(int value);
	void decArmor(int value);
	void decMp(int value);
	void incAttack(int value);
private:
	int hp_, armor_, mp_, range_, attack_;

};
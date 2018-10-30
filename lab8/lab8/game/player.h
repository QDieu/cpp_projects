#pragma once
class player
{
public:
	player(std::string character);
	player();
	void getStats();
	int getAttack();
	int getHp();
	int getRange();
	std::string getCharacter();
	bool skill();
	int takeDamage(int damage);
	int getPosition();
	void setPosition(int position);
private:
	goblin goblin;
	knight knight;
	mage mage;
	std::string character_;
	int currentPosition_;
};


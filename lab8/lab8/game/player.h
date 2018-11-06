#pragma once
class player
{
public:
	player(std::string character);
	player();
	~player();
	std::string getCharacter();
	int getPosition() const;
	void setPosition(int position);
	int getHp() const;
	int getMp() const;
	int getArmor() const;
	int getRange() const;
	int getAttack() const;
	int takeDamage(int damage);
	int skill();
	void getStats() const;
	void setDirection(int value);
	int getDirection();
private:
	Hero * hero;
	std::string character_;
	int currentPosition_, currentDirection_;
};


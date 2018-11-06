#pragma once
class mage : public Hero
{
public:
	mage();
	int takeDamage(int damage) override;
	int skill() override;
};


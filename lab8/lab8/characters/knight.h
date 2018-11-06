#pragma once
class knight : public Hero
{
public:
	knight();
	int getAttack() const override;
	int skill() override;
};


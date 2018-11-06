#include "../stdafx.h"
#include "game.h"


game::game(std::string first,std::string second)
{
	players[0] = player(first);
	players[1] = player(second);
	players[0].setDirection(border_::left);
	players[1].setDirection(border_::right);
}

void game::moveForward()
{
	switch (players[currentPlayer].getDirection()) {
	case border_::left: {
		if (players[currentPlayer].getPosition() + 1 != players[getSwitchPlayer()].getPosition())
			players[currentPlayer].setPosition(players[currentPlayer].getPosition() + 1);
		else
			cout << "Player " << currentPlayer << " don't move forward" << endl;
		break;
	}
	case border_::right: {
		if(players[currentPlayer].getPosition() - 1 != players[getSwitchPlayer()].getPosition())
			players[currentPlayer].setPosition(players[currentPlayer].getPosition() - 1);
		else
			cout << "Player " << currentPlayer << " don't move forward" << endl;
		break;
	}
	}
}

void game::moveBackward()
{
	switch (players[currentPlayer].getDirection()) {
	case border_::left: {
		if (players[currentPlayer].getPosition() - 1 >= border_::left)
			players[currentPlayer].setPosition(players[currentPlayer].getPosition() - 1);
		else
			cout << "Player " << currentPlayer << " don't move backward" << endl;
		break;
	}
	case border_::right: {
		if (players[currentPlayer].getPosition() + 1 <= border_::right)
			players[currentPlayer].setPosition(players[currentPlayer].getPosition() + 1);
		else
			cout << "Player " << currentPlayer << " don't move backward" << endl;
		break;
	}
	}
}

int game::getDistance()
{
	return abs(players[0].getPosition()-players[1].getPosition());
}

void game::attack()
{
	int distance = getDistance();
	if (distance <= players[currentPlayer].getRange())
		cout << "Player " << getSwitchPlayer() << " took " << players[getSwitchPlayer()].takeDamage(players[currentPlayer].getAttack()) << "damage. " << players[getSwitchPlayer()].getHp() <<"left" << endl;
	else cout << "You're not close enough to attack" << endl;
}


void game::skill()
{
	if (players[currentPlayer].skill())
	{
		cout << "BOOOOM!!!" << endl;
		cout << "Bomp explosion "<< currentPlayer <<" took " << players[currentPlayer].takeDamage(players[currentPlayer].getHp() - 1) << " damage. " << players[currentPlayer].getHp() << "left" << endl;
		cout << "Bomp explosion "<< getSwitchPlayer() << " took " << players[getSwitchPlayer()].takeDamage(players[getSwitchPlayer()].getHp() - 1) << " damage. " << players[getSwitchPlayer()].getHp()<< "left" << endl;
	}
}

bool game::isDead(){
	if (players[currentPlayer].getHp() <= 0) return true;
	return false;
}

void game::getStats()
{
	players[currentPlayer].getStats();
}

void game::switchPlayer()
{
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;
}

int game::getSwitchPlayer()
{
	if (currentPlayer == 0) return 1;
	return 0;
}

void game::start_game()
{
	int currentChoice;
	while(1)
	{
		cout << "\n\nPlayer " << currentPlayer+1 << " choose your next move" << endl;
		cout << "Type 1 for attack \nType 2 to use skill of your character \nType 3 for move forward\n Type 4 for move backward \nType 5 check your status" << endl << endl;
		cin >> currentChoice;
		cout << endl;
		switch(currentChoice)
		{
		case 1:
		{
			attack();
			break;
		}
		case 2:
		{
			skill();
			break;
		}
		case 3:
		{
			moveForward();
			break;
		}
		case 4:
		{
			moveBackward();
			break;
		}
		case 5:
		{
			getStats();
			break;
		}
		}
		if (isDead())
		{
			cout << endl << "Player "<< getSwitchPlayer() <<" won! " << endl;
			break;
		}
		switchPlayer();
	}
}

game::~game()
{
	delete[] players;
}
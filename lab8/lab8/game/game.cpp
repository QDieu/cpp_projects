#include "../stdafx.h"
#include "game.h"


game::game(string first, string second)
{
	Player1 = player(first);
	Player2 = player(second);
	Player1.setPosition(1);
	Player2.setPosition(7);
}

void game::moveForward(int who)
{
	switch (who)
	{
	case 1:
	{
		if (Player1.getPosition() + 1 <= rightBorder && Player1.getPosition() + 1 != Player2.getPosition())
		{
			Player1.setPosition(Player1.getPosition() + 1);
			cout << "Your character moved forward" << endl;
		}
		else cout << "Your character can't move forward" << endl;
		break;
	}
	case 2:
	{
		if (Player2.getPosition() - 1 >= leftBorder && Player2.getPosition() - 1 != Player1.getPosition())
		{
			Player2.setPosition(Player2.getPosition() - 1);
			cout << "Your character moved forward" << endl;
		}
		else cout << "Your character can't move forward" << endl;
		break;
	}
	}
}

void game::moveBackward(int who)
{
	switch (who)
	{
	case 1:
	{
		if (Player1.getPosition() - 1 >= leftBorder && Player1.getPosition() - 1 != Player2.getPosition())
		{
			Player1.setPosition(Player1.getPosition() - 1);
			cout << "Your character moved backward" << endl;
		}
		else cout << "Your character can't move backward" << endl;
		break;
	}
	case 2:
	{
		if (Player2.getPosition() + 1 <= rightBorder && Player2.getPosition() + 1 != Player1.getPosition())
		{
			Player2.setPosition(Player2.getPosition() + 1);
			cout << "Your character moved backward" << endl;
		}
		else cout << "Your character can't move backward" << endl;
		break;
	}
	}
}

int game::getDistance()
{
	return abs(Player1.getPosition()-Player2.getPosition());
}

void game::move(int who)
{
	int choice;
	cout << "choose direction:\ntype 1 to move forward, type 2 to move backward" << endl;
	cin >> choice;
	switch(choice)
	{
	case 1:
	{
		moveForward(who);
		break;
	}
	case 2:
	{
		moveBackward(who);
		break;
	}
	}
}

void game::attack(int whoOfAttack)
{
	int distance = getDistance();
	if (whoOfAttack == 1 && distance <= Player1.getRange())
		cout << "Player 2 took " << Player2.takeDamage(Player1.getAttack()) << "damage. " << Player2.getHp() - Player2.takeDamage(Player1.getAttack()) <<"left" << endl;
	else if (whoOfAttack == 2 && distance <=Player2.getRange())
		cout << "Player 1 took " << Player1.takeDamage(Player2.getAttack()) << "damage. " << Player1.getHp() - Player1.takeDamage(Player2.getAttack()) << "left" << endl;
	else cout << "You're not close enough to attack" << endl;
}

void game::skill(int whoOfPlayer)
{
	int distance = getDistance();
	if (whoOfPlayer == 1) {
		if (Player1.skill())
		{
			cout << "BOOOOM!!!" << endl;
			cout << "Bomp explosion player1 took " << Player1.takeDamage(Player1.getHp() - 1) << " damage. " << Player1.getHp() << "left" << endl;
			cout << "Bomp explosion player2 took " << Player2.takeDamage(Player2.getHp() - 1) << " damage. " << Player2.getHp()<< "left" << endl;
		}
	}
	else if (whoOfPlayer == 2) {
		if (Player2.skill())
		{
			cout << "BOOOOM!!!" << endl;
			cout << "Bomp explosion player1 took " << Player1.takeDamage(Player1.getHp() - 1) <<" damage. "<< Player1.getHp()<< "left" << endl;
			cout << "Bomp explosion player2 took " << Player2.takeDamage(Player2.getHp() - 1) << " damage. " << Player2.getHp() << "left" << endl;
		}
	}
}

bool game::isDead(int who)
{
	if (who == 1 && Player1.getHp() <= 0) return true;
	else if (who == 2 && Player2.getHp() <= 0) return true;
	return false;
}

void game::getStats(int who)
{
	if (who == 1) Player1.getStats();
	else if (who == 2) Player2.getStats();
}

void game::switchPlayer()
{
	if (currentPlayer == 1) currentPlayer = 2;
	else currentPlayer = 1;
}

void game::start_game()
{
	int currentChoice;
	while(1)
	{
		cout << "Player " << currentPlayer << " choose your next move" << endl;
		cout << "Type 1 for attack \nType 2 to use skill of your character \nType 3 for move \nType 4 check your status" << endl << endl;
		cin >> currentChoice;
		cout << endl;
		switch(currentChoice)
		{
		case 1:
		{
			attack(currentPlayer);
			break;
		}
		case 2:
		{
			skill(currentPlayer);
			break;
		}
		case 3:
		{
			move(currentPlayer);
			break;
		}
		case 4:
		{
			getStats(currentPlayer);
			break;
		}
		}
		if (isDead(1))
		{
			cout << endl << "Player 2 won! " << endl;
			break;
		}
		else if (isDead(2))
		{
			cout << endl << "Player 1 won!" << endl;
			break;
		}
		switchPlayer();
	}
}
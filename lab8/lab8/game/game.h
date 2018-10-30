#pragma once
class game
{
public:
	game(std::string first, std::string second);
	void moveForward(int who);
	void moveBackward(int who);
	int getDistance();
	void move(int who);
	void attack(int whoOfAttack);
	void skill(int whoOfPlayer);
	bool isDead(int who);
	void getStats(int who);
	void switchPlayer();
	void start_game();
private:
	player Player1, Player2;
	const int leftBorder = 1, rightBorder = 7;
	int currentPlayer = 1;
};


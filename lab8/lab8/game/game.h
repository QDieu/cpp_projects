#pragma once
class game
{
public:
	game(std::string first, std::string second);
	void moveForward();
	void moveBackward();
	int getDistance();
	void attack();
	void skill();
	bool isDead();
	void getStats();
	void switchPlayer();
	void start_game();
	int getSwitchPlayer();
	~game();
private:
	player * players = new player[2];
	int currentPlayer = 0;
	enum border_ { left = 1, right = 7 };
};


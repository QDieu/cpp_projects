#include "stdafx.h"

enum Class {
	Knight = 1, Mage, Goblin
};

void init() 
{
	string first, second;
	cout << "Player 1 - choose your hero" << endl;
	cout << "type 1 for Knight class, type 2 for Mage class, type 3 for Goblin class" << endl;
	cin >> first;
	cout << "Player 2 - choose your hero" << endl;
	cout << "type 1 for Knight class, type 2 for Mage class, type 3 for Goblin class" << endl;
	cin >> second;
	game g(first, second);
	cout << "Game starting!!!" << endl << endl;
	g.start_game();
}


int main()
{
	init();
    return 0;
}


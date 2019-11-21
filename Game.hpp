/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Game class declaration. Member variables include the gameMap Map
**				object, flags for escape sequence, "dead", and "win" statuses,
**				and a variable to hold the player's last directional movement.
**				Game constructor prints opening lines and player objective. Move
**				and escape functions display description of current space (long
**				for “move,” short for “escape”), prompt user to enter 1-4 to
**				choose a direction validate user input, all “goDirection”
**				function from the map class and re-prompt the user if the move
**				is denied. escape checks if entered direction is opposite of
**				last entered direction. If so, sets “dead” flag.
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Map.hpp"
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Game
{
private:
	Map gameMap;
	//flags to indicate escape sequence and if the player is dead or has won
	bool escapeBool = false;
	bool dead = false;
	bool win = false;
	
	int prevChoice = -1;
	
public:
	Game();
	
	void move();
	void escape();
	
	//input validation function
	bool checkIntRange(int);
	
	bool getEscape();
	bool getDead();
	bool getWin();
};

#endif //GAME_HPP
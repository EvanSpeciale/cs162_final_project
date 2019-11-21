/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Game class implementation.
******************************************************************************/
#include "Space.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include <iostream>
#include <climits>
using std::cin;
using std::cout;
using std::endl;

//prints opening lines and player objective
Game::Game()
{
	cout << "July 13, 2122 - LV-426" << endl
		<< "----------------------" << endl
		<< "You have crash landed on a barren moon of Calpamos in the Zeta" << endl
		<< "Reticuli system. Fortunately your ship is largely fixable, but the" << endl
		<< "engine\'s primary power source was damaged beyond repair by the impact." << endl << endl
		<< "There\'s an abandoned helium-3 mining colony nearby which, based on the" << endl
		<< "thin polymer material used in its construction, couldn\'t be more than" << endl
		<< "10 years old. It seems unlikely that a mine of this size would be scuttled" << endl
		<< "so quickly, but there’s no sign that it’s in operation and preliminary" << endl
		<< "scans indicate no signs of life. As unsettling as that is, this place" << endl
		<< "holds your only chance of finding a replacement fuel cell and getting" << endl
		<< "off of this windswept rock. You figure your best bet is to head for" << endl
		<< "the mining platform at the far end of the facility and pray that" << endl
		<< "there\'s a big enough cell left in a transport vehicle or something." << endl
		<< "It\'s a long shot, but without a power supply you could be stuck here" << endl
		<< "for weeks waiting for someone to pick up your distress signal." << endl << endl
		<< "You get into your EVA suit and head for the open loading dock at the" << endl
		<< "south end of the facility." << endl << endl
		<< "OBJECTIVE: Explore the abandoned mining colony and look for a fuel" << endl
		<< "cell in the dig site on the north side. You don’t know what happened" << endl
		<< "here that caused the colonists to upand leave, so be carefuland make" << endl
		<< "sure you have an exit strategy if things go sideways. Try to make a" << endl
		<< "mental (or physical) map of the facility to make sure you don’t" << endl
		<< "get lost... or trapped." << endl << endl
		<< "You enter the complex through the large loading bay door and pull the" << endl
		<< "door shut behind you. You hear mechanisms whirring as the room is" << endl
		<< "sealed and pressurized." << endl << endl;
}

//displays description of current space, prompts user to move to an adjacent
//space. If move is valid, moves the player to that space. if not, reprompts
//user
void Game::move()
{
	//displays long space description
	gameMap.lookAround();

	int choice;
	bool valid;
	bool validMove;

	do
	{
		//prompts user for valid input (1-4)
		do
		{
			cin.clear();
			cout << "Which direction do you go?" << endl << endl
				<< "        North" << endl
				<< "          1" << endl
				<< "West 2         3 East" << endl
				<< "          4" << endl
				<< "        South" << endl << endl;
			cout << "Enter Selection [1-4]: ";
			cin >> choice;
			valid = this->checkIntRange(choice);	//checks if input is int between 1 and 4
			cout << endl;
		} while (!valid);

		//calls to relevant "goDirection" function in Map class. If move is invalid
		//according to that class, reprompts user to choose a direction
		switch (choice)
		{
		case 1:
		{
			validMove = gameMap.goNorth();
			break;
		}
		case 2:
		{
			validMove = gameMap.goWest();
			break;
		}
		case 3:
		{
			validMove = gameMap.goEast();
			break;
		}
		case 4:
		{
			validMove = gameMap.goSouth();
			break;
		}
		}
	} while (!validMove);
}

void Game::escape()
{
	//prints short space description
	gameMap.runThrough();

	int choice;
	bool valid;
	bool validMove;

	do
	{
		//prompts user for valid input (1-4)
		do
		{
			cin.clear();
			cout << "Which direction do you go?" << endl << endl
				<< "        North" << endl
				<< "          1" << endl
				<< "West 2         3 East" << endl
				<< "          4" << endl
				<< "        South" << endl << endl;
			cout << "Enter Selection [1-4]: ";
			cin >> choice;
			valid = this->checkIntRange(choice);	//checks if input is int between 1 and 4
			cout << endl;
		} while (!valid);

		//checks if user is trying to go the opposite direction of their last move
		//if so, sets "dead" flag
		if (choice == 1 && prevChoice == 4)
		{
			dead = true;
		}
		if (choice == 2 && prevChoice == 3)
		{
			dead = true;
		}
		if (choice == 3 && prevChoice == 2)
		{
			dead = true;
		}
		if (choice == 4 && prevChoice == 1)
		{
			dead = true;
		}
		
		//saves direction to compare against next move
		prevChoice = choice;
		
		//calls to relevant "goDirection" function in Map class. If move is invalid
		//according to that class, reprompts user to choose a direction
		switch (choice)
		{
		case 1:
		{
			validMove = gameMap.goNorth();
			break;
		}
		case 2:
		{
			validMove = gameMap.goWest();
			break;
		}
		case 3:
		{
			validMove = gameMap.goEast();
			break;
		}
		case 4:
		{
			validMove = gameMap.goSouth();
			break;
		}
		}
	} while (!validMove);
}

bool Game::checkIntRange(int input)
{
	if (input < 1 || input > 4)
	{
		cout << "Please enter a valid choice [1-4]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return false;
	}
	else
	{
		return true;
	}
}

bool Game::getEscape()
{
	escapeBool = gameMap.getEscape();
	return escapeBool;
}
bool Game::getDead()
{
	return dead;
}
bool Game::getWin()
{
	win = gameMap.getWin();
	return win;
}
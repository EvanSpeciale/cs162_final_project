/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Map class implementation.
******************************************************************************/
#include "Space.hpp"
#include "Map.hpp"
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//connects all Space objects to create a static linked list. initializes
//each space object's directional pointers, short descriptions, and long
//descriptions. Sets the status flags if a space is locked or has a key
Map::Map()
{
	//outside
	outside.setNorth(&room2);
	outside.setDescription(out);
	outside.setLocked4(true);
	outside.setShortDesc(shortOutside);
	//room 1
	room1.setLocked1(true);
	room1.setNorth(&room5);
	room1.setEast(&room2);
	room1.setDescription(rm1);
	room1.setShortDesc(short1);
	//room 2
	room2.setNorth(&room6);
	room2.setEast(&room3);
	room2.setWest(&room1);
	room2.setSouth(&outside);
	room2.setDescription(rm2);
	room2.setShortDesc(short2);
	//room 3
	room3.setEast(&room4);
	room3.setWest(&room2);
	room3.setDescription(rm3);
	room3.setShortDesc(short3);
	//room 4
	room4.setNorth(&room8);
	room4.setWest(&room3);
	room4.setDescription(rm4);
	room4.setShortDesc(short4);
	//room 5
	room5.setKeyRoom2(true);
	room5.setSouth(&room1);
	room5.setDescription(rm5);
	room5.setShortDesc(short5);
	//room 6
	room6.setEast(&room7);
	room6.setSouth(&room2);
	room6.setDescription(rm6);
	room6.setShortDesc(short6);
	//room 7
	room7.setNorth(&room12);
	room7.setEast(&room8);
	room7.setWest(&room6);
	room7.setDescription(rm7);
	room7.setShortDesc(short7);
	//room 8
	room8.setNorth(&room13);
	room8.setEast(&room9);
	room8.setWest(&room7);
	room8.setSouth(&room4);
	room8.setDescription(rm8);
	room8.setShortDesc(short8);
	//room 9
	room9.setKeyRoom1(true);
	room9.setWest(&room8);
	room9.setDescription(rm9);
	room9.setShortDesc(short9);
	//room 10
	room10.setKeyRoom3(true);
	room10.setEast(&room11);
	room10.setDescription(rm10);
	room10.setShortDesc(short10);
	//room 11
	room11.setNorth(&room14);
	room11.setWest(&room10);
	room11.setDescription(rm11);
	room11.setShortDesc(short11);
	//room 12
	room12.setLocked2(true);
	room12.setNorth(&room15);
	room12.setEast(&room13);
	room12.setSouth(&room7);
	room12.setDescription(rm12);
	room12.setShortDesc(short12);
	//room 13
	room13.setNorth(&room16);
	room13.setWest(&room12);
	room13.setSouth(&room8);
	room13.setDescription(rm13);
	room13.setShortDesc(short13);
	//room 14
	room14.setNorth(&room17);
	room14.setEast(&room15);
	room14.setSouth(&room11);
	room14.setDescription(rm14);
	room14.setShortDesc(short14);
	//room 15
	room15.setNorth(&room18);
	room15.setWest(&room14);
	room15.setSouth(&room12);
	room15.setDescription(rm15);
	room15.setShortDesc(short15);
	//room 16
	room16.setSouth(&room13);
	room16.setDescription(rm16);
	room16.setShortDesc(short16);
	//room 17
	room17.setEast(&room18);
	room17.setSouth(&room14);
	room17.setDescription(rm17);
	room17.setShortDesc(short17);
	//room 18
	room18.setKeyRoom4(true);
	room18.setLocked3(true);
	room18.setWest(&room17);
	room18.setSouth(&room15);
	room18.setDescription(rm18);
	room18.setShortDesc(short18);
	
}

//checks if current space points to a space or nullptr. If nullptr, rejects
//move and re-prompts. else, checks if locked, checks for key and either 
//grants or denies access accordingly
bool Map::goNorth()
{
	Space* newLocation = playerLocation->getNorth();
	//if there is no adjacent space in that direction
	if (newLocation == nullptr)
	{
		cout << "You can\'t go North from here." << endl << endl;
		return false;
	}
	
	//if the space is locked with any level lock
	else if (newLocation->getLocked1())
	{
		//checks if player has right key
		if (keys[0])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 1 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked2())
	{
		if (keys[1])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 2 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked3())
	{
		if (keys[2])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: ADMINISTRATOR ACCESS REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked4())
	{
		if (keys[3])
		{
			playerLocation = newLocation;
			cout << "ESCAPE TEXT" << endl;
			escape = true;
			return true;
		}
		else
		{
			cout << "You can\'t go back to the ship without at least checking the dig site." << endl << endl;
			return false;
		}
	}
	//if no restrictions, moves player to adjacent space
	else
	{
		playerLocation = newLocation;
		return true;
	}
}
bool Map::goEast()
{
	Space* newLocation = playerLocation->getEast();
	if (newLocation == nullptr)
	{
		cout << "You can\'t go East from here." << endl << endl;
		return false;
	}
	else if (newLocation->getLocked1())
	{
		if (keys[0])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 1 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked2())
	{
		if (keys[1])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 2 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked3())
	{
		if (keys[2])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: ADMINISTRATOR ACCESS REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked4())
	{
		if (keys[3])
		{
			playerLocation = newLocation;
			win = true;
			return true;
		}
		else
		{
			cout << "You can\'t go back to the ship without at least checking the dig site." << endl << endl;
			return false;
		}
	}
	else
	{
		playerLocation = newLocation;
		return true;
	}
}
bool Map::goSouth()
{
	Space* newLocation = playerLocation->getSouth();
	if (newLocation == nullptr)
	{
		cout << "You can\'t go South from here." << endl << endl;
		return false;
	}
	else if (newLocation->getLocked1())
	{
		if (keys[0])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 1 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked2())
	{
		if (keys[1])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 2 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked3())
	{
		if (keys[2])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: ADMINISTRATOR ACCESS REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked4())
	{
		if (keys[3])
		{
			playerLocation = newLocation;
			win = true;
			return true;
		}
		else
		{
			cout << "You can\'t go back to the ship without at least checking the dig site." << endl << endl;
			return false;
		}
	}
	else
	{
		playerLocation = newLocation;
		return true;
	}

}
bool Map::goWest()
{
	Space* newLocation = playerLocation->getWest();
	if (newLocation == nullptr)
	{
		cout << "You can\'t go West from here." << endl << endl;
		return false;
	}
	else if (newLocation->getLocked1())
	{
		if (keys[0])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 1 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked2())
	{
		if (keys[1])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: LEVEL 2 CLEARANCE REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked3())
	{
		if (keys[2])
		{
			playerLocation = newLocation;
			cout << "ACCESS GRANTED" << endl << endl;
			return true;
		}
		else
		{
			cout << "ACCESS DENIED: ADMINISTRATOR ACCESS REQUIRED" << endl << endl;
			return false;
		}
	}
	else if (newLocation->getLocked4())
	{
		if (keys[3])
		{
			playerLocation = newLocation;
			cout << "ESCAPE TEXT" << endl << endl;
			escape = true;
			return true;
		}
		else
		{
			cout << "You can\'t go back to the ship without at least checking the dig site." << endl << endl;
			return false;
		}
	}
	else
	{
		playerLocation = newLocation;
		return true;
	}
}

Space* Map::getPlayerLocation()
{
	return playerLocation;
}

//lookAround and runThrough both print the description of the room, runThrough
//just prints a shorter one. lookAround also checks if there is a key in the room
//and adds it to the player's inventory if so.
void Map::lookAround()
{
	cout << playerLocation->getDescription() << endl << endl;

	if (playerLocation->getKeyRoom1())
	{
		cout << "An ID card for Mark Gillman, Mine Operations Personnel, is sitting on the desk." << endl
			<< "Attached is a keycard with \"L1\" printed on it. You take the keycard." << endl;
		playerLocation->setKeyRoom1(false);
		//places key in player's inventory
		keys[0] = true;
	}
	if (playerLocation->getKeyRoom2())
	{
		cout << "The ruined corpse still has its ID card: Karen Hammond, Assistant Science Director." << endl
			<< "Attached is a keycard with \"L2\" printed on it. You take the keycard." << endl;
		playerLocation->setKeyRoom2(false);
		keys[1] = true;
	}
	if (playerLocation->getKeyRoom3())
	{
		cout << "The acid-burned man\'s hand reaches toward the top desk drawer which holds the ID card" << endl
			<< "of John Kinzler, Chief Overseer, a \"MAX\" keycard, and ammo for his pistol. You take the keycard..." << endl
			<< "and the gun." << endl;
		playerLocation->setKeyRoom3(false);
		keys[2] = true;
	}
	if (playerLocation->getKeyRoom4())
	{
		playerLocation->setKeyRoom4(false);
		escape = true;
		keys[3] = true;
	}
}
void Map::runThrough()
{
	cout << playerLocation->getShortDesc() << endl << endl;
}

bool Map::getEscape()
{
	return escape;
}
bool Map::getWin()
{
	return win;
}
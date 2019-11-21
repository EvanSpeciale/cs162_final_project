/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Space class implementation.
******************************************************************************/
#include "Space.hpp"
#include <string>
using std::string;

Space::Space()
{
}

//get functions for adjacent spaces
Space* Space::getNorth()
{
	return north;
}
Space* Space::getEast()
{
	return east;
}
Space* Space::getSouth()
{
	return south;
}
Space* Space::getWest()
{
	return west;
}

//set functions for adjacent spaces
void Space::setNorth(Space* north)
{
	this->north = north;
}
void Space::setEast(Space* east)
{
	this->east = east;
}
void Space::setSouth(Space* south)
{
	this->south = south;
}
void Space::setWest(Space* west)
{
	this->west = west;
}

//get and set functions for space descriptions
string Space::getDescription()
{
	return description;
}
string Space::getShortDesc()
{
	return shortDesc;
}
void Space::setDescription(string descrip)
{
	description = descrip;
}
void Space::setShortDesc(string shortDescrip)
{
	shortDesc = shortDescrip;
}

//get and set functions for flags indicating that a space is locked or holds a key
void Space::setKeyRoom1(bool key)
{
	keyRoom1 = key;
}
void Space::setKeyRoom2(bool key)
{
	keyRoom2 = key;
}
void Space::setKeyRoom3(bool key)
{
	keyRoom3 = key;
}
void Space::setKeyRoom4(bool key)
{
	keyRoom4 = key;
}
void Space::setLocked1(bool lock)
{
	locked1 = lock;
}
void Space::setLocked2(bool lock)
{
	locked2 = lock;
}
void Space::setLocked3(bool lock)
{
	locked3 = lock;
}
void Space::setLocked4(bool lock)
{
	locked4 = lock;
}
bool Space::getLocked1()
{
	return locked1;
}
bool Space::getLocked2()
{
	return locked2;
}
bool Space::getLocked3()
{
	return locked3;
}
bool Space::getLocked4()
{
	return locked4;
}
bool Space::getKeyRoom1()
{
	return keyRoom1;
}
bool Space::getKeyRoom2()
{
	return keyRoom2;
}
bool Space::getKeyRoom3()
{
	return keyRoom3;
}
bool Space::getKeyRoom4()
{
	return keyRoom4;
}
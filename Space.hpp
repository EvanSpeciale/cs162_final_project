/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Space class declaration. i.	Each space object has 4 pointers to
**				set which spaces are to the North, East, South and West. If 
**				there is no room in any direction, that pointer is set to nullptr.
**				Each space has a short and long description. Displays long
**				description before player reaches mining platform, short one
**				after. Rooms may hold a key (e.g. keyRoom1 = true), be locked
**				(e.g. locked1 = true), or both. Class methods are just get and
**				set functions for each Space member variable.
******************************************************************************/
#ifndef SPACE_HPP	
#define SPACE_HPP
#include <string>
using std::string;

class Space
{
private:
	//pointers to each adjacent space (or nullptr if no adjacent space)
	Space* north = nullptr;
	Space* east = nullptr;
	Space* south = nullptr;
	Space* west = nullptr;
	
	//strings for short and long descriptions
	string description;
	string shortDesc;
	
	//flags to mark rooms as locked or containing keys
	bool keyRoom1 = false;
	bool keyRoom2 = false;
	bool keyRoom3 = false;
	bool keyRoom4 = false;
	bool locked1 = false;
	bool locked2 = false;
	bool locked3 = false;
	bool locked4 = false;
public:
	Space();
	
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();
	void setNorth(Space*);
	void setEast(Space*);
	void setSouth(Space*);
	void setWest(Space*);

	string getDescription();
	void setDescription(string);
	string getShortDesc();
	void setShortDesc(string);
	
	void setKeyRoom1(bool);
	void setKeyRoom2(bool);
	void setKeyRoom3(bool);
	void setKeyRoom4(bool);
	
	void setLocked1(bool);
	void setLocked2(bool);
	void setLocked3(bool);
	void setLocked4(bool);
	
	bool getLocked1();
	bool getLocked2();
	bool getLocked3();
	bool getLocked4();
	
	bool getKeyRoom1();
	bool getKeyRoom2();
	bool getKeyRoom3();
	bool getKeyRoom4();
};

#endif //SPACE_HPP
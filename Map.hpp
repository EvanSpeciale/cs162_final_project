/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: Map class declaration. Member variables include 18 Space objects,
**				18 long descriptions, 18 short descriptions, a vector to hold
**				the “keys”, a Space pointer to hold the player’s location, and
**				“escape” and “win” flags to indicate when game events happen.
**				The Map constructor connects all space objects to create a static
**				linked list and initializes all Space variables. the goDirection
**				functions check if there is an adjacent space to the player's
**				space and moves the player to that space. The look around and
**				run through functions print the space descriptions as the player
**				moves.
******************************************************************************/
#ifndef MAP_HPP
#define MAP_HPP
#include "Space.hpp"
#include <string>
#include <vector>
using std::vector;
using std::string;

class Map
{
private:
	string out = "outside";
	string rm1 =	"The crew\'s quarters are a large rectangular room with bunk beds\n"
					"set into all four walls and three freestanding sets of beds in the\n"
					"center along the length of the room. The beds are neat but littered\n"
					"with personal effects: photos, drawings, whiteboards with crude\n"
					"messages written on them, etc. At each end of the room is a set of\n"
					"small lockers and a round table surrounded by five stools. An\n"
					"unfinished game of Go sits on one of the tables.\n\n"
					"There are two doors, one to the Eastand one to the North.";
	string rm2 =	"The loading bay is clean and well organized. There are no vehicles\n"
					"in the dock, but pallets full of helium-3 cannisters are neatly\n"
					"stacked along the walls awaiting shipment.\n\n"
					"There is a large shutter-like door to the east, and human-sized\n"
					"doors to the North and the West. The West door has a keypad next\n"
					"to it with \"L1\" displayed in green.";
	string rm3 =	"Three elevated tracks with metal rollers run from the room to the\n"
					"East, through the center of the room, and up to the large shutter\n"
					"on the West wall. The tracks run through three 3\'x3\' holes in the\n"
					"East wall from the adjoining room. At the west end of the room\n"
					"there is a stack of polycarb pallets and a container full of sturdy\n"
					"metal straps. At the end of each track is an empty pallet and a\n"
					"pallet jack. This seems to be the room where the cannisters are\n"
					"checked and prepared for shipping. There are a couple cannisters\n"
					"still on the tracks, but the operation appears to be in working\n"
					"order.\n\n"
					"There is a door to the East and a large shutter to the West.";
	string rm4 =	"Large, heavily insulated pipes enter this room through the Eastern\n"
					"Wall and connect to a large machine which sits idly, red exclamation\n"
					"marks flashing on its various displays. The machine appears to fill\n"
					"the cannisters four at a time while large robotic arms load and\n"
					"unload the cannisters from the filling station. The cannisters are\n"
					"placed on tracks of metal rollers and sent through holes in the\n"
					"wall to the room to the West.\n\n"
					"There is a door to the West and a door to the North.";
	string rm5 =	"A body lies in a pool of blood at the far end of the locker room,\n"
					"near the showers. There is a gaping, ragged hole in the center of\n"
					"the crew member\'s chest and their sternum and ribcage is visibly\n"
					"broken or missing. Blood is sprayed on the walls and some has even\n"
					"reached the ceiling. It\'s hard to imagine how a gun could have\n"
					"caused this injury, but you struggle to think of anything else\n"
					"powerful enough to cause such a cavernous wound. This person didn\'t\n"
					"die today, but the scene is still fresh enough that you think\n"
					"whatever did this might still be around. Now it\'s even more\n"
					"important to get that cell and get off this moon.\n\n"
					"There is a door to the South.";
	string rm6 =	"The infirmary is in disarray with broken glass littered on the floor\n"
					"and some blood on the operating table at the center of the room.\n"
					"Some cabinet doors are left open and supplies are scattered across\n"
					"the counters. You wonder if this emergency surgery was a success\n"
					"until you see a sheet-covered body through the glass door of an\n"
					"observation room with a large dark red stain in the middle of the\n"
					"chest. Guess not.\n\n"
					"There is a door to the Eastand a door to the South.";
	string rm7 =	"The T-shaped hallway connects the rooms to the East and the West\n"
					"with a large mechanical door facing North. Painted on the walls\n"
					"are arrows pointing to \"Infirmary\" (East), \"Canteen/Rec Room\" (West),\n"
					"and \"Lab/Mine Operations\" (North). Smeared bloody footprints are\n"
					"tracked on the floor from the Eastern door to the Western door.\n\n"
					"There are doors to the North, East, and West. The North door has a\n"
					"keypad next to it with \"L2\" displayed in blue.";
	string rm8 =	"The Rec Room has two small tables with five chairs each, three\n"
					"large couches surrounding a large projector screen, a ping pong\n"
					"and air hockey table, and an old school Addam's Family pinball\n"
					"machine - the high score belongs to \"ASS\".\n\n"
					"The cards scattered on the tableand various half-finished drinks\n"
					"littering the room make you think that people left this room in a hurry.\n\n"
					"There are two sets of doors to the North, a door to the East, a door\n"
					"to the West, and a door to the South.";
	string rm9 =	"The small administrative office is cluttered and smells like the\n"
					"inside of a microwave. The room is dingy and unadorned except for\n"
					"two Weyland Mining Corp. posters touting the company\'s innovations in\n"
					"\"The Future of Energy\" and instructing employees to report any talk\n"
					"of labor organization to their supervisor.\n\n"
					"There is a door to the West.";
	string rm10 =	"At the end of the large, tasteful administrative office, a man sits\n"
					"slumped in an office chair behind a desk, his face and chest so\n"
					"badly acid burned you can\'t make out any of his features. He holds\n"
					"a pistol in his right hand, the slide pulled back and the ejection\n"
					"port exposed - he ran out of bullets before he met his end. Some\n"
					"of the ceiling tiles have been damaged or destroyed and a large\n"
					"hole in the drop ceiling exposes wires and vents running out of\n"
					"the room to the North.\n\n"
					"There is a door to the East.";
	string rm11 =	"The operations center has been virtually destroyed by gunfire and\n"
					"the large gashes ripped across the equipment lining the walls. The\n"
					"display console in the center of the room (and the body on top of\n"
					"it) have been crushed by something narrow and powerful which must\n"
					"have slammed down along the length of the console with immense\n"
					"force. The person sitting in the chair nearest the North door lies\n"
					"face down on the complicated array of buttons, a large hole pierced\n"
					"through the back of their head.\n\n"
					"Most of the monitors along the walls are smashed or say \"OFFLINE\",\n"
					"but two cameras are still active: the helium-3 cannister filling\n"
					"station at the South end of the facility and the cavernous mining\n"
					"platform at the north end.Both scenes are completely still.You can\n"
					"see a hulking oversized excavator sitting on a lift against the\n"
					"East wall of the mining platform - if the fuel cell is still there,\n"
					"this is exactly what you need to escape this nightmare.\n\n"
					"There is a door to the Northand a small office door to the West.";
	string rm12 =	"A wide hallway runs North-South past a large laboratory; the two\n"
					"are separated by a glass wall and a pair of sliding doors. The\n"
					"laboratory walls are lined with cabinets and benches and two\n"
					"freestanding lab benches sit in the center of the room. The North\n"
					"end of the lab is taken up with complicated-looking centrifuges\n"
					"and industrial chromatography columns. Test tube racks and trays\n"
					"of vials sit on the counters next to open lab notebooks and fancy\n"
					"micropipettes.\n\n"
					"In one of the vent hoods, some sort of spider - like creature lies\n"
					"on its back, its legs curledand its thick, muscular tail laid\n"
					"straight out from its body. One of the legs has been severed at a\n"
					"joint and an opaque green fluid has leaked out onto the body and\n"
					"sprayed onto the walls of the vent hood. Where the fluid has\n"
					"touched the hood, the material is meltedand bubbled as if by an\n"
					"especially caustic acid.\n\n"
					"There are doors at the North and South end of the hallway.";
	string rm13 =	"The mess hall contains three long parallel tables with benches on\n"
					"each side. Dish carts sit empty in the corners. On the North wall\n"
					"is a large serving window into the kitchen.\n\n"
					"The room is essentially spotless, it must not have been mealtime\n"
					"when... whatever went down.\n\n"
					"There are two swinging doors to the Northand two doors to the South.";
	string rm14 =	"The T-shaped hallway is a grisly scene: eight people lie dead,\n"
					"eviscerated by... metal tools? claws? teeth? Most of the bodies\n"
					"wear the gray boiler suits of miners, but one is equipped in some\n"
					"measure of combat gear - it didn\'t make a difference. All the bodies\n"
					"have been thrown against the walls and lie in piles (and pieces)\n"
					"along the edges of the corridor.\n\n"
					"Through the blood splashed and smeared on the wall you can make out\n"
					"arrows pointing to \"Garage / Maintenance\"(North), \"Armory\"(East),\n"
					"and \"Operations Center\"(South).\n\n"
					"There are doors to the North, East, and South.";
	string rm15 =	"Shells and cartridges are scattered across every surface of the\n"
					"locker room and armory, and bullet holes riddle the North wall near\n"
					"a heavy metal door with six thick security bolts securing it shut.\n"
					"Two people in gray boiler suits lie crumpled on the floor near the\n"
					"North door, one with a large hole punched all the way through their\n"
					"abdomen. The other\'s legs have been severed cleanly, seemingly in\n"
					"one motion. They still clutch their weapons, looks of terror frozen\n"
					"on their faces. Two turret guns on tripods sit pointed at the North\n"
					"door, their displays flashing \"AMMO\". A sign above the North door\n"
					"reads \"HARD HATS MUST BE WORN PAST THIS POINT\". That must be the\n"
					"mining platform.\n\n"
					"There are doors to North, West, and South.The heavy, armored door\n"
					"to the North has a keypad next to it with \"MAX\" displayed in red.";
	string rm16 =	"The large industrial kitchen is all white tile and stainless\n"
					"steel. Pans and utensils hang from the walls and the large rack\n"
					"in the center of the room, but some holes indicate that pieces\n"
					"are missing. It looks like prep for dinner was interrupted as\n"
					"cutting boards with dry, wilting vegetables lie across several\n"
					"surfaces. A couple of heavy tables have been pushed against the\n"
					"walk-in freezer door at the north end of the room and a sturdy\n"
					"metal spoon has been jammed in the latch mechanism to keep it\n"
					"from opening. The small porthole window into the freezer has\n"
					"frozen over so you can\'t see what might be locked in there.\n\n"
					"There are two swinging doors to the South.";
	string rm17 =	"The garage houses a handful of material transport and personnel\n"
					"vehicles in various states of repair. Unfortunately none of these\n"
					"are big enough to have a fuel cell as large as you need.\n\n"
					"A thick glass window looks through the eastern wall into the\n"
					"cavernous mining platformand a large armored garage door gives\n"
					"access to the vehicles going between these two rooms.Through the\n"
					"window you see some scattered bodies across the platformand, on\n"
					"the East side, a huge excavator sitting on a lift waiting to\n"
					"descend to the dig site.From here, you can see the fuel cell\n"
					"compartment, seemingly intact.This stupid idea just might have\n"
					"worked after all.\n\n"
					"There is a door to the Southand an armored garage door to the\n"
					"East. Next to the garage door is a keypad with \"MAX\" displayed in\n"
					"red.";
	string rm18 =	"Ignoring the mangled bodies littering the mining platform, you\n"
					"walk purposefully toward the Eastern lift and the excavator. The\n"
					"platform would usually be deafeningly loud given the heavy\n"
					"machinery that operates here normally, but now it is eerily\n"
					"quiet. The only sign of movement is the flashing yellow warning\n"
					"lights that sit on the corners of the elevator shafts.\n\n"
					"As you near the excavator you can finally make out the fuel meter\n"
					"on the right side of the fuel cell compartment: 70%. Plenty to\n"
					"power your dinghy back to the mothership in orbit.The fuel cell\n"
					"is shaped roughly like a two - foot tall soda can; it will be\n"
					"heavy to be sure, but manageable for the trip back to the ship.\n\n"
					"You yank the ejection lever down over the cell compartment: a\n"
					"loud gas hiss and an even louder electronic BEEP indicate that\n"
					"the cell is now free. Above youand about 20 meters to the North,\n"
					"movement catches your eye. A long black tail that looks like a\n"
					"spinal cord with a scorpion stinger tip uncurls from the gaunt\n"
					"humanoid bodyand elongated skull perched in a divot in the cave\n"
					"wall.\n\n"
					"It\'s time to run.Your only chance is to head back to your ship as\n"
					"fast as you possibly can; one false moveand you are sure to end\n"
					"up like the rest of the inhabitants of this doomed venture.\n\n"
					"OBJECTIVE: Get out. Use your (hopefully accurate) map to take the\n"
					"most direct route you can to the exit. If you turn around or enter\n"
					"a dead end, it\'s game over man, game over. If you make it to the\n"
					"exit, you just might be able to ditch this rock before... well,\n"
					"let\'s not think about what comes next.";
	string shortOutside;
	string short1 = "Crew\'s Quarters\n\n"
					"There are two doors, one to the Eastand one to the North.";
	string short2 = "Loading Bay\n\n"
					"There is a large shutter - like door to the east, and human - sized\n"
					"doors to the North and the West.";
	string short3 = "Shipping Prep Room\n\n"
					"There is a door to the East and a large shutter to the West.";
	string short4 =	"Helium Cannister Filling Room\n\n"
					"There is a door to the West and a door to the North.";
	string short5 = "Crew Bathroom\n\n"
					"There is a door to the South.";
	string short6 = "Infirmary\n\n"
					"There is a door to the East and a door to the South.";
	string short7 = "South Hallway\n\n"
					"There are doors to the North, East, and West.";
	string short8 = "Rec Room\n\n"
					"There are two sets of doors to the North, a door to the East,\n"
					"a door to the West, and a door to the South.";
	string short9 = "Small Office\n\n"
					"There is a door to the West.";
	string short10 = "Overseer\'s Office\n\n"
					"There is a door to the East.";
	string short11 = "Operations Center\n\n"
					"There is a door to the North and a small office door to the West.";
	string short12 = "Laboratory\n\n"
					"There are doors at the North and South end of the hallway.";
	string short13 = "Canteen\n\n"
					"There are two swinging doors to the North and two doors to the South.";
	string short14 = "North Hallway\n\n"
					"There are doors to the North, East, and South.";
	string short15 = "Locker Room and Armory\n\n"
					"There are doors to North, West, and South.";
	string short16 = "Kitchen\n\n"
					"There are two swinging doors to the South.";
	string short17 = "Garage\n\n"
					"There is a door to the South and an armored garage door to the East.";
	string short18 = "Mining Platform\n\n"
					"There is a door to the West and the door to the South";

	Space outside;
	Space room1;
	Space room2;
	Space room3;
	Space room4;
	Space room5;
	Space room6;
	Space room7;
	Space room8;
	Space room9;
	Space room10;
	Space room11;
	Space room12;
	Space room13;
	Space room14;
	Space room15;
	Space room16;
	Space room17;
	Space room18;
	
	//pointer to player's location
	Space* playerLocation = &room2;

	//container to hold "keys"
	vector<bool> keys{ false, false, false, false };
	
	//flags to indicate if player is in escape sequence or has won the game
	bool escape = false;
	bool win = false;
public:
	Map();
	
	bool goNorth();
	bool goEast();
	bool goSouth();
	bool goWest();
	
	Space* getPlayerLocation();
	
	void lookAround();
	void runThrough();
	
	bool getEscape();
	bool getWin();
};

#endif //MAP_HPP
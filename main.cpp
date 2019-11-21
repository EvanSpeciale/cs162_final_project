/******************************************************************************
** Name:		Evan Speciale
** Date:		August 13, 2019
** Description: main function creates game object and repeats move prompts until
**				the escape sequence flag is set. Then repeats escape prompts until
**				either the "dead" or "win" flag is set.
******************************************************************************/
#include "Game.hpp"
#include "Map.hpp"
#include "Space.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Game game;
	do
	{
		game.move();
	} while (game.getEscape() != true);

	do
	{
		game.escape();
	} while (game.getWin() != true && game.getDead() != true);

	if (game.getWin())
	{
		cout << "You sprint out of the facility with every ounce of your remaining" << endl
			<< "energy. It\'s a 100 m dead sprint back to the ship." << endl << endl
			<< "When you reach the fuel compartment, you dunk the cell inand slam the" << endl
			<< "ejection lever into place.You run to the cockpitand blast the throttle" << endl
			<< "as high as you dare; yes, the bay door is still open, but you don’t have" << endl
			<< "time to worry about that, you just need to get away from HERE. As the" << endl
			<< "ship accelerates (MUCH slower than you remember), you can see the creature" << endl
			<< "galloping toward you with alarming speed. It leaps toward the closing bay" << endl
			<< "door and catches one of its claws in the gap. You pull down the small" << endl
			<< "fire axe strapped to the wall above the doorand swing. Green fluid" << endl
			<< "sprays outand begins to burn the interior, but the creature shrieksand" << endl
			<< "lets go of the ship, falling to the surface." << endl << endl
			<< "You prepare the ship for orbitand begin to make your way back toward" << endl
			<< "your vessel in orbit." << endl << endl
			<< "Congratulations, you escaped with your life!" << endl;
	}
	else if (game.getDead())
	{
		cout << "You turn around and see the creature stalking toward you. The last thing you see is its black, dripping maw." << endl << endl
			<< "GAME OVER" << endl;
	}

	return 0;
}
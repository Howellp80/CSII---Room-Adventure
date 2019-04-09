/****************************************************************************************
* Class name: Center.hpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The center room for the game, derived from Space base class
****************************************************************************************/

#ifndef CENTER_HPP
#define CENTER_HPP

#include "Space.hpp"

class Center : public Space
{
public:
	// constructor set access to the player object and sets bool complete to false
	Center(Player *);

	// default destructor
	~Center();



	/****************************************************************************************
	* Function name: special()
	* Parameters: none
	* Description: Prints the room description and options. Bases on selected option and 
	*              what the player has equiped, runs a loop to determine the players fate.
	*              Returns a 1 when the player changes rooms, a 2 if the player dies, and
	*              a 3 if the player wins the game.
	****************************************************************************************/
	int special();

};

#endif
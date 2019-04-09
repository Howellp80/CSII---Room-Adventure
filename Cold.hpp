/****************************************************************************************
* Class name: Cold.hpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The cold room for the game, derived from Space base class
****************************************************************************************/

#ifndef COLD_HPP
#define COLD_HPP

#include "Space.hpp"

class Cold : public Space
{
public:
	// constructor set access to the player object and sets bool complete to false
	Cold(Player *);

	// default destructor
	~Cold();



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
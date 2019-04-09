/****************************************************************************************
* Class name: Game.hpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Creates the players and the rooms, initializing their values and then 
*              handles main gameplay.
****************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Center.hpp"
#include "Water.hpp"
#include "Hot.hpp"
#include "Cold.hpp"
#include "Dark.hpp"
#include "Space.hpp"
#include <iostream>
#include <cstdlib>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

class Game
{
private:
	int turns,               // tracks room changes for timed hints
		playerState;         // did the player leave a room, die, or win the game 
	Player * player;         // the game character
	Space * centerRoom,      // central room connecting to all of the others
		  * waterRoom,       // room with waterfall in it
		  * hotRoom,         // room with lava in it
		  * coldRoom,        // room with ice block in it
		  * darkRoom;        // pitch black room

public:
	// default constructor
	Game();

	// destructor deletes player and room objects
	~Game();



	/****************************************************************************************
	* Function name: init()
	* Parameters: none
	* Description: Dynamically creates player and room objects. Sets the starting player
	*              location, and sets turns to zero. Connects each room to the 
	*              others via pointers. 
	****************************************************************************************/
	void init();



	/****************************************************************************************
	* Function name: play()
	* Parameters: none
	* Description: Primary game loop determines what is done based on a returned gamestate.
	*              Prints out game intro text and game ending text. Checks the timer.
	****************************************************************************************/
	void play();



	/****************************************************************************************
	* Function name: checkTimer()
	* Parameters: none
	* Description: Checks on the players progress and periodically offers up hints so the 
	*              player can complete the game if they're having difficulty.
	****************************************************************************************/
	void checkTimer();

};

#endif
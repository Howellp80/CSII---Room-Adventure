/****************************************************************************************
* Class name: Water.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The waterfall room for the game, derived from Space base class
****************************************************************************************/

#include "Water.hpp"

// constructor set access to the player object and sets bool complete to false
Water::Water(Player *p)
{
	setPlayer(p);
	setComplete(false);
}

// default destructor
Water::~Water()
{
}



/****************************************************************************************
* Function name: special()
* Parameters: none
* Description: Prints the room description and options. Bases on selected option and
*              what the player has equiped, runs a loop to determine the players fate.
*              Returns a 1 when the player changes rooms, a 2 if the player dies, and
*              a 3 if the player wins the game.
****************************************************************************************/
int Water::special()
{
	// room description
	system(CLEAR_SCREEN);
	std::cout << "As you enter the room, the first thing you notice is a" << std::endl;
	std::cout << "small waterfall falling down the height of the back" << std::endl;
	std::cout << "wall. The water pours out of a carved serpent head and" << std::endl;
	std::cout << "lands below in a shallow pool that must drain to" << std::endl;
	std::cout << "somewhere else below. The air is humid and the stone" << std::endl;
	std::cout << "walls glisten with dampness. The room otherwise, is" << std::endl;
	std::cout << "oddly plain." << std::endl << std::endl;
	
	// if there are items on the floor, print them
	if (!floor.empty()){
		printFloor();
		std::cout << std::endl << std::endl;
	}

	do{
		// room options
		std::cout << " [1] - Examine the Waterfall" << std::endl;
		std::cout << " [2] - Equip/Use item from Ruck Sack" << std::endl;
		std::cout << " [3] - Go to another Room" << std::endl;
		if (!floor.empty())
			std::cout << " [4] - Pick up item(s) from the floor" << std::endl;
		std::cin >> choice;

		//validate choice
		if (floor.empty())
			while (choice < 1 || choice > 3){
			std::cout << "Choose 1 - 3." << std::endl;
			std::cin >> choice;
			}

		else
			while (choice < 1 || choice > 4){
			std::cout << "Choose 1 - 4." << std::endl;
			std::cin >> choice;
			}


		// examine waterfall
		if (choice == 1){
			//does the player have the phial?
			if (!complete ){
				system(CLEAR_SCREEN);
				std::cout << "You approach the Waterfall, eyeing the carved" << std::endl;
				std::cout << "serpent head above. At first glance there doesn't" << std::endl;
				std::cout << "appear to be anything remarkable about the fall." << std::endl;
				std::cout << "However, as you get closer you notice a faint blue" << std::endl;
				std::cout << "glow shining through the falling water. Cautiously" << std::endl;
				std::cout << "reaching through the water you grasp at the" << std::endl;
				std::cout << "glowing object. You pull out a Crystal Phial filled" << std::endl;
				std::cout << "with a glowing liquid. You pop the top and smell" << std::endl;
				std::cout << "the liquid. It smells harmless enough. You resecure" << std::endl;
				std::cout << "the top and stuff the Phial into your Ruck Sack." << std::endl << std::endl;

				checkPackFull();
				player->add2Pack("Phial");
				player->setHasPhial(true);
				complete = true;

				pause();
			}

			else { //The player has the phial.
				system(CLEAR_SCREEN);
				std::cout << "Looking at the fall reminds you of the Crystal" << std::endl;
				std::cout << "Phial you found behind the cool waters. You" << std::endl;
				std::cout << "suppose that the carved serpent head above the" << std::endl;
				std::cout << "fall doesn't seem quite as menacing now that" << std::endl;
				std::cout << "it has offered you such a gift." << std::endl << std::endl;

				pause();
			}
		}

		// equip/use inventory selected 
		if (choice == 2){
			itemManip();
			pause();
		}

		// if player wants to pick up items from the floor
		if (choice == 4){
			itemPickup();
			pause();
		}

	}
	//  repeat while the player didn't change rooms, or win, or die
	while (choice != 3);


	// user wants to go to another room
	changeRoom();
	return 1;
}




















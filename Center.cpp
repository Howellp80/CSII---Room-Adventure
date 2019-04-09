/****************************************************************************************
* Class name: Center.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The center room for the game, derived from Space base class
****************************************************************************************/

#include "Center.hpp"

// constructor set access to the player object and sets bool complete to false
Center::Center(Player * p)
{
	setPlayer(p);
	setComplete(false);
}

// default destructor
Center::~Center()
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
int Center::special()
{
	// room description
	system(CLEAR_SCREEN);
	std::cout << "You are in a dimly lit circular room. You can make" << std::endl;
	std::cout << "out five doorways. One of which is sealed. In the" << std::endl;
	std::cout << "second you can hear the sound of rushing water." << std::endl;
	std::cout << "From the third you see and feel a warm glow. From the" << std::endl;
	std::cout << "fourth door, a cold draft eminates from within. The" << std::endl;
	std::cout << "fifth door is pitch black and uneasily still." << std::endl 
		      << std::endl;

	// if there are items on the floor, print them
	if (!floor.empty()){
		printFloor();
		std::cout << std::endl << std::endl;
	}

	do{
		// room options
		std::cout << " [1] - Examine the Sealed Door" << std::endl;
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

		// examine sealed door
		if (choice == 1){
			//does the player have the key equiped?
			if (player->getKeyEquiped()){
				system(CLEAR_SCREEN);
				std::cout << "You approach the Sealed door with Skull key in hand." << std::endl;
				std::cout << "Raising the key to the lock, it slides in as though" << std::endl;
				std::cout << "freshly oiled. The gentlest of pressure turns the" << std::endl;
				std::cout << "key. A feeling of satisfaction fills you as the" << std::endl;
				std::cout << "tumbler releases and the lock disengages. You hear" << std::endl;
				std::cout << "the sound of grinding stone behind the door, and" << std::endl;
				std::cout << "then the door itself begins to part. A splendid," << std::endl;
				std::cout << "shimmering light fills your eyes! Before you lays" << std::endl;
				std::cout << "the long saught after treasure of Altea." << std::endl << std::endl;

				pause();

				system(CLEAR_SCREEN);
				std::cout << "Several dozen large chests sit about the room with" << std::endl;
				std::cout << "their lids open. Spilling forth you see golden coins," << std::endl;
				std::cout << "diamonds, onyx rings, and other gems and jewelry. To" << std::endl;
				std::cout << "say that you came across a fortune would be an" << std::endl;
				std::cout << "Understatement. Adorning the walls you notice finely" << std::endl;
				std::cout << "crafted weapons and armor. Each unique with fitted" << std::endl;
				std::cout << "rubys, emeralds, and dragon's eye gems. Against the" << std::endl;
				std::cout << "side wall there lies a sturdy shelf filled with" << std::endl;
				std::cout << "various prescious metal ingots. You couldn't have" << std::endl;
				std::cout << "imagined such wealth even if you had a lifetime to" << std::endl;				
				std::cout << "ponder it! Then you notice a hallway leading off of" << std::endl;
				std::cout << "the back wall. Near its end, you can clearly make out" << std::endl;
				std::cout << "sunshine entering the passageway. Fortune smile upon" << std::endl;
				std::cout << "you with not only untold riches, but a way out as" << std::endl;
				std::cout << "well." << std::endl << std::endl;

				std::cin.get();

				return 3;
			}

			else { //The key isn't equiped.
				system(CLEAR_SCREEN);
				std::cout << "The Sealed Doors stand about ten feet tall and" << std::endl;
				std::cout << "are made of a polished stone. Images of what" << std::endl;
				std::cout << "must have been a ruling family and a sprawling" << std::endl;
				std::cout << "city with a fortified castle occupy most of the" << std::endl;
				std::cout << "carved area. The doors are much too thick to" << std::endl;
				std::cout << "break through with anything you have at your" << std::endl;
				std::cout << "disposal. But there is a keyhole. Perhaps you" << std::endl;
				std::cout << "could find the key and unlock what lays behind." << std::endl;
				std::cout << std::endl;

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








/****************************************************************************************
* Class name: Hot.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The hot room for the game, derived from Space base class
****************************************************************************************/

#include "Hot.hpp"

// constructor set access to the player object and sets bool complete to false
Hot::Hot(Player *p)
{
	setPlayer(p);
	setComplete(false);
}

// default destructor
Hot::~Hot()
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
int Hot::special()
{
	// room description
	system(CLEAR_SCREEN);
	if (!complete){
		std::cout << "A wave of heat hits your face as you enter the room." << std::endl;
		std::cout << "In the center you notice a lit torch held in a stone" << std::endl;
		std::cout << "podium. The side walls are lined along the bottom" << std::endl;
		std::cout << "with metal grates, and below the grates you can see" << std::endl;
		std::cout << "molten lava. Behind the torch, against the back wall" << std::endl;
		std::cout << "you find the gaping jaws of a carved dragon head. It" << std::endl;
		std::cout << "appears as if the dragon is watching over the torch." << std::endl << std::endl;
	}
	else{
		std::cout << "A wave of heat hits your face as you enter the room." << std::endl;
		std::cout << "In the center you notice the stone podium that once" << std::endl;
		std::cout << "held the torch that you took. Against the back wall" << std::endl;
		std::cout << "you find the gaping jaws of the carved dragon head." << std::endl;
		std::cout << "You still treat the room with caution, as you can't be" << std::endl;
		std::cout << "sure if the Crystal Phial is still working it's magic" << std::endl;
		std::cout << "on you." << std::endl << std::endl;
	}
	// if there are items on the floor, print them
	if (!floor.empty()){
		printFloor();
		std::cout << std::endl << std::endl;
	}

	do{
		// room options
		std::cout << " [1] - Examine the Torch area" << std::endl;
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


		// examine torch area
		if (choice == 1){
			//do they have the torch?
			if (!complete){
				// have they drank from the crystal phial?
				if (player->getPhialEquiped()){
					system(CLEAR_SCREEN);
					std::cout << "You approach the Eternal Torch slowly, wiping" << std::endl;
					std::cout << "sweat from your brow. The Torch is set inside of a" << std::endl;
					std::cout << "stone podium, but appears as if it would come " << std::endl;
					std::cout << "free if you were to pull it upwards. You brace " << std::endl;
					std::cout << "yourself and wipe the sweat from your hands before " << std::endl;
					std::cout << "placing them firmly around the torch. You pull, and " << std::endl;
					std::cout << "the torch rises free of the podium. However at that " << std::endl;
					std::cout << "moment the carved dragon head erupts with flame, " << std::endl;
					std::cout << "enveloping your body! You panic, naturally, but " << std::endl;
					std::cout << "quickly realize that the fire doesn't burn! It must" << std::endl;
					std::cout << "be the drink you took from the Crystal Phial, you" << std::endl;
					std::cout << "think to yourself. The Eternal Torch extinguishes" << std::endl;
					std::cout << "itself as you go to put it in your Ruck Sack." << std::endl << std::endl;

					checkPackFull();
					player->add2Pack("Torch");
					player->setHasTorch(true);
					complete = true;
				}

				else{
					system(CLEAR_SCREEN);
					std::cout << "You approach the Eternal Torch slowly, wiping" << std::endl;
					std::cout << "sweat from your brow. The Torch is set inside of" << std::endl;
					std::cout << "the stone podium, but appears as if it would come " << std::endl;
					std::cout << "free if you were to pull it upwards. You brace " << std::endl;
					std::cout << "yourself and wipe the sweat from your hands before " << std::endl;
					std::cout << "placing them firmly around the torch. You pull, and " << std::endl;
					std::cout << "the torch rises free of the podium. However at that " << std::endl;
					std::cout << "moment the carved dragon head erupts with flame, " << std::endl;
					std::cout << "enveloping your body! You panic, naturally, and" << std::endl;
					std::cout << "for two to three seconds you feel the most intense" << std::endl;
					std::cout << "pain of your life. By that point though the flames" << std::endl;
					std::cout << "had begun to burn away your nerve endings. You pass" << std::endl;
					std::cout << "out from the shock as the fire continues to consume" << std::endl;
					std::cout << "what is left of your corpse." << std::endl << std::endl;

					return 2;
				}
					
					pause();
				

			}

			//The player has the torch.
			else { 
				system(CLEAR_SCREEN);
				std::cout << "Looking at the empty podium reminds you of the" << std::endl;
				std::cout << "engulfing flames and just how quickly one can" << std::endl;
				std::cout << "lose their life down here. You're glad to have a" << std::endl;
				std::cout << "Torch now, both for it's light and warmth. But" << std::endl;
				std::cout << "you'd rather not stay and test your chances in" << std::endl;
				std::cout << "this room any longer." << std::endl << std::endl;

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














/****************************************************************************************
* Class name: Cold.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The cold room for the game, derived from Space base class
****************************************************************************************/

#include "Cold.hpp"

// constructor set access to the player object and sets bool complete to false
Cold::Cold(Player *p)
{
	setPlayer(p);
	setComplete(false);
}

// default destructor
Cold::~Cold()
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
int Cold::special()
{
	// room description
	system(CLEAR_SCREEN);
	if (!complete){
		std::cout << "As you enter the room you can see your breath." << std::endl;
		std::cout << "Frost crunches beneath your boots. You notice" << std::endl;
		std::cout << "several lifelike statues throughout the room. Just" << std::endl;
		std::cout << "beyond them there is a large protruding ice block" << std::endl;
		std::cout << "jutting up from the ground. Otherwise everything" << std::endl;
		std::cout << "else is frosted over. You pull your cloak tighter" << std::endl;
		std::cout << "in an attempt to fight off the cold." << std::endl << std::endl;
	}
	else{
		std::cout << "The room is just as cold as the last time you entered" << std::endl;
		std::cout << "it. Where you had melted the Ice Block, there now sits" << std::endl;
		std::cout << "a fresh layer of ice on the ground. The frozen corpses" << std::endl;
		std::cout << "of past adventures still eternally wait in their" << std::endl;
		std::cout << "tomb. You decide that staying is a bad idea." 
			      << std::endl << std::endl;
	}
	// if there are items on the floor, print them
	if (!floor.empty()){
		printFloor();
		std::cout << std::endl << std::endl;
	}

	do{
		// room options
		std::cout << " [1] - Examine the Frozen Block" << std::endl;
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


		// examine frozen block
		if (choice == 1){
			//do they have the dagger?
			if (!complete){
				// have they equipped the torch?
				if (player->getTorchEquiped()){
					system(CLEAR_SCREEN);
					std::cout << "As you walk deeper into the room it's seems as if" << std::endl;
					std::cout << "you can notice the cold fighting against the warmth" << std::endl;
					std::cout << "of your torch. You'd hate to feel the nip of the" << std::endl;
					std::cout << "cold without your flame. You wearily glance at the" << std::endl;
					std::cout << "statues as you pass them. A shiver runs up your" << std::endl;
					std::cout << "spine as you realize the statues are really frozen" << std::endl;
					std::cout << "solid adventures. You press on, hoping to avoid an" << std::endl;
					std::cout << "icy death. As you reach the Frozen Block, you move" << std::endl;
					std::cout << "your torch closer to better see, only to find that" << std::endl;
					std::cout << "ice begins to melt! Squinting you can barely make" << std::endl;
					std::cout << "out the shape of something within the ice. After a" << std::endl;
					std::cout << "few more moments, your prize is revealed. Your" << std::endl;
					std::cout << "stiff hand prys free the Frost Dagger from the" << std::endl;
					std::cout << "remaining ice. You hurridly go to place the dagger" << std::endl;
					std::cout << "in your Ruck Sack as your mind turns to warmer" << std::endl;
					std::cout << "climates." << std::endl << std::endl;

					checkPackFull();
					player->add2Pack("Dagger");
					player->setHasDagger(true);
					complete = true;
				}

				else{
					system(CLEAR_SCREEN);
					std::cout << "The temperature drops as you enter deeper and" << std::endl;
					std::cout << "deeper within the room. Your body stiffens with" << std::endl;
					std::cout << "each step you take forward. You glance at a nearby" << std::endl;
					std::cout << "statue, only to realize too late that the statue" << std::endl;
					std::cout << "isn't a statue. It's a frozen body! You try to turn" << std::endl;
					std::cout << "around but your body is slow to react. You can't" << std::endl;
					std::cout << "bend your fingers and your feet are no better than" << std::endl;
					std::cout << "stumps. You slip on the frosted ground. The warmth" << std::endl;
					std::cout << "of life leaving you ever faster. Your mind pannicks" << std::endl;
					std::cout << "at the thought of an iced entombment, but there's" << std::endl;
					std::cout << "nothing you can do now. With your body unable to" << std::endl;
					std::cout << "move, the cold takes you over, freezing limbs to the" << std::endl;
					std::cout << "bone. Your thoughts quickly grow hazy now, and yet" << std::endl;
					std::cout << "but for a brief moment you swear it's getting warmer" << std::endl;
					std::cout << "in here. Sadly, that was your last thought. Your dead" << std::endl;
					std::cout << "body joins the rest of the \"statues\" in their" << std::endl;
					std::cout << "eternal grave." << std::endl << std::endl;

					return 2;
				}

				pause();


			}

			//The player has the torch.
			else { 
				system(CLEAR_SCREEN);
				std::cout << "Looking at the frozen corpses reminds you that" << std::endl;
				std::cout << "you're lucky to have survived this encounter." << std::endl;
				std::cout << "You can only hope that you can find a good use" << std::endl;
				std::cout << "for the Frost Dagger you now posess. This room" << std::endl;
				std::cout << "is too cool to stay in much longer, even with" << std::endl;
				std::cout << "your Torch." << std::endl << std::endl;

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










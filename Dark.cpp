/****************************************************************************************
* Class name: Dark.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: The dark room for the game, derived from Space base class
****************************************************************************************/

#include "Dark.hpp"

// constructor set access to the player object and sets bool complete to false
Dark::Dark(Player *p)
{
	setPlayer(p);
	setComplete(false);
}

// default destructor
Dark::~Dark()
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
int Dark::special()
{
	// room description
	system(CLEAR_SCREEN);
	// if not completed
	if (!complete){
		//  has the torch
		if (player->getTorchEquiped()){
			std::cout << "Entering the room, the flame of your Torch seems" << std::endl;
			std::cout << "engaged in a shoving match with the darkness." << std::endl;
			std::cout << "You can see, but only about eight feet in front" << std::endl;
			std::cout << "of you. You do not feel safe here at all." << std::endl << std::endl;
		}

		// no torch
		else{
			std::cout << "Entering the room feels as though you came upon" << std::endl;
			std::cout << "the divide between existence and nothingness." << std::endl;
			std::cout << "What little light is behind you is swallowed" << std::endl;
			std::cout << "whole by the darkness just inches in front" << std::endl;
			std::cout << "of your face. You whole body is telling you to" << std::endl;
			std::cout << "leave this place." << std::endl << std::endl;

		}
	}
	// if completed
	else{
		std::cout << "Re-entering the dark room you wave your Torch around" << std::endl;
		std::cout << "and see the shatterd bits of the Serpent. Oddly" << std::endl;
		std::cout << "enough the shards do not thaw. What the Dagger did" << std::endl;
		std::cout << "appears to be rather permanent. Better him than me" << std::endl;
		std::cout << "you think to yourself." << std::endl << std::endl;
	}

	// if there are items on the floor, print them
	if (!floor.empty()){
		printFloor();
		std::cout << std::endl << std::endl;
	}

	do{
		// room options
		std::cout << " [1] - Step forward" << std::endl;
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


		// enter the darkness
		if (choice == 1){
			//do they have the key?
			if (!complete){
				system(CLEAR_SCREEN);
				// has both dagger and torch equiped
				if ((player->getTorchEquiped()) && (player->getDaggerEquiped())) {
					std::cout << "You cautiously step into the room. As you look down" << std::endl;
					std::cout << "you can just make out what appear to be bones. You" << std::endl;
					std::cout << "try your best to avoid them, but they're covering" << std::endl;
					std::cout << "the whole floor and you kick into a small pile." << std::endl;
					std::cout << "You pause, and that is when you hear it. A quiet but" << std::endl;
					std::cout << "audible hissing sound. You ready your Dagger and" << std::endl;
					std::cout << "thrust your Torch ahead of you, increasing your" << std::endl;
					std::cout << "visable range. Out of the darkness you see the head" << std::endl;
					std::cout << "of a Serpent! Its eyes piercing red with hate, it is" << std::endl;
					std::cout << "locked on to your position. In desperation you swing" << std::endl;
					std::cout << "your Torch at it, momentarily pausing its approach." << std::endl;
					std::cout << "But the Serpent is hungry and continues to persue" << std::endl;
					std::cout << "you as you stumble backwards towards the exit. Just" << std::endl;
					std::cout << "then the Serpent lunges at you, catching a mouth-" << std::endl;
					std::cout << "full of your torch. The serpent shrieks and pulls" << std::endl;
					std::cout << "its head back exposing its underside. Out of" << std::endl;
					std::cout << "options, you dive forward with Dagger in hand. To" << std::endl;
					std::cout << "your amazement the Dagger pierces the scales of the" << std::endl;
					std::cout << "Serpent just where skull meets neck. The Serpent" << std::endl;
					std::cout << "pull violently back, taking your Dagger with it. But" << std::endl;
					std::cout << "the damage is done and the Serpent begins to freeze" << std::endl;
					std::cout << "over. Its body shudders and cracks as it solidifies" << std::endl;
					std::cout << "in an icy death. The Serpent holds there for but a" << std::endl;
					std::cout << "moment before crashing to the floor, shattering in to" << std::endl;
					std::cout << "hundreds of pieces. Still unnerved, you pick up your" << std::endl;
					std::cout << "Dagger. Waving your Torch around the room for other" << std::endl;
					std::cout << "dangers, you finally notice an objet glinting on the" << std::endl;
					std::cout << "back wall. Approaching it you see that it is in fact" << std::endl;
					std::cout << "a key. The base is a gem encrusted skull with the arm" << std::endl;
					std::cout << "of the key extending out from the skulls mouth. What" << std::endl;
					std::cout << "isn't gem covered appears to be made of pure gold." << std::endl;
					std::cout << "Whatever this key unlocks is sure to be worth" << std::endl;
					std::cout << "something. You put the Skull Key securly in to your" << std::endl;
					std::cout << "Ruck Sack." << std::endl << std::endl;


					checkPackFull();
					player->add2Pack("Key");
					player->setHasKey(true);
					complete = true;
					pause();

				}

				// no torch but has dagger
				// not a possible logic path because the torch can't be unequiped
				// and you must have equiped the torch to get the dagger, but keeping
				// for possible later use.
				else if ((!player->getTorchEquiped()) && (player->getDaggerEquiped())){
					std::cout << "You step forward and the darkness encroaches upon" << std::endl;
					std::cout << "you. Another step forward and your foot crashes" << std::endl;
					std::cout << "into what sounds like dried sticks. That sound" << std::endl;
					std::cout << "fades and the remaining silence is deafening." << std::endl;
					std::cout << "You inch forward only to stop dead in" << std::endl;
					std::cout << "your tracks. It was faint, but you heard it; a" << std::endl;
					std::cout << "distinct hissing sound. You freeze with fear," << std::endl;
					std::cout << "unable to run away or prepare to fight. The black" << std::endl;
					std::cout << "of the room hugs you like a wet blanket, blinding" << std::endl;
					std::cout << "you to your steadily approaching doom. It doesn't" << std::endl;
					std::cout << "take long. Seemingly out of nowhere you feel a" << std::endl;
					std::cout << "sharp pain, as though you had been stabbed with" << std::endl;
					std::cout << "knives. You swing your Dagger, blindly. But nothing" << std::endl;
					std::cout << "can be done. The sharp pain gives way to an intense" << std::endl;
					std::cout << "burning sensation. As though a fire was spreading" << std::endl;
					std::cout << "across your body, you drop to the floor, desperate" << std::endl;
					std::cout << "to escape what is quickly becoming an overwhealming" << std::endl;
					std::cout << "sensation. Your heart is pounding and sweat begins to" << std::endl;
					std::cout << "pour out of your body. You feel your consciousness" << std::endl;
					std::cout << "fade as the poison begins to digest your muscles and" << std::endl;
					std::cout << "organs from the inside. All turns black and still." << std::endl;
					std::cout << "After waiting a few minutes the serpent begins to" << std::endl;
					std::cout << "swallow your lifeless corpse, head first."
						      << std::endl << std::endl;
					
					return 2;
				}


				// has torch equiped but not dagger 
				else if ((player->getTorchEquiped()) && (!player->getDaggerEquiped())){
					std::cout << "You cautiously step into the room. As you look down" << std::endl;
					std::cout << "you can just make out what appear to be bones. You" << std::endl;
					std::cout << "try your best to avoid them, but they're covering" << std::endl;
					std::cout << "the whole floor and you kick into a small pile." << std::endl;
					std::cout << "You pause and that is when you hear it. A quiet but" << std::endl;
					std::cout << "audible hissing sound. You ready your Sword and" << std::endl;
					std::cout << "thrust your Torch ahead of you, increasing your" << std::endl;
					std::cout << "visable range. Out of the darkness you see the head" << std::endl;
					std::cout << "of a Serpent! Its eyes piercing red with hate, it is" << std::endl;
					std::cout << "locked on to your position. In desperation you swing" << std::endl;
					std::cout << "your Torch at it, momentarily pausing its approach." << std::endl;
					std::cout << "But the Serpent is hungry and continues to persue" << std::endl;
					std::cout << "you as you stumble backwards towards the exit. Just" << std::endl;
					std::cout << "then the Serpent lunges at you, catching a mouth-" << std::endl;
					std::cout << "full of your torch. The serpent shrieks and pulls" << std::endl;
					std::cout << "its head back exposing its underside. This is your" << std::endl;
					std::cout << "chance to strike! You arc your sword through the" << std::endl;
					std::cout << "air, striking the Serpent just below where the head" << std::endl;
					std::cout << "meets the neck. All hope is abandoned as you watch" << std::endl;
					std::cout << "your sword fail to penetrate the thick scales of the" << std::endl;
					std::cout << "Serpent. The beast rises above you, mockingly. It" << std::endl;
					std::cout << "pauses long enough for you to think of your wife" << std::endl;
					std::cout << "back at home. In the blink of an eye the Serpent" << std::endl;
					std::cout << "comes down on you, biting your torso. You feel a" << std::endl;
					std::cout << "sharp pain, as though you had been stabbed with" << std::endl;
					std::cout << "knives. You swing your sword, wildly. But nothing" << std::endl;
					std::cout << "can be done. The sharp pain gives way to an intense" << std::endl;
					std::cout << "burning sensation. As though a fire was spreading" << std::endl;
					std::cout << "across your body, you drop to the floor, desperate" << std::endl;
					std::cout << "to escape what is quickly becoming an overwhealming" << std::endl;
					std::cout << "sensation. Your heart is pounding and sweat begins to" << std::endl;
					std::cout << "pour out of your body. You feel your consciousness" << std::endl;
					std::cout << "fade as the poison begins to digest your muscles and" << std::endl;
					std::cout << "organs from the inside. All turns black and still." << std::endl;
					std::cout << "After waiting a few minutes the serpent begins to" << std::endl;
					std::cout << "swallow your lifeless corpse, head first."
						      << std::endl << std::endl;

					return 2;
				}

				// the player has neither dagger or torch
				else if ((!player->getTorchEquiped()) && (!player->getDaggerEquiped())){
					std::cout << "You step forward and the darkness encroaches upon" << std::endl;
					std::cout << "you. Another step forward and your foot crashes" << std::endl;
					std::cout << "into what sounds like dried sticks. That sound" << std::endl;
					std::cout << "fades and the remaining silence is deafening." << std::endl;
					std::cout << "You inch forward only to stop dead in" << std::endl;
					std::cout << "your tracks. It was faint, but you heard it; a" << std::endl;
					std::cout << "distinct hissing sound. You freeze with fear," << std::endl;
					std::cout << "unable to run away or prepare to fight. The black" << std::endl;
					std::cout << "of the room hugs you like a wet blanket, blinding" << std::endl;
					std::cout << "you to your steadily approaching doom. It doesn't" << std::endl;
					std::cout << "take long. Seemingly out of nowhere you feel a" << std::endl;
					std::cout << "sharp pain, as though you had been stabbed with" << std::endl;
					std::cout << "knives. You swing your Sword, blindly. But nothing" << std::endl;
					std::cout << "can be done. The sharp pain gives way to an intense" << std::endl;
					std::cout << "burning sensation. As though a fire was spreading" << std::endl;
					std::cout << "across your body, you drop to the floor, desperate" << std::endl;
					std::cout << "to escape what is quickly becoming an overwhealming" << std::endl;
					std::cout << "sensation. You heart is pounding and sweat begins to" << std::endl;
					std::cout << "pour out of your body. You feel your consciousness" << std::endl;
					std::cout << "fade as the poison begins to digest your muscles and" << std::endl;
					std::cout << "organs from the inside. All turns black and still." << std::endl;
					std::cout << "After waiting a few minutes the serpent begins to" << std::endl;
					std::cout << "swallow your lifeless corpse, head first."
						      << std::endl << std::endl;

					return 2;
				}
			}

			//The player has the torch.
			else { 
				system(CLEAR_SCREEN);
				std::cout << "You're glad to have defeated the serpent, but" << std::endl;
				std::cout << "you fear your dreams will forever by haunted by" << std::endl;
				std::cout << "the ordeal. Your only solace is the possibility" << std::endl;
				std::cout << "that the Skull Key may open up the path to" << std::endl;
				std::cout << "something of immense value. But even then, this" << std::endl;
				std::cout << "is a heavy price to pay." << std::endl << std::endl;

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







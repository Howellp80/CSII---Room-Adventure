/****************************************************************************************
** Program Filename: Main.cpp
** Author: Parker Howell
** Date: 3-15-16
** Description: Main menu either starts the game, shows the game hints, or exits
****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Game.hpp"

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

int main(){

	int choice;       // how many fighters are on each team, or to exit 

	do
	{
		// main menu
		system(CLEAR_SCREEN);
		std::cout << "Welcome to your adventure!" << std::endl;
		std::cout << "Please select 1 - 3." << std::endl << std::endl;
		std::cout << " [1] - Play" << std::endl;
		std::cout << " [2] - Show Spoiler" << std::endl;
		std::cout << " [3] - EXIT" << std::endl;
		std::cin >> choice;

		// validate choice
		while (choice < 1 || choice > 3){
			std::cout << "Please enter a value between 1 and 3." << std::endl;
			std::cin >> choice;
		}

		// if the user didn't exit
		if (choice != 3){

			// did the user want to play the game?
			if (choice == 1){

				// create a game and run it
				Game myGame;
				myGame.init();
				myGame.play();
			}

			// did the user want to see the Spoiler?
			else { // (choice == 2)
				system(CLEAR_SCREEN);
				std::cout << "To beat the game the player must first go" << std::endl;
				std::cout << "into the waterfall room. There they should" << std::endl;
				std::cout << "find the Crystal Phial behind the waterfall." << std::endl;
				std::cout << "They should drink the contents." << std::endl;
				std::cout << "Then they need to go to the hot room where" << std::endl;
				std::cout << "they can get the Eternal Torch. Then they " << std::endl;
				std::cout << "should equip the torch and head to the cold" << std::endl;
				std::cout << "room, where they can melt the ice and" << std::endl;
				std::cout << "retrieve the Frost Dagger. They should equip" << std::endl;
				std::cout << "the dagger and then head to the dark room." << std::endl;
				std::cout << "With the torch and dagger both equiped, they" << std::endl;
				std::cout << "can kill the serpent and retrieve the Skull" << std::endl;
				std::cout << "Key. The Skull key should be equiped and used" << std::endl;
				std::cout << "on the sealed door." << std::endl << std::endl;

				std::cout << "Please press \"Enter\" to return to the main menu." 
					      << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
		}

		// did the user exit?
	} while (choice != 3);

	return 0;
}
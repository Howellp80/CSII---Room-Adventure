/****************************************************************************************
* Class name: Game.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Creates the players and the rooms, initializing their values and then
*              handles main gameplay.
****************************************************************************************/

#include "Game.hpp"

// default constructor
Game::Game()
{
}

// destructor deletes player and room objects
Game::~Game()
{
	delete player;
	delete centerRoom;
	delete waterRoom;
	delete hotRoom;
	delete coldRoom;
	delete darkRoom;
}



/****************************************************************************************
* Function name: init()
* Parameters: none
* Description: Dynamically creates player and room objects. Sets the starting player
*              location, and sets turns to zero. Connects each room to the
*              others via pointers.
****************************************************************************************/
void Game::init()
{
	turns = 0;
	player = new Player();
	centerRoom = new Center(player);
	waterRoom = new Water(player);
	hotRoom = new Hot(player);
	coldRoom = new Cold(player);
	darkRoom = new Dark(player);

	// always start here
	player->setLocation(centerRoom);

	// add room pointers for each room...
	centerRoom->setCenRoom(centerRoom);
	centerRoom->setWRoom(waterRoom);
	centerRoom->setHRoom(hotRoom);
	centerRoom->setCRoom(coldRoom);
	centerRoom->setDRoom(darkRoom);
	
	waterRoom->setCenRoom(centerRoom);
	waterRoom->setWRoom(waterRoom);
	waterRoom->setHRoom(hotRoom);
	waterRoom->setCRoom(coldRoom);
	waterRoom->setDRoom(darkRoom);
	
	hotRoom->setCenRoom(centerRoom);
	hotRoom->setWRoom(waterRoom);
	hotRoom->setHRoom(hotRoom);
	hotRoom->setCRoom(coldRoom);
	hotRoom->setDRoom(darkRoom);
	
	coldRoom->setCenRoom(centerRoom);
	coldRoom->setWRoom(waterRoom);
	coldRoom->setHRoom(hotRoom);
	coldRoom->setCRoom(coldRoom);
	coldRoom->setDRoom(darkRoom);
	
	darkRoom->setCenRoom(centerRoom);
	darkRoom->setWRoom(waterRoom);
	darkRoom->setHRoom(hotRoom);
	darkRoom->setCRoom(coldRoom);
	darkRoom->setDRoom(darkRoom);
	}



/****************************************************************************************
* Function name: play()
* Parameters: none
* Description: Primary game loop determines what is done based on a returned gamestate.
*              Prints out game intro text and game ending text. Checks the timer.
****************************************************************************************/
void Game::play()
{
	// intro
	system(CLEAR_SCREEN);
	std::cout << "...about midway down, you notice the fraying quicking." << std::endl;
	std::cout << "Your anchor to the labyrinth above unravelling, you" << std::endl;
	std::cout << "quicken the pace downward. However, the rope gives way," << std::endl;
	std::cout << "and you fall to the floor below, uncerimoniously landing" << std::endl;
	std::cout << "with a thud and clang. You gather yourself, and your" << std::endl;
	std::cout << "things. Nothing is broken except your pride. Well, that" << std::endl;
	std::cout << "and your rope. Any hopes of entering the area unnoticed" << std::endl;
	std::cout << "dashed, you quickly scan the room. Whatever beasts that" << std::endl;
	std::cout << "may be lurking are now very well aware of your presence." << std::endl << std::endl;
	
	std::cout << "Press \"Enter\"." << std::endl;
	std::cin.ignore();
	std::cin.get();

	system(CLEAR_SCREEN);
	std::cout << "Not sensing any imediate threats you look above at the" << std::endl;
	std::cout << "remanents of your rope. It had served you well, but all" << std::endl;
	std::cout << "things come to an end. Perhaps your end shall be here" << std::endl;
	std::cout << "too, you think. You quickly steel yourself against such" << std::endl;
	std::cout << "thoughts. No, there is a way out, but you must go" << std::endl;
	std::cout << "forward. You may survive this adventure yet, and who" << std::endl;
	std::cout << "knows, you might even find the fabled treasure of the" << std::endl;
	std::cout << "Altean Empire in the process." << std::endl;
	std::cout << "Composed, you take a better look at your surroundings." << std::endl << std::endl;

	std::cout << "Press \"Enter\"." << std::endl;
	std::cin.get();

	// game loop check on returned player state after calling a rooms special function
	do{
		// gives the player a hint if they're taking a long time
		turns++;
		checkTimer();

		// runs special function of the room that the player is in
		playerState = player->getLocation()->special();

	// if the player is alive and going to the next room
	} while (playerState == 1);

	// if the player died
	if (playerState == 2){
		std::cout << "Perhaps the next adventurer will have better fortunes." 
			      << std::endl;

		std::cin.ignore();
	}

	// if the player won the game
	else{ // (playerState ==3)
		system(CLEAR_SCREEN);
		std::cout << "Congratulations, you've won the game!" << std::endl;
		std::cout << "Your constitution was tested, your reflexes challenged," 
			<< std::endl;
		std::cout << "and you faced many a dangerous foe." << std::endl;
		std::cout << "But today you stand victorious, and your rewards shall" 
			      << std::endl;
		std::cout << "last you and your lineage many lifetimes." << std::endl;
		std::cout << "Rest easy, good Sir. For now your biggest challenge " << std::endl;
		std::cout << "is how to carry all of these riches home." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Please press \"Enter\" to return to the main menu." << std::endl;
	std::cin.get();
}



/****************************************************************************************
* Function name: checkTimer()
* Parameters: none
* Description: Checks on the players progress and periodically offers up hints so the
*              player can complete the game if they're having difficulty.
****************************************************************************************/
void Game::checkTimer()
{
	// if player has zero items 
	// and its been 5 or more turns
	if ((!player->getHasPhial()) && (!player->getHasTorch()) && (!player->getHasDagger()) && (!player->getHasKey())){
		if ((turns >= 5) && (turns % 5 == 0)){
			std::cout << "You have a sudden thought that the next item you" << std::endl;
			std::cout << "seek might be in the Water room." << std::endl << std::endl;

			std::cout << "Press \"Enter\"." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}

	// if the player only has had the phial 
	// and its been 10 or more turns
	else if ((player->getHasPhial()) && ((!player->getHasTorch()) && (!player->getHasDagger()) && (!player->getHasKey()))){
		if ((turns >= 10) && (turns % 5 == 0)){
			std::cout << "You have a sudden thought that the next item you" << std::endl;
			std::cout << "seek might be in the Hot room." << std::endl << std::endl;

			std::cout << "Press \"Enter\"." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}

	// if the player has had the phial and the torch 
	// and its been 15 or more turns
	else if ((player->getHasPhial()) && (player->getHasTorch()) && ((!player->getHasDagger()) && (!player->getHasKey()))){
		if ((turns >= 15) && (turns % 5 == 0)){
			std::cout << "You have a sudden thought that the next item you" << std::endl;
			std::cout << "seek might be in the Cold room." << std::endl << std::endl;

			std::cout << "Press \"Enter\"." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}

	// if the player has had the phial and the torch and the dagger 
	// and its been 20 or more turns
	else if ((player->getHasPhial()) && (player->getHasTorch()) && (player->getHasDagger()) && (!player->getHasKey())){
		if ((turns >= 20) && (turns % 5 == 0)){
			std::cout << "You have a sudden thought that the next item you" << std::endl;
			std::cout << "seek might be in the Dark room." << std::endl << std::endl;

			std::cout << "Press \"Enter\"." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}

	// if the player has had the phial and the torch and the dagger and the key
	// and its been 25 or more turns
	else if ((player->getHasPhial()) && (player->getHasTorch()) && (player->getHasDagger()) && (player->getHasKey())){
		if ((turns >= 25) && (turns % 5 == 0)){
			std::cout << "You have a sudden thought that the next item you" << std::endl;
			std::cout << "seek might be in the Center room." << std::endl << std::endl;

			std::cout << "Press \"Enter\"." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
	}
}
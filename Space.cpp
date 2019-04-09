/****************************************************************************************
* Class name: Space.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Abstract base class for all of the rooms used in the game.
****************************************************************************************/

#include "Space.hpp"

// default constructor - never used
Space::Space()
{
}

// default destructor - never used
Space::~Space()
{
}



/****************************************************************************************
* Function name: pause()
* Parameters: none
* Description: Pauses the game by asking the user to press enter.
****************************************************************************************/
void Space::pause()
{
	std::cout << "Press \"Enter\"." << std::endl;
	std::cin.ignore();
	std::cin.get();
}



/****************************************************************************************
* Function name: changeRoom()
* Parameters: none
* Description: Prints the available room options and gets the user choice. Bases on the
*              choice, the players location is changed.
****************************************************************************************/
void Space::changeRoom()
{
	// get players current location
	Space * playerLoc = player->getLocation();
	
	std::cout << "Please select the room you want to go to." << std::endl;
	
	// print out the rooms the player isn't currently in
	if (playerLoc != cenRoom)
		std::cout << " [1] - The Center Room with the Sealed Door." << std::endl;
	if (playerLoc != wRoom)
		std::cout << " [2] - The Water Room." << std::endl;
	if (playerLoc != hRoom)
		std::cout << " [3] - The Hot Room." << std::endl;
	if (playerLoc != cRoom)
		std::cout << " [4] - The Cold Room." << std::endl;
	if (playerLoc != dRoom)
		std::cout << " [5] - The Dark Room." << std::endl;
	std::cin >> choice;

	// validate choice excluding the room currently occupied
	// if in center room
	if (playerLoc == cenRoom){
		while (choice < 2 || choice > 5){
			std::cout << "Please choose 2 - 5" << std::endl;
			std::cin >> choice;
		}
	}
	// if in water room
	if (playerLoc == wRoom){
		while ((choice < 1 || choice > 5) || choice == 2){
			std::cout << "Please choose either 1, 3, 4, or 5" << std::endl;
			std::cin >> choice;
		}
	}
	// if in hot room
	if (playerLoc == hRoom){
		while ((choice < 1 || choice > 5) || choice == 3){
			std::cout << "Please choose either 1, 2, 4, or 5" << std::endl;
			std::cin >> choice;
		}
	}	
	// if in cold room
	if (playerLoc == cRoom){
		while ((choice < 1 || choice > 5) || choice == 4){
			std::cout << "Please choose either 1, 2, 3, or 5" << std::endl;
			std::cin >> choice;
		}
	}
	// if in dark room
	if (playerLoc == dRoom){
		while (choice < 1 || choice > 4){
			std::cout << "Please choose 1 - 4" << std::endl;
			std::cin >> choice;
		}
	}

	//adjust player location based on room selected
	if (choice == 1)
		player->setLocation(cenRoom);
	else if (choice == 2)
		player->setLocation(wRoom);
	else if (choice == 3)
		player->setLocation(hRoom);
	else if (choice == 4)
		player->setLocation(cRoom);
	else // (choice == 5)
		player->setLocation(dRoom);
}



/****************************************************************************************
* Function name: itemManip()
* Parameters: none
* Description: Handles the player equiping/using items. Calls players printPack function
*              and gets the item to equip/use from the backpack. At the same time it puts
*              currently equiped items back into the backpack if necessary.
****************************************************************************************/
void Space::itemManip()
{
	int itemChoice;
	int items = player->printPack();
	if (items != -1){
		std::cin >> itemChoice;

		//validate choice
		while (itemChoice < 1 || itemChoice > items){
			std::cout << "Please choose between 1 - " << items << "."
				<< std::endl;
			std::cin >> itemChoice;
		}

		// if the player equipes/uses the sword
		if (player->getItemAt(itemChoice - 1) == "Sword"){
			system(CLEAR_SCREEN);
			if (!player->getKeyEquiped()){
				std::cout << "You put your dagger back into your" << std::endl;
				std::cout << "Ruck Sack and remove your sword." << std::endl;
				std::cout << "It's not as easy to handle, but it's" << std::endl;
				std::cout << "better than being unarmed." << std::endl << std::endl;

				player->setDaggerEquiped(false);
				player->add2Pack("Dagger");
				player->setSwordEquiped(true);
				player->remFromPack(itemChoice - 1);
			}

			else{ // the key is equiped
				std::cout << "Perhaps you should see where the key" << std::endl;
				std::cout << "is used before putting it away." << std::endl << std::endl;
			}
		}


		// if the player equipes/uses the phial
		else if (player->getItemAt(itemChoice - 1) == "Phial"){
			system(CLEAR_SCREEN);
			std::cout << "You remove the Crystal Phial form your" << std::endl;
			std::cout << "sack and instantly your hand feels a" << std::endl;
			std::cout << "slight chill. You pop the top and sip" << std::endl;
			std::cout << "from the contents. You put the Crystal" << std::endl;
			std::cout << "Phial back into your Ruck Sack and" << std::endl;
			std::cout << "notice that your body begins to cool." << std::endl;
			std::cout << "You feel as though you could walk" << std::endl;
			std::cout << "through a fire unscathed." << std::endl << std::endl;

			player->setPhialEquiped(true);
		}


		// if the player equipes/uses the torch
		else if (player->getItemAt(itemChoice - 1) == "Torch"){
			system(CLEAR_SCREEN);
			std::cout << "You remove the Eternal Torch from your" << std::endl;
			std::cout << "Ruck Sack and are amused as its flame" << std::endl;
			std::cout << "sparks to life, filling the surrounding" << std::endl;
			std::cout << "area with light. This torch has a" << std::endl;
			std::cout << "different kind of heat coming off of" << std::endl;
			std::cout << "it. It feels somehow warmer than" << std::endl;
			std::cout << "normal, but it doesn't seem to burn." << std::endl << std::endl;

			player->setTorchEquiped(true);
			player->remFromPack(itemChoice - 1);

			// if also using the sword
			if (player->getSwordEquiped() == true){
				std::cout << "Handling both your torch and sword" << std::endl;
				std::cout << "is a bit awkward, but managable." << std::endl;
				std::cout << "Perhaps you can find a lighter" << std::endl;
				std::cout << "weapon to wield." << std::endl << std::endl;
			}
		}


		// if the player equipes/uses the dagger
		else if (player->getItemAt(itemChoice - 1) == "Dagger"){
			system(CLEAR_SCREEN);
			if (!player->getKeyEquiped()){
				std::cout << "You secure your sword to your Ruck Sack." << std::endl;
				std::cout << "Removing the dagger you can't help but" << std::endl;
				std::cout << "notice how well it balances with the" << std::endl;
				std::cout << "torch." << std::endl << std::endl;

				player->setSwordEquiped(false);
				player->remFromPack(itemChoice - 1);
				player->add2Pack("Sword");
				player->setDaggerEquiped(true);
			}

			else{ // the key is equiped
				std::cout << "Perhaps you should see where the key" << std::endl;
				std::cout << "is used before putting it away." << std::endl << std::endl;
			}
		}


		// if the player equipes the key
		else if (player->getItemAt(itemChoice - 1) == "Key"){
			system(CLEAR_SCREEN);
			// if using the dagger
			if (player->getDaggerEquiped()){
				std::cout << "You put away your Dagger and remove" << std::endl;
				std::cout << "the Skull Key from your Ruck Sack." << std::endl;
				std::cout << "It's a fine key, and probably guards" << std::endl;
				std::cout << "something of value." << std::endl << std::endl;

				player->setDaggerEquiped(false);
				player->remFromPack(itemChoice - 1);
				player->add2Pack("Dagger");
				player->setKeyEquiped(true);
			}

			// if using the sword
			else if (player->getSwordEquiped()){
				std::cout << "You put away your Sword and remove" << std::endl;
				std::cout << "the Skull Key from your Ruck Sack." << std::endl;
				std::cout << "It's a fine key, and probably guards" << std::endl;
				std::cout << "something of value." << std::endl << std::endl;

				player->setSwordEquiped(false);
				player->remFromPack(itemChoice - 1);
				player->add2Pack("Sword");
				player->setKeyEquiped(true);
			}
		}
	}
}



/****************************************************************************************
* Function name: itemPickup()
* Parameters: none
* Description: Displays the items on the floor in the current room. The user then selects
*              the one they would like to add to their backpack. Checks backpack for
*              room and adds item, or asks you to make room in the backpack, and then
*              adds the item. Removes the item from the floor.
****************************************************************************************/
void Space::itemPickup()
{
	int floorItem;

	// print items on the floor
	int items = printFloorPickup();
	
	std::cin >> floorItem;

	while (floorItem < 1 || floorItem > items){
		std::cout << "Please select 1 - " << items << std::endl;
		std::cin >> floorItem;
	}

	//see if backpack has room
	checkPackFull();

	std::cout << "You pick up the " << floor[floorItem - 1]
		<< " and put it in your Ruck Sack." << std::endl << std::endl;

	player->add2Pack(floor[floorItem - 1]);
	removeFromFloor(floorItem - 1);
}



/****************************************************************************************
* Function name: printFloorPickup()
* Parameters: none
* Description: Numbers and prints out all of the items on a rooms floor. Used in
*              itemPickup function. Returns the number of items printed out.
****************************************************************************************/
int Space::printFloorPickup()
{
	unsigned int i;
	for (i = 0; i < floor.size(); i++)
		std::cout << " [" << i + 1 << "] - " << floor[i] << std::endl;
	return i;
}



/****************************************************************************************
* Function name: printFloor()
* Parameters: none
* Description: Used to display the items on the floor when a player enters a room.
****************************************************************************************/
void Space::printFloor()
{
	std::cout << "Item(s) on the floor:" << std::endl;
	unsigned int i;
	for (i = 0; i < floor.size(); i++)
		std::cout << floor[i] << std::endl;
}



/****************************************************************************************
* Function name: checkPackFull()
* Parameters: none
* Description: If the backpack is full asks user to remove an item. The removed item
*              is added to the floor of the player occupied room.
****************************************************************************************/
void Space::checkPackFull()
{
	int remove;
	// if the pack is full
	if (player->getItemsInPack() == player->getPackSize()){
		std::cout << "Your Ruck Sack, filled with basic survival items" << std::endl;
		std::cout << "and other necessities, can only hold " << player->getPackSize()
			      << " additional item(s)." << std::endl;
		std::cout << "You'll have to remove an item first. This item will" << std::endl;
		std::cout << "be left on the floor of the room you're in." << std::endl << std::endl;

		int numOfItems = player->printPack();

		std::cin >> remove;

		// validate remove
		while (remove < 1 || remove > numOfItems){
			std::cout << "Please select 1 - " << numOfItems << std::endl;
			std::cin >> remove;
		}

		std::cout << "You set the " << player->getItemAt(remove - 1) << " on the floor."
			      << std::endl;

		add2Floor(player->getItemAt(remove - 1));
		player->remFromPack(remove - 1);
	}
}



/****************************************************************************************
* Function name: add2Floor(std::string)
* Parameters: string - name of item to be added to current room floor.
* Description: Adds an item with the value of the string argument to the floor.
****************************************************************************************/
void Space::add2Floor(std::string it)
{
	floor.push_back(it);
}



/****************************************************************************************
* Function name: removeFromFloor(int)
* Parameters: int - represents the index of the floor vector - 0 is first item.
* Description: Removes an item from the floor vector at the index passed in.
****************************************************************************************/
void Space::removeFromFloor(int ind)
{
	floor.erase((floor.begin()) + ind);
}





// getters

bool Space::getComplete()
{
	return complete;
}




// setters

void Space::setComplete(bool comp)
{
	this->complete = comp;
}

void Space::setCenRoom(Space *cen)
{
	this->cenRoom = cen;
}

void Space::setWRoom(Space *wat)
{
	this->wRoom = wat;
}

void Space::setHRoom(Space *hot)
{
	this->hRoom = hot;
}

void Space::setCRoom(Space * cold)
{
	this->cRoom = cold;
}

void Space::setDRoom(Space *dark)
{
	this->dRoom = dark;
}

void Space::setPlayer(Player * p)
{
	this->player = p;
}











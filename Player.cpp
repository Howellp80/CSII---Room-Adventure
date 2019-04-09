/****************************************************************************************
* Class name: Player.cpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Creates a player object with a backpack for item storage, a location
*              pointer, and some booleans to track item progress/use.
****************************************************************************************/

#include "Player.hpp"
#include "Space.hpp"

// constructor sets starting bools
Player::Player()
{
	setSwordEquiped(true);
	setPhialEquiped(false);
	setTorchEquiped(false);
	setDaggerEquiped(false);
	setKeyEquiped(false);

	setHasPhial(false);
	setHasTorch(false);
	setHasDagger(false);
	setHasKey(false);
}

// default destructor
Player::~Player()
{
}



/****************************************************************************************
* Function name: add2Pack(std::string)
* Parameters: string - name of the item to be added
* Description: Adds an item to the backpack vector with value of the string passed in.
****************************************************************************************/
void Player::add2Pack(std::string item)
{
	backpack.push_back(item);
}



/****************************************************************************************
* Function name: remFromPack(int)
* Parameters: int - represents the index of the backpack vector - 0 is first item.
* Description: Removes an item from the backpack vector at the index passed in.
****************************************************************************************/
void Player::remFromPack(int ind)
{
	backpack.erase((backpack.begin()) + ind);
}



/****************************************************************************************
* Function name: printPack()
* Parameters: none
* Description: If the pack has items they are numbered and printed to the console. The
*              number of items printed is returned as an int. If the pack is empty, a
*              message is printed and -1 is returned.
****************************************************************************************/
int Player::printPack()
{
	// if there is something in the pack
	if (!backpack.empty()){
		unsigned int i;
		for (i = 0; i < backpack.size(); i++){
			std::cout << " [" << i + 1 << "] - " << backpack[i] << std::endl;
		}
		return  i;
	}

	else { // backpack is empty
		system(CLEAR_SCREEN);
		std::cout << "Your Ruck Sack has a lot of useful items, like your sleeping bag," << std::endl;
		std::cout << "and food and water, but nothing specific to this particular quest." 
			      << std::endl << std::endl;
		return -1;
	}

}




// getters

// returns the name of the item in backpack
std::string Player::getItemAt(int ind)
{
	return backpack[ind];
}

// returns what room the player is in
Space * Player::getLocation()
{
	return location;
}

// returns how many items the backpack can hold
int Player::getPackSize()
{
	return PACKSIZE;
}

// returns how many items are currently in the packpack
int Player::getItemsInPack()
{
	return backpack.size();
}


bool Player::getSwordEquiped()
{
	return swordEquiped;
}

bool Player::getPhialEquiped()
{
	return phialEquiped;
}

bool Player::getTorchEquiped()
{
	return torchEquiped;
}

bool Player::getDaggerEquiped()
{
	return daggerEquiped;
}

bool Player::getKeyEquiped()
{
	return keyEquiped;
}

bool Player::getHasPhial()
{
	return hasPhial;
}

bool Player::getHasTorch()
{
	return hasTorch;
}

bool Player::getHasDagger()
{
	return hasDagger;
}

bool Player::getHasKey()
{
	return hasKey;
}




// setters

// changes the players location to passed in argument
void Player::setLocation(Space * loc)
{
	this->location = loc;
}


void Player::setSwordEquiped(bool sw)
{
	this->swordEquiped = sw;
}

void Player::setPhialEquiped(bool pe)
{
	this->phialEquiped = pe;
}

void Player::setTorchEquiped(bool te)
{
	this->torchEquiped = te;
}

void Player::setDaggerEquiped(bool de)
{
	this->daggerEquiped = de;
}

void Player::setKeyEquiped(bool ke)
{
	this->keyEquiped = ke;
}

void Player::setHasKey(bool k)
{
	this->hasKey = k;
}

void Player::setHasPhial(bool p)
{
	this->hasPhial = p;
}

void Player::setHasTorch(bool t)
{
	this->hasTorch = t;
}

void Player::setHasDagger(bool d)
{
	this->hasDagger = d;
}









/****************************************************************************************
* Class name: Player.hpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Creates a player object with a backpack for item storage, a location
*              pointer, and some booleans to track item progress/use.
****************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

#define PACKSIZE 1   // maximum number of items the pack can store

class Space;       // forward declaration because Space has a player too

class Player
{
private:
	std::vector<std::string> backpack;   // Ruck Sack for item storage
	Space * location;                    // which room the player is in

	bool swordEquiped,        // user holding the sword? starting item
		hasPhial,             // did user get the phial? true even if item dropped
		phialEquiped,         // user holding the phial?
		hasTorch,             // did user get the torch? true even if item dropped
		torchEquiped,         // user holding the torch?
	    hasDagger,            // did user get the dagger? true even if item dropped
		daggerEquiped,        // user holding the dagger?
		hasKey,               // did user get the key? true even if item dropped
		keyEquiped;           // user holding the key?


public:
	// constructor sets starting bools
	Player();

	// default destructor
	~Player();



	/****************************************************************************************
	* Function name: add2Pack(std::string)
	* Parameters: string - name of the item to be added
	* Description: Adds an item to the backpack vector with value of the string passed in.
	****************************************************************************************/
	void add2Pack(std::string);
	
	
	
	/****************************************************************************************
	* Function name: remFromPack(int)
	* Parameters: int - represents the index of the backpack vector - 0 is first item.
	* Description: Removes an item from the backpack vector at the index passed in.
	****************************************************************************************/
	void remFromPack(int);
	

	
	/****************************************************************************************
	* Function name: printPack()
	* Parameters: none
	* Description: If the pack has items they are numbered and printed to the console. The 
	*              number of items printed is returned as an int. If the pack is empty, a 
	*              message is printed and -1 is returned.
	****************************************************************************************/
	int printPack();




	// getters

	// returns the name of the item in backpack
	std::string getItemAt(int);

	// returns what room the player is in
	Space * getLocation();

	// returns how many items the backpack can hold
	int getPackSize();
	
	// returns how many items are currently in the packpack
	int getItemsInPack();

	bool getSwordEquiped();
	bool getPhialEquiped();
	bool getTorchEquiped();
	bool getDaggerEquiped();
	bool getKeyEquiped();
	bool getHasPhial();
	bool getHasTorch();
	bool getHasDagger();
	bool getHasKey();
	

	
	// setters

	// changes the players location to passed in argument
	void setLocation(Space *);
	
	void setSwordEquiped(bool);
	void setPhialEquiped(bool);
	void setTorchEquiped(bool);
	void setDaggerEquiped(bool);
	void setKeyEquiped(bool);
	void setHasKey(bool);
	void setHasPhial(bool);
	void setHasTorch(bool);
	void setHasDagger(bool);

};

#endif
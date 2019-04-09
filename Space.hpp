/****************************************************************************************
* Class name: Space.hpp
* Author: Parker Howell
* Date: 3-15-16
* Description: Abstract base class for all of the rooms used in the game. 
****************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

class Player;        // forward declaration because Player has a Space too

class Space
{
protected:
	bool complete;        // has the goal for the room been reached?
	int choice;           // player entered choice for more than one menu
	std::vector<std::string> floor;    // holds items placed on the floor
	Player * player;      // all rooms have a pointer to the player
	Space * cenRoom,      // all rooms have a pointer to the center room
		  * wRoom,        // all rooms have a pointer to the water room
		  * hRoom,        // all rooms have a pointer to the hot room
		  * cRoom,        // all rooms have a pointer to the cold room
		  * dRoom;        // all rooms have a pointer to the dark room

public:
	// default constructor - never used
	Space();

	// default destructor - never used
	~Space();
	
	// pure virtual function - see derived classes
	virtual int special() = 0;



	/****************************************************************************************
	* Function name: pause()
	* Parameters: none
	* Description: Pauses the game by asking the user to press enter.
	****************************************************************************************/
	void pause();
	
	
	
	/****************************************************************************************
	* Function name: changeRoom()
	* Parameters: none
	* Description: Prints the available room options and gets the user choice. Bases on the 
	*              choice, the players location is changed.
	****************************************************************************************/
	void changeRoom();
	
	
	
	/****************************************************************************************
	* Function name: itemManip()
	* Parameters: none
	* Description: Handles the player equiping/using items. Calls players printPack function  
	*              and gets the item to equip/use from the backpack. At the same time it puts 
	*              currently equiped items back into the backpack if necessary.
	****************************************************************************************/
	void itemManip();
	
	
	
	/****************************************************************************************
	* Function name: itemPickup()
	* Parameters: none
	* Description: Displays the items on the floor in the current room. The user then selects 
	*              the one they would like to add to their backpack. Checks backpack for 
	*              room and adds item, or asks you to make room in the backpack, and then 
	*              adds the item. Removes the item from the floor.
	****************************************************************************************/
	void itemPickup();
	
	
	
	/****************************************************************************************
	* Function name: printFloorPickup()
	* Parameters: none
	* Description: Numbers and prints out all of the items on a rooms floor. Used in 
	*              itemPickup function. Returns the number of items printed out.
	****************************************************************************************/
	int printFloorPickup();
	
	
	
	/****************************************************************************************
	* Function name: printFloor()
	* Parameters: none
	* Description: Used to display the items on the floor when a player enters a room.
	****************************************************************************************/
	void printFloor();
	
	
	
	/****************************************************************************************
	* Function name: checkPackFull()
	* Parameters: none
	* Description: If the backpack is full asks user to remove an item. The removed item
	*              is added to the floor of the player occupied room.
	****************************************************************************************/
	void checkPackFull();
	
	
	
	/****************************************************************************************
	* Function name: add2Floor(std::string)
	* Parameters: string - name of item to be added to current room floor.
	* Description: Adds an item with the value of the string argument to the floor.
	****************************************************************************************/
	void add2Floor(std::string);
	
	
	
	/****************************************************************************************
	* Function name: removeFromFloor(int)
	* Parameters: int - represents the index of the floor vector - 0 is first item.
	* Description: Removes an item from the floor vector at the index passed in.
	****************************************************************************************/
	void removeFromFloor(int);



	//getters
	bool getComplete();



	// setters
	void setComplete(bool);
	void setCenRoom(Space *);
	void setWRoom(Space *);
	void setHRoom(Space *);
	void setCRoom(Space *);
	void setDRoom(Space *);
	void setPlayer(Player *);

};

#endif
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "House.h"
#include "Item.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Weapon;
class Armor;


class Player
{
public:

	Player(short _hp, House& _currentHouse, Room& _currentRoom);
	Player(short _hp, House& _currentHouse, Room& _currentRoom, Weapon& _weapon, Armor& _armor);
	Player();


	void action();

private:

	void goToRoom(short _id);
	void goToFound(short _id);
	void attackMonster();
	void useItem(short _id);

	short request();

	string name;

	short hp;

	Weapon* weapon;
	Armor* armor;

	House* currentHouse;
	Room* currentRoom;

	vector<Item*> inventory;
};


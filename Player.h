#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "House.h"
#include "Item.h"
#include "ItemHeins.h"

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

	Item& operator[](short _id);
	Item& operator[](string _name);


	void changeHp(const short _hp);
	void addItem(Item& item);

	string& getName();
	short getHp();
	short getMaxHp();

	bool searchItem(string& _name);
	void eraseItem(short _id);
	void action();

	bool life = true;

private:

	void goToRoom(short _id);
	void goToFound(short _id);
	void useItem(short _id);
	void openInventory();

	short request();

	string name;

	short maxHp;
	short hp;

	Weapon* weapon;
	Armor* armor;

	House* currentHouse;
	Room* currentRoom;

	vector<Item*> inventory;
};


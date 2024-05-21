#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "printText.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Player;


class Item
{
public:

	Item();
	Item(const Item& other);

	virtual void action();
	virtual void pickup();

	virtual void printData();

	string& getName();
	void setPlayer(Player& _player);

	static Item& getRandom();

	bool erased = false;

	//virtual ~Item() = default;

protected:
	string name;
	string textPickup;
	string textAction;
	Player* player;
	
private:
	
	static vector<Item*> allItem;
	static void initVector();
};

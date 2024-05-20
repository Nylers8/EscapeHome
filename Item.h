#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Item
{
public:

	void action();
	void pickup();

	static Item& getRandom();

	//virtual ~Item() = default;

private:
	string name;

	static std::vector<Item> allItem;
};


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "Found.h"

class House;

 class Room
{
public:
	Room();
	Room(House& _house, string _name);
	Room(House& _house, string _name, std::initializer_list<string> _rooms);


	short getId();
	string getName();

	void addPath(Room& _room);
	void setText(const string& _text);

	bool checkPath(string _name);

	// ¬ыводит доступные пути и места обыска
	void printActions();


private:
	string name;
	short id;

	string text = "";

	House* house;

	vector<std::reference_wrapper<Room>> paths{};
	vector<Found> founds{};

	static short count;
};


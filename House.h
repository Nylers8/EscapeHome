#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "Room.h"

class House
{

public:

	Room& operator[](const short _id);
	Room& operator[](const string _name);


	void addRoom(Room& _room);
	void changeCurrentRoom(Room& _room);

	short getSize();
	Room& getRoom(const short _id);
	Room& getRoom(const string& _name);
	Room& getCurrentRoom();

private:

	vector<std::reference_wrapper<Room>> allRoom{};

	Room* currentRoom;
};


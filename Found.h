#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"

#include "Item.h"
#include "Monster.h"

using std::cout;
using std::endl;
using std::string;

class Found
{
public:

	Found(const string& _name, const string& _textAction);
	Found(const string& _name, const string& _textAction, Item& _item);
	Found(const string& _name, const string& _textAction, Monster& _monster);
	Found(const string& _name, const string& _textAction, Monster& _monster, Item& _item);
	Found(const Found& other);

	Found();

	Found& operator[](short _id);
	Found& operator[](string _name);

	static Found& getFound(short _id);
	static Found& getFound(string _name);
	static Found& getRandomFound();


	string& getName();
	void action();

private:

	void printTextAction();

	string name;
	Monster* monsterptr;
	Item* itemptr;

	string textAction;
	
	static std::vector<Found> varietyFounds;
};


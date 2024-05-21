#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Player;

class Monster
{
public:
	Monster();
	Monster(string _name, string _textAction, short _damage);

	void attack();

	void setPlayer(Player& _player);

	string& getName();

	static Monster& getMonster(short _id);
	static Monster& getMonster(string& _name);
	static Monster& getRandom();

private:
	string name;
	string textAction;
	short damage;

	Player* pl;

	static vector<Monster> allMonster;
	static void initAllMonster();
};


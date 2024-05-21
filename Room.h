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
#include "printText.h"

class House;
class Key;

 class Room
{
public:
	Room();
	Room(House& _house, string _name);
	Room(House& _house, string _name, std::initializer_list<string> _rooms);
	Room(House& _house, string _name, std::initializer_list<string> _rooms, std::initializer_list<Found> _founds, bool _open = true, Key* _keyroom = nullptr, string _textClosed = "");


	short getId();
	string getName();

	Room& getRoomFromPaths(short _id);
	Room& getRoomFromPaths(string _name);
	Found& getFound(short _id);
	Found& getFound(string _name);

	short getSizePaths();
	short getSizeFounds();

	Key& getKey();
	string& getTextClosed();


	void addPath(Room& _room);
	void addPath(std::initializer_list<string> _rooms);
	void setText(const string& _text);

	void foundAction(short _id);

	bool checkPath(string _name);

	// ������� ��������� ���� � ����� ������
	void printActions();

	bool open = true;

private:
	string name;
	string text = "";
	string textClosed;
	short id;


	House* house;
	Key* keyRoom;

	vector<std::reference_wrapper<Room>> paths{};
	vector<Found> founds{};

	static short count;
};


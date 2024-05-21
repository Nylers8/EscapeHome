#include "Room.h"
#include "House.h"
#include "ItemHeins.h"

short Room::count = 0;

Room::Room()
{
	house = nullptr;
	name = "none";
	id = 0;
	paths = {};
	founds = {};
	keyRoom = nullptr;
}

Room::Room(House& _house, string _name)
{
	id = count;
	count++;

	this->name = _name;


	// Случайнные объеты
	short size = rand() % 3;
	for (short i = 0; i < size; i++)
	{
		founds.push_back(Found::getRandomFound());
	}


	house = &_house;
	_house.addRoom(*this);
	keyRoom = nullptr;
}

Room::Room(House& _house, string _name, std::initializer_list<string> _rooms) : Room(_house, _name)
{
	addPath(_rooms);
}

Room::Room(House& _house, string _name, std::initializer_list<string> _rooms, std::initializer_list<Found> _founds, bool _open, Key* _keyRoom, string _textClosed) : Room(_house, _name)
{
	addPath(_rooms);

	founds.clear();
	for (Found f : _founds)
	{
		this->founds.push_back(f);
	}

	this->open = _open;
	keyRoom = _keyRoom;
	textClosed = _textClosed;
}




short Room::getId()
{
	return id;
}

string Room::getName()
{
	return name;
}


Room& Room::getRoomFromPaths(short _id)
{
	short size = paths.size();
	if (size <= 0)
	{
		return *new Room;
	}

	if (_id > size)
	{
		return paths[size - 1];
	}

	return paths[_id];
}

Room& Room::getRoomFromPaths(string _name)
{
	short size = paths.size();
	for (short i = 0; i < size; i++)
	{
		if (paths[i].get().getName() == _name) 
		{
			return paths[i];
		}
	}

	return *new Room;
}

Found& Room::getFound(short _id)
{
	short size = founds.size();
	if (size <= 0)
	{
		return *new Found;
	}

	if (_id > size)
	{
		return founds[size - 1];
	}

	return founds[_id];
}

Found& Room::getFound(string _name)
{
	short size = founds.size();
	for (short i = 0; i < size; i++)
	{
		if (founds[i].getName() == _name)
		{
			return founds[i];
		}
	}

	return *new Found;
}

short Room::getSizePaths()
{
	return paths.size();
}

short Room::getSizeFounds()
{
	return founds.size();
}

Key& Room::getKey()
{
	return *keyRoom;
}

string& Room::getTextClosed()
{
	return textClosed;
}




void Room::addPath(Room& _room)
{
	paths.push_back(_room);
}

void Room::addPath(std::initializer_list<string> _rooms)
{
	for (string r : _rooms)
	{
		paths.push_back((*house)[r]);

		// Ищет тех, в кого может зайти, а они в него не могут
		// Проще говоря, связывает двери, чтобы в неё можно было войти и выйти
		short size = paths.size();
		for (short i = 0; i < size; i++)
		{
			if (!paths[i].get().checkPath(name))
			{
				paths[i].get().addPath(*this);
			}
		}
	}


}

void Room::setText(const string& _text)
{
	this->text = _text;
}

void Room::foundAction(short _id)
{
	if (_id >= founds.size())
		return;
	if (_id < 0)
		return;

	founds[_id].action();

	if (founds.size() == 1)
		founds.clear();
	else
		founds.erase(founds.begin() + _id);
}


bool Room::checkPath(string _name)
{
	if (paths.size() == 0)
		return false;


	for (short i = 0; i < paths.size(); i++)
	{
		if (paths[i].get().getName() == _name)
		{
			return true;
		}
	}

	return false;
}

void Room::printActions()
{
	if (text != "")
	{
		cout << text << endl;
	}
	else
	{
		short randNum = rand() % 4;
		switch (randNum)
		{
		case 0:
		{
			printText("Вы находитесь в \'" + name + '\'');
			break;
		}

		case 1:
		{
			printText("Вы внимательно осмтраиваетесь в \'" + name + '\'');
			break;
		}

		case 2:
		{
			printText("Находясь в \'" + name + "\' вы ощущаете на себе пристальный взгляд..");
			break;
		}

		case 3:
		{
			printText("Вы ощущаете сТрАх, находясь в \'" + name + "\'..");
			break;
		}

		default:
		{
			printText("Вы чувствуете себя хакером.. \'" + name + '\'');
			break;
		}
		}
	}
	cout << endl << endl;

	short size = paths.size();
	short j = 1;
	for (short i = 0; i < size; i++, j++)
	{
		cout << j << " - " << paths[i].get().getName() << endl;
	}
	cout << endl;

	size = founds.size();
	for (short i = 0; i < size; i++, j++)
	{
		cout << j << " - обыскать \'" << founds[i].getName() << '\'' << endl;
	}
	cout << endl << j << " - открыть инвентарь" << endl;
}

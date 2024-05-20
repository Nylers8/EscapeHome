#include "Room.h"
#include "House.h"

short Room::count = 0;

Room::Room()
{
	house = nullptr;
	name = "none";
	id = 0;
	paths = {};
	founds = {};
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
}

Room::Room(House& _house, string _name, std::initializer_list<string> _rooms) : Room(_house, _name)
{
	addPath(_rooms);
}

Room::Room(House& _house, string _name, std::initializer_list<string> _rooms, std::initializer_list<Found> _founds, bool _open) : Room(_house, _name)
{
	addPath(_rooms);

	founds.clear();
	for  (Found f : _founds)
	{
		this->founds.push_back(f);
	}

	this->open = _open;
}


short Room::getId()
{
	return id;
}

string Room::getName()
{
	return name;
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
	cout << "ID:" << id << endl;

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
			cout << "Вы находитесь в \'" << name << '\'' << endl;
			break;
		}

		case 1:
		{
			cout << "Вы внимательно осмтраиваетесь в \'" << name << '\'' << endl;
			break;
		}

		case 2:
		{
			cout << "Находясь в \'" << name << "\' вы ощущаете на себе пристальный взгляд.." << endl;
			break;
		}

		case 3:
		{
			cout << "Вы ощущаете сТрАх, находясь в \'" << name << "\'..";
			break;
		}

		default:
		{
			cout << "Вы чувствуете себя хакером.. \'" << name << '\'' << endl;
			break;
		}
		}
	}
	cout << endl;

	short size = paths.size();
	short j = 1;
	for (short i = 0; i < size; i++, j++)
	{
		cout << j << " - " << paths[i].get().getName() << endl;
	}

	size = founds.size();
	for (short i = 0; i < size; i++, j++)
	{
		cout << j << " - обыскать \'" << founds[i].getName() << '\'' << endl;
	}
}

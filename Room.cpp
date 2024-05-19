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

	// ����� � ���������� � ��������� ���� ���, � ���� ���� ���� � �������
	// ����� ������� ��������� �����/����
	short size = _house.getSize();
	for (short i = 0; i < size; i++)
	{
		if (_house[i].checkPath(name))
		{
			paths.push_back(_house[i]);
		}
	}

	house = &_house;
	_house.addRoom(*this);
}

Room::Room(House& _house, string _name, std::initializer_list<string> _rooms) : Room(_house, _name)
{
	// ��������� �������� ����
	for (string r : _rooms)
	{
		paths.push_back(_house[r]);

		short size = paths.size();
		for (short i = 0; i < size; i++)
		{
			if (!paths[i].get().checkPath(name))
			{
				paths[i].get().addPath(*this);
			}
		}
	}


	// ���������� ������
	//////////////////////////////
	//////////////////////////////

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
			cout << "�� ���������� � \'" << name << '\'' << endl;
			break;
		}

		case 1:
		{
			cout << "�� ����������� �������������� � \'" << name << '\'' << endl;
			break;
		}

		case 2:
		{
			cout << "�������� � \'" << name << "\' �� �������� �� ���� ����������� ������.." << endl;
			break;
		}

		case 3:
		{
			cout << "�� �������� �����, �������� � \'" << name << "\'..";
			break;
		}

		default:
		{
			cout << "�� ���������� ���� �������.. \'" << name << '\'' << endl;
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
		cout << j << " - ��������" << endl;
	}
}

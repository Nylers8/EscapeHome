#include "Found.h"

Found::Found(const string& _name, const string& _textAction)
{
	this->name = _name;
	this->textAction = _textAction;

	monsterptr = &Monster::getRandom();
	itemptr = &Item::getRandom();
}

Found::Found(const string& _name, const string& _textAction, Item& _item) : Found(_name, _textAction)
{
	itemptr = &_item;
}

Found::Found(const string& _name, const string& _textAction, Monster& _monster) : Found(_name, _textAction)
{
	monsterptr = &_monster;
}

Found::Found(const string& _name, const string& _textAction, Monster& _monster, Item& _item) : Found(_name, _textAction)
{
	monsterptr = &_monster;
	itemptr = &_item;
}

Found::Found(const Found& other)
{
	*this = other;
}

Found::Found()
{
	name = "name:none";
	textAction = "action:none";
	monsterptr = nullptr;
	itemptr = nullptr;
}



Found& Found::operator[](short _id)
{
	return getFound(_id);
}

Found& Found::operator[](string _name)
{
	return getFound(_name);
}

Found& Found::getFound(short _id)
{
	short size = varietyFounds.size();
	if (size == 0)
	{
		return *new Found;
	}

	return varietyFounds[_id];
}

Found& Found::getFound(string _name)
{
	short size = varietyFounds.size();
	if (size == 0)
	{
		return *new Found;
	}

	for (short i = 0; i < size; i++)
	{
		if (varietyFounds[i].getName() == _name)
		{
			return varietyFounds[i];
		}
	}

	return *new Found;
}

Found& Found::getRandomFound()
{
	short size = varietyFounds.size();
	if (size == 0)
	{
		return *new Found;
	}

	short randNum = rand() % size;
	return varietyFounds[randNum];
}


string& Found::getName()
{
	return name;
}



void Found::action()
{
	printTextAction();
	itemptr->pickup();

	short randNum = rand() % 10;
	if (!randNum)
	{
		monsterptr->attack();
	}
}

void Found::printTextAction()
{
	short delayBase = 500;
	short delayChar = 40;

	short size = textAction.size();
	short count = 0;

	for (short i = 0; i < size; i++, count++)
	{
		Sleep(delayChar);
		cout << textAction[i];
		

		if (textAction[i] == '\n')
		{
			Sleep(delayBase + delayChar * count / 2);
			count = 0;
		}
	}
}





std::vector<Found> Found::varietyFounds
{
	Found("���� �������", 
		(string)"�� ��������� � ���� �������\n�� ��������� � ����������� ������������ ������ �������..\n" + 
		"��� ������� ����������� �����, ����� �����\n� ��� �� ��������:\n"),

	Found("������� �������",
		(string)"�� ����������� ������������ ������ �������..\n" +
		"�� ��� ��������� ������� ������ ����������� �� �����\n� ���� � ���� ���������� ����.." +
		"\n\n������� �� �������� ���-�� ����!\n�� ��������:\n"),

	Found("������ �������",
		(string)"��� ������������� ������ �������..\n�� ��������� ��������� � ��������..\n" +
		"�� ���� ������� � �������. ��������!.\n�� �� �� ����� ���������� ���..\n" + 
		"������ �� �������� �����, � ����� ����� �����:\n"),

	Found("������� � �������",
		(string)"��� ����� � ������� � �������\n�� ��� ����������.. �����..\n" +
		"������ ��� � �����-�� ����� � ����� ���������\n�� ��������� ��� � ������ �� ������ ����.. �������!!\n\n" +
		"�������������� ������������, �� ��������� ��� ������� ����� �����!\n" +
		"�� ������������� �������..\n...\n...\n���! �������� �����! \n����� � ��������, �� ����� �������� ����� �����..\n" +
		"�� ��������� ����������� ���� ���� � �������������:\n"),

	Found("������� �����", 
		(string)"������� ������� � ������, �� ��������� ������� � ���\n" + 
		"�� ������� ��������� ������ �� �����..\n������� � ���� � ���� ����� �����!\n" + 
		"�� ��������� � ������� ������ ���� ������..\n� ��������� �� ����� ��� ���� � ������..\n\n" + 
		"��� ����� ������������ ������� �� �������������\n��� �������� �������, ��� ������ ��-�� �������..\n" + 
		"�� ������ �� �������..\n ������� ����� �� ���, � �� ��� ��������� ������!\n�� �����:\n")
};
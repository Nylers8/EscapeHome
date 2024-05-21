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

Item& Found::getItem()
{
	return *itemptr;
}

Monster& Found::getMonster()
{
	return *monsterptr;
}



void Found::action()
{
	system("cls");
	printText(textAction);
	printText("\t" + itemptr->getName());
	Sleep(300);
	system("cls");

	itemptr->pickup();
	itemptr = new Item();

	short randNum = rand() % 10;
	if (!randNum)
	{
		monsterptr->attack();
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
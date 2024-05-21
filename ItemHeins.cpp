#include "ItemHeins.h"


vector<Key> Key::allKey{};


Potion::Potion(string _name, short _hpRegen, string _textAction, string _textPickup)
{
	name = _name;
	hpRegen = _hpRegen;
	textPickup = _textPickup;
	textAction = _textAction;
	player = nullptr;
	erased = true;
}

Potion::Potion(const Potion& other)
{
	*this = other;
}

void Potion::action()
{
	player->changeHp(hpRegen);

	if (textAction != "")
	{
		printText(textAction);
		return;
	}

	printText("˸���� ��������� ����, �� ���������� \'" + name + "\'\n");
	printText("�� ����� ��������� ���������� ����������\n");
	printText("�������� \'" + player->getName() + "\' ������������� �� " + std::to_string(hpRegen) + " ������!\n");
}

void Potion::pickup()
{
	player->addItem(*this);

	if (textPickup != "")
	{
		printText(textPickup);
		return;
	}

	printText("�� �������� �� ���������� �� �������� ����������..\n");
	printText("�� ����� ����� � ���� ����������,\n�� ��� ��� �������..\n�� ������ ��������� � ������\n");
}



Key::Key()
{
	name = "���� ���������";
	textAction = "������ �� �������� ����";
	textPickup = "�� ������ � ��������, ����� 3 ��������";
}

Key::Key(string _name, string _textAction, string _textPickup)
{
	name = _name;
	textAction = _textAction;
	textPickup = _textPickup;
}

void Key::action()
{
	printText(textAction);
}

void Key::pickup()
{
	player->addItem(*this);
	printText(textPickup);
}


Key& Key::getKey(const short _id)
{
	if (_id < 0)
		return *new Key;


	short size = allKey.size();
	if (size <= 0)
	{
		initAllKey();
		size = allKey.size();
	}

	if (_id > size)
		return *new Key;

	return allKey[_id];
}

Key& Key::getKey(const string& _name)
{
	short size = allKey.size();
	if (size <= 0)
	{
		initAllKey();
		size = allKey.size();
	}

	for (short i = 0; i < size; i++)
	{
		if (allKey[i].getName() == _name)
			return allKey[i];
	}

	return *new Key;
}

Key& Key::getRandomKey()
{
	short size = allKey.size();
	if (size <= 0)
	{
		initAllKey();
		size = allKey.size();
	}

	short randIndex = rand() % size;
	return allKey[randIndex];
}


void Key::initAllKey()
{
	allKey = {Key("������ ����", "�� ������������ ������ ����", "�� ������� ������ ����")};
}

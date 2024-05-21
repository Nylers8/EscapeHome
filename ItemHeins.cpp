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

	printText("Лёгким движением руки, вы открываете \'" + name + "\'\n");
	printText("Вы жадно выпиваете содержимое флакончика\n");
	printText("Здоровье \'" + player->getName() + "\' восстановлено на " + std::to_string(hpRegen) + " единиц!\n");
}

void Potion::pickup()
{
	player->addItem(*this);

	if (textPickup != "")
	{
		printText(textPickup);
		return;
	}

	printText("Вы тянитесь за бутылочкой со странным срдержимым..\n");
	printText("Вы очень нежны с этой бутылочкой,\nна вид она хрупкая..\nВы кладёте бутылочку в карман\n");
}



Key::Key()
{
	name = "ключ галактики";
	textAction = "похоже он довольно крут";
	textPickup = "вы встали с осколком, между 3 столбами";
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
	allKey = {Key("ржавый ключ", "вы осматриваете ржавый ключ", "вы подняли ржавый ключ")};
}

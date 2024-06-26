﻿#include "ItemHeins.h"


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
	allKey = {
		Key("ключ с наклейкой", 
			(string)"Вы осмтриваете ключ, со странной наклейкой..\nВы с трудом рассматриваете наклейку(☺)\nОна вся выцветевшая и стёртая\n" + 
			"Похоже на ней изображен весёлый смайлик",
			"Вы замечаете ключ!\nПохоже она открывает какую-то дверь\nВы заметили, что на ключе есть стёртая наклейка.."),

		Key("вонючий ключ",
			"Вы не особо хотите доставть это ключ\nОн ужасно воняет!",
			"Вы унюхали что-то противное (фууу)\nПрисмотревшись вы поняли, что это ключ..\nВы уже не так рады, как предыдущему.."),

		Key("обычный ключ",
			"При расмотрении ключа, вы замечаете, что на ключе что-то есть!\nЭто надпись \'2\'..\nЧто бы это значило?",
			"Вы нашли ключ!\nПо сравнению с предыдущим он не воняет!"),

		Key("грязный ключ",
			"Этот ключ очень грязный!\nПохоже вставить в дверь, его будет трудно..",
			"Вы находите ещё один ключ!\nОн очент грязный..\nВы незнаете куда его положить..\n...\n...\nВы всё таки решили положить его в карман..\n"),

		Key("ржавый ключ",
			"Вы аккуратно расматриваете ключ..\nОн очень ржавый\nПохоже им долго не пользовались..",
			"Вы находите уже 5 ключ!\nСколько их в доме?\nВы аккуратно вешаете ключ на пояс.."),

		Key("большой ключ",
			"Вы решаете положить ключ на пол и рассмотерть..\nОн имеет странную изгибающуюся форму..\nКакую же дверь открывает такой большй замок?",
			"Вы замечаете большой ключ!\nЕго было трудно незаметить.."),

		Key("мокрый ключ",
			"Вы решаете осмотерть мокрый ключ..\nПохоже высыхать он не собирается..\nЭто плохо, он можжет заржаветь..",
			"Вы засовываете руку прямо в воду!\nОна холодная, но вы уверенно тянитесь за ключом\nВы успешно достали ключ.. И намочили руку.."),

		Key("липкий ключ",
			"Весь ключ обмотан паутиной..\nВстанет ли он хоть в какой-нибудь замок?",
			"Вы аккуратно берёте ключ.. Он очень липнет к рукам.. Вы приклеили его к поясу"),

		Key("портативная лестница",
			"Несмотря на свои размеры, с помощью неё можно подняться наверх",
			"Вы видите как из взорванной пасти, выпадает портативная лестница\nНабравшись сил вы поднимаете её..\nОна оказался не такой мерзкой как вы думали"),

		Key("золотой ключ",
			"Он очень сильно блестит\nИ он тяжелый",
			"Вы пытаетесь поднять золотой ключ\nОн оказался тяжелее, чем вы думали"),

		Key("пульт",
			"Похоже он открывает какую-то электрическую дверь\nВ доме вы такую не встречали",
			"Вы поднимаете пульт\nОн имеет антенку и всего одну кнопку"),

		Key("бензин",
			"Вероятно он нужен для машины\nНо в доме вы её не встречали",
			"Вы подбераите бензин\nКак он оказался на крыше?")
	};
}

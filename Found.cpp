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
	Found("куча коробок", 
		(string)"Вы подходите к куче коробок\nВы осторожно и внимательно осматриваете каждую коробку..\n" + 
		"Все коробки оказываются пусты, кроме одной\nВ ней вы находите:\n"),

	Found("картина старика",
		(string)"Вы внимательно осматриваете старую картину..\n" +
		"На ней изображен дряхлый старик залазеевший на крышу\nУ него в руке золотистый ключ.." +
		"\n\nКажется за картиной что-то есть!\nВы находите:\n"),

	Found("старый шкафчик",
		(string)"Вас заинтересовал старый шкафчик..\nВы осторожно подходите к шкафчику..\n" +
		"Он весь пыльный и грязный. Мерзость!.\nНо вы всё равно открываете его..\n" + 
		"Внутри вы находите грязь, а среди грязи лежит:\n"),

	Found("картина с пауками",
		(string)"Вас манит к картине с пауками\nНа ней изображены.. пауки..\n" +
		"Похоже они в каком-то тёмном и сыром помещении\nВы замечаете что у одного из пауков есть.. граната!!\n\n" +
		"Присмотревшись внимательнее, вы понимаете что картина висит криво!\n" +
		"Вы выраввниваете картину..\n...\n...\nУра! Идеально ровно! \nРядом с картиной, на стене открылся некий отсек..\n" +
		"Вы бестрашно засовываете туда руку и обнаруживаете:\n"),

	Found("картина парня", 
		(string)"Заметив картину с парнем, вы решаетесь подойти к ней\n" + 
		"На картине изображен парень на улице..\nКажется у него в руке некий пульт!\n" + 
		"Он открывает с помощью пульта двеь гаража..\nК сожалению не видно что есть в гараже..\n\n" + 
		"При более внимательном осмотре вы обнаруживаете\nЕле заметную ниточку, что торчит из-за картины..\n" + 
		"Вы дёрнули за ниточку..\n Картина упала на пол, а за ней показался тайник!\nВы нашли:\n")
};
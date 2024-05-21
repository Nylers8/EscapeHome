#include "Player.h"

Player::Player(string _name, short _hp, House& _currentHouse, Room& _currentRoom)
{
	name = _name;

	this->maxHp = _hp;
	this->hp = _hp;

	this->currentHouse = &_currentHouse;
	this->currentRoom = &_currentRoom;

	this->weapon = nullptr;
	this->armor = nullptr;
}

Player::Player(string _name, short _hp, House& _currentHouse, Room& _currentRoom, Weapon& _weapon, Armor& _armor) : Player(_name, _hp, _currentHouse, _currentRoom)
{
	this->weapon = &_weapon;
	this->armor = &_armor;
}

Player::Player()
{
	name = "none";

	maxHp = 1;
	hp = 1;

	currentHouse = nullptr;
	currentRoom = nullptr;
	weapon = nullptr;
	armor = nullptr;
}

Item& Player::operator[](short _id)
{
	if (_id < 0)
		return *new Item;

	if (_id >= inventory.size())
		return *new Item;

	return *inventory[_id];
}

Item& Player::operator[](string _name)
{
	short size = inventory.size();

	for (short i = 0; i < size; i++)
	{
		if (inventory[i]->getName() == _name)
		{
			return *inventory[i];
		}
	}

	return *new Item;
}


void Player::changeHp(const short _hp)
{
	hp += _hp;

	if (hp <= 0)
	{
		hp = 0;
		life = false;
	}

	else if (hp > maxHp)
		hp = maxHp;
}

void Player::addItem(Item& item)
{
	inventory.push_back(&item);
}


string& Player::getName()
{
	return name;
}

short Player::getHp()
{
	return hp;
}

short Player::getMaxHp()
{
	return maxHp;
}



bool Player::searchItem(string& _name)
{
	short size = inventory.size();
	for (short i = 0; i < size; i++)
	{
		if (inventory[i]->getName() == _name)
		{
			return true;
		}
	}

	return false;
}

void Player::eraseItem(short _id)
{
	if (inventory.size() <= 1)
	{
		inventory.clear();
		return;
	}

	inventory.erase(inventory.begin() + _id);
}

void Player::action()
{
	short act = request();

	short sizePaths = currentRoom->getSizePaths();
	short sizeFounds = currentRoom->getSizeFounds();

	if (act <= sizePaths)
	{
		goToRoom(act - 1);
	}
	else if (act <= sizeFounds + sizePaths)
	{
		goToFound(act - sizePaths - 1);
	}
	else if (act <= sizeFounds + sizePaths + 1)
		openInventory();

}


void Player::goToRoom(short _id)
{
	Room& nextRoom = currentRoom->getRoomFromPaths(_id);
	if (!nextRoom.open)
	{
		if (searchItem(nextRoom.getKey().getName()))
		{
			nextRoom.open = true;
			currentRoom = &nextRoom;

			printText("Вы открываете дверь от \'" + currentRoom->getName() + "\', при помощи \'" + nextRoom.getKey().getName() + '\'');
			printText("\nДверь медленно и со скрипом открывается..");
		}

		else
		{
			printText(nextRoom.getTextClosed());
			return;
		}
	}


	currentRoom = &nextRoom;

	system("cls");
	printText("Вы пошли в \'" + currentRoom->getName() + "\'...");


}

void Player::goToFound(short _id)
{
	currentRoom->getFound(_id).getItem().setPlayer(*this);
	currentRoom->getFound(_id).getMonster().setPlayer(*this);

	currentRoom->foundAction(_id);
}

void Player::useItem(short _id)
{
	inventory[_id]->action();

	if (inventory[_id]->erased)
		eraseItem(_id);
}

void Player::openInventory()
{
	short size = inventory.size();
	short act = 0;

	system("cls");
	do
	{
		size = inventory.size();
		short i = 0;

		cout << "---------- " << name << " ----------" << endl;
		cout << "Здоровье: " << hp << '/' << maxHp << endl << endl;
		cout << "Инвентарь: " << endl;
		for (; i < size; i++)
		{
			cout << "\t" << i << " - " << inventory[i]->getName() << endl;
		}
		cout << endl << i << " - закрыть инвентарь" << endl;
		cout << "---------- " << name << " ----------" << endl;

		cout << "\nВведите действие: ";
		std::cin >> act;

		system("cls");

		if (act >= 0 && act < size)
		{
			useItem(act);
			system("cls");
		}


	} while (act != size);
}


short Player::request()
{
	short act = 0;
	short size = currentRoom->getSizePaths() + currentRoom->getSizeFounds();

	do
	{
		system("cls");

		cout << "Возможные пути:" << endl;
		currentRoom->printActions();
		cout << "\nВведите действие: ";
		std::cin >> act;

	} while (0 >= act && act < size-1);
	
	system("cls");

	return act;
}

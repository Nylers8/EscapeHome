#include "Player.h"

Player::Player(short _hp, House& _currentHouse, Room& _currentRoom)
{
	name = "������ ��";

	this->hp = _hp;

	this->currentHouse = &_currentHouse;
	this->currentRoom = &_currentRoom;

	this->weapon = nullptr;
	this->armor = nullptr;
}

Player::Player(short _hp, House& _currentHouse, Room& _currentRoom, Weapon& _weapon, Armor& _armor) : Player(_hp, _currentHouse, _currentRoom)
{
	this->weapon = &_weapon;
	this->armor = &_armor;
}

Player::Player()
{
	name = "none";

	hp = 1;

	currentHouse = nullptr;
	currentRoom = nullptr;
	weapon = nullptr;
	armor = nullptr;
}

void Player::action()
{
	short act = request();

	short sizePaths = currentRoom->getSizePaths();
	short sizeFounds = currentRoom->getSizeFounds();

	if (act <= sizePaths)
	{
		goToRoom(act-1);
	}
	else if (act <= sizeFounds + sizePaths)
	{
		goToFound(act - sizePaths - 1);
	}

}

void Player::goToRoom(short _id)
{
	currentRoom = &currentRoom->getRoomFromPaths(_id);

	system("cls");
	printText("�� ����� � \'" + currentRoom->getName() + "\'...");


}

void Player::goToFound(short _id)
{
	if (_id < 0)
	{
		cout << "Id ���!" << endl;
		return;
	}

	currentRoom->foundAction(_id);
}


short Player::request()
{
	short act = 0;
	short size = currentRoom->getSizePaths() + currentRoom->getSizeFounds();

	do
	{
		system("cls");

		cout << "��������� ����:" << endl;
		currentRoom->printActions();
		cout << "\n������� ��������: ";
		std::cin >> act;

	} while (0 >= act && act < size);
	
	cout << endl;

	return act;
}

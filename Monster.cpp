#include "Monster.h"
#include "Player.h"


vector<Monster> Monster::allMonster{};


Monster::Monster()
{
    name = "Мега Таракан";
    textAction = "Мега Таракан, выпрыгивает на вас!";
    damage = 1;
    pl = nullptr;
}

Monster::Monster(string _name, string _textAction, short _damage)
{
    name = _name;
    textAction = _textAction;
    damage = _damage;
    pl = nullptr;
}


void Monster::attack()
{
    system("cls");
    printText(textAction);

    short damageToPlayer = (damage + damage / 4) - (rand() % (damage / 2));
    pl->changeHp(-damageToPlayer);

    printText("\n\'" + name + "\' нанес(-ла) вам: " + std::to_string(damageToPlayer) + " урона!\n");
    printText("Оставшееся здоровье: " + pl->getHp() + '/' + pl->getMaxHp());
}


void Monster::setPlayer(Player& _player)
{
    pl = &_player;
}


string& Monster::getName()
{
    return name;
}

Monster& Monster::getMonster(short _id)
{
    if (_id < 0)
        return *new Monster;

    short size = allMonster.size();
    if (size <= 0)
    {
        initAllMonster();
        size = allMonster.size();
    }

    if (_id > size)
        return allMonster[size - 1];

    return allMonster[_id];
}

Monster& Monster::getMonster(string& _name)
{
    short size = allMonster.size();
    if (size <= 0)
    {
        initAllMonster();
        size = allMonster.size();
    }
    
    for (short i = 0; i < size; i++)
    {
        if (allMonster[i].getName() == _name)
            return allMonster[i];
    }

    return *new Monster;
}

Monster& Monster::getRandom()
{
    short size = allMonster.size();
    if (size <= 0)
    {
        initAllMonster();
        size = allMonster.size();
    }

    short randIndex = rand() % size;
    return allMonster[randIndex];
}


void Monster::initAllMonster()
{

    allMonster = {Monster("летучая мышь", 
        (string)"Как только вы забрали свою \'награду\'..\n" + 
        "Из дальнего угла на вас напала летучая мышь!\n" + 
        "Она чуть не расцарапа вам лицо! Благо вы успели отбиться..\n", 20)};
}

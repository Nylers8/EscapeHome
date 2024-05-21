#pragma once

#include "Item.h"
#include "ItemHeins.h"


vector<Item*> Item::allItem{};


Item::Item()
{
    name = "ничего";
    textPickup = "";
    textAction = "";
    player = nullptr;
}

Item::Item(const Item& other)
{
    *this = other;
}

void Item::action()
{
    printText("Вы умело использовали \'" + name + "\'!!");
}

void Item::pickup()
{
    printText("Вы пытаетесь подобрать \'" + name + "\'..\nУ вас неплохо получается!");
}

void Item::printData()
{
    printText('\'' + name + "\':\n");
    printText("\tИспользуется с умом!");
}

string& Item::getName()
{
    return name;
}

void Item::setPlayer(Player& _player)
{
    player = &_player;
}

Item& Item::getRandom()
{
    short size = allItem.size();

    if (size <= 0)
    {
        initVector();
        size = allItem.size();
    }

    short randIndex = rand() % size;
    return *allItem[randIndex];
}

void Item::initVector()
{
    allItem = {new Potion("huiSubaki",15)};
}

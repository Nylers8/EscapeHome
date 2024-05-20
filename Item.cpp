#include "Item.h"

void Item::pickup()
{
}

Item& Item::getRandom()
{
    return *new Item();
}

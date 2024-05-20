#include "Monster.h"

void Monster::attack()
{
}

Monster& Monster::getRandom()
{
    return *new Monster;
}

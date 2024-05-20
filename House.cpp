#include "House.h"

Room& House::operator[](const short _id)
{
    return getRoom(_id);
}

Room& House::operator[](const string _name)
{
    return getRoom(_name);
}

void House::addRoom(Room& _room)
{
    allRoom.push_back(_room);
}

short House::getSize()
{
    return allRoom.size();
}

Room& House::getRoom(const short _id)
{
    if (allRoom.size() == 0)
    {
        std::cout << "Дом пока пуст!" << endl;
        return *(new Room);
    }

    if (_id >= allRoom.size())
    {
        cout << "Неизвестный id комнаты, возвращается последний" << endl;
        return allRoom[allRoom.size() - 1];
    }
    return allRoom[_id];
}

Room& House::getRoom(const string& _name)
{
    for (short i = 0; i < allRoom.size(); i++)
    {
        if (allRoom[i].get().getName() == _name)
        {
            return allRoom[i];
        }
    }

    return *(new Room);
}

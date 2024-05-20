#pragma once

#include "Header.h"

class A
{
public:
	virtual void action() = 0;
};

class B : public A
{
public:
	void action()override
	{
		cout << "������� �� �����!" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;
	House h2;

	Room spal1(h1, "�������", {}, {Found::getFound(0), Found::getFound(1)});
	Room vanna1(h1, "�����");
	Room toiler1(h1, "������");
	Room cor1(h1, "�������", { "�������", "�����"}, {Found::getFound(0)}, true);

	Player pl(100, h1, spal1);
	while (true)
	{
		pl.action();
	}

	return 0;
}
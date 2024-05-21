#pragma once

#include "Header.h"
#include <typeinfo>

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;
	
	Item& ptr = Key::getKey("������ ����");

	Room spal(h1, "�������", {}, { *new Found("������ �������", "�� ������� � ������ �������\n", Key::getKey("������ ����")), Found::getRandomFound()});
	Room van(h1, "�����", {}, {}, false, &Key::getKey("������ ����"), "����� ������ ����");
	Room cor(h1, "�������", { "�������", "�����" });

	Player pl(100, h1, spal);
	while (true)
	{
		pl.action();
	}

	return 0;
}
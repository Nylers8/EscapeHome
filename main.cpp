#pragma once

#include "Header.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;
	House h2;

	Room spal1(h1, "�������");
	Room vanna1(h1, "�����");
	Room toiler1(h1, "������");
	Room cor1(h1, "�������", { "�������", "�����"});

	Found f(Found::getRandomFound());

	f.action();

	return 0;
}
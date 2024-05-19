#pragma once

#include "Header.h"

#include <initializer_list>

void Test(std::string name, std::initializer_list<short> shorts)
{
	cout << name << endl;

	for (short s : shorts)
	{
		std::cout << s << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");


	House h1;
	House h2;

	Room spal1(h1, "спальня");
	Room vanna1(h1, "ванна");
	Room toiler(h1, "туалет");
	Room cor1(h1, "коридор", { "спальня", "ванна"});

	h1[0].printActions();
	cout << endl;
	h1[1].printActions();
	cout << endl;
	h1[2].printActions();
	cout << endl;
	h1[3].printActions();
	cout << endl;

	return 0;
}
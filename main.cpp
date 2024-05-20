#pragma once

#include "Header.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;
	House h2;

	Room spal1(h1, "спальня");
	Room vanna1(h1, "ванна");
	Room toiler1(h1, "туалет");
	Room cor1(h1, "коридор", { "спальня", "ванна"});

	Found f(Found::getRandomFound());

	f.action();

	return 0;
}
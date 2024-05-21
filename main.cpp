#pragma once

#include "Header.h"
#include <typeinfo>

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;
	
	Item& ptr = Key::getKey("ржавый ключ");

	Room spal(h1, "спальня", {}, { *new Found("Старая коробка", "вы подошли к старой коробке\n", Key::getKey("ржавый ключ")), Found::getRandomFound()});
	Room van(h1, "ванна", {}, {}, false, &Key::getKey("ржавый ключ"), "нужен ржавый ключ");
	Room cor(h1, "коридор", { "спальня", "ванна" });

	Player pl(100, h1, spal);
	while (true)
	{
		pl.action();
	}

	return 0;
}
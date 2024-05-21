#pragma once

#include "Header.h"
#define skipStart

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;

	// Создание комнат
	Room spal(h1, "спальня");
	Room cor(h1, "коридор");
	Room tualet(h1, "туалет");
	Room kid(h1, "детская");
	Room kitch(h1, "кухня");
	Room stairs(h1, "лестничный проём");
	Room under(h1, "подвал");

	// Объединение 1 этажа
	cor.addPath({ "спальня", "туалет", "детская", "кухня" });

	kid.addPath({"подвал"});
	kitch.addPath({"лестничный проём"});



	string enterText;

	// Начало игры

#ifndef skipStart
	printText("...\nВы просыпаетесь на кровати..\nУ вас болит голова..\n");
	printText("Вы помните, как с друзьями устроили поход в лес..\n");
	printText("А дальше воспоминания обрываются..\n\n");
#endif // skipStart

	printText("Введите имя персонажа: ");
	std::cin >> enterText;
	system("cls");

	Player pl(enterText, 100, h1, spal);

#ifndef skipStart
	printText("Вы оглядываетесь, и замечаете, что это место вам незнакомо\n");
	printText("Всё оно очень грязное и мерзкое\n");
	printText("Вам некомфортно..\n");
	printText("Нужно что-то делать..");
	system("cls");
#endif // !skipStart

	while (pl.life)
	{
		pl.action();
	}

	return 0;
}
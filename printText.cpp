#pragma once

#include "printText.h"

void printText(std::string text)
{
	short delayBase = 500;
	short delayChar = 40;

	short size = text.size();
	short count = 0;

	for (short i = 0; i < size; i++, count++)
	{
		Sleep(delayChar);
		std::cout << text[i];


		if (text[i] == '\n' || i == size-1)
		{
			Sleep(delayBase + delayChar * count / 2);
			count = 0;
		}
	}
}

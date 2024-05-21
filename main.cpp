#pragma once

#include "Header.h"
#define skipStart

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;

	// �������� ������
	Room spal(h1, "�������");
	Room cor(h1, "�������");
	Room tualet(h1, "������");
	Room kid(h1, "�������");
	Room kitch(h1, "�����");
	Room stairs(h1, "���������� ����");
	Room under(h1, "������");

	// ����������� 1 �����
	cor.addPath({ "�������", "������", "�������", "�����" });

	kid.addPath({"������"});
	kitch.addPath({"���������� ����"});



	string enterText;

	// ������ ����

#ifndef skipStart
	printText("...\n�� ������������ �� �������..\n� ��� ����� ������..\n");
	printText("�� �������, ��� � �������� �������� ����� � ���..\n");
	printText("� ������ ������������ ����������..\n\n");
#endif // skipStart

	printText("������� ��� ���������: ");
	std::cin >> enterText;
	system("cls");

	Player pl(enterText, 100, h1, spal);

#ifndef skipStart
	printText("�� �������������, � ���������, ��� ��� ����� ��� ���������\n");
	printText("�� ��� ����� ������� � �������\n");
	printText("��� �����������..\n");
	printText("����� ���-�� ������..");
	system("cls");
#endif // !skipStart

	while (pl.life)
	{
		pl.action();
	}

	return 0;
}
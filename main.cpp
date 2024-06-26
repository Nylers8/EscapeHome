#pragma once

#include "Header.h"
#define skipStart

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	House h1;

	// �������� ������

	// ������ ����
	Room spal(h1, "�������");
	Room cor(h1, "�������");
	Room tualet(h1, "������", {}, {Found("���������� �������", "�� ��������� � ���������� �������\n��� ��� ������, ������� � �������\n�� ��� �� ��������:\n", Key::getKey(0))});
	Room kid(h1, "�������", {}, { Found("�������", "�� ��������� � �������\n��� ��� �������.. � �������..\n�� ��� �� ���������:\n", Key::getKey(1)) }, false, &Key::getKey(0), "�� ��������� ������� �����..\n������ ����� ������..\n�������������� �� ������, ��� ��� ����� � ���������");
	Room kitch(h1, "�����", {}, {Found("�������", "��� ������������� �������\n� ���� ������ ���-�� ������ � ������..\n�� ��� ����������..\n� ��� �� ��������:", Key::getKey(2))}, false, &Key::getKey(1), "�� ������� �� �����..\n��� ����� ����� ������..");
	Room stairs(h1, "���������� ����", {}, {Found("���� ����", "�� ��������� ���-�� �������� � ���� ����..\n������� � ������� ���� �����\n�� ��������:\n", Key::getKey(3))});
	Room under(h1, "������", {}, {}, false, &Key::getKey(7), "�� ������ �� ����� � ������\n������ �� ������..\n� ���� ���� ������ � �������..");

	// ����������� 1 �����
	cor.addPath({ "�������", "������", "�������", "�����" });

	kid.addPath({"������"});
	kitch.addPath({"���������� ����"});


	// ������ ����
	Room spal2(h1, "�������2", {}, {Found("���� �����", "�� ��������� ���� �����..\n��������� ��������� ����, �� ������, ��� ������ �� ������\n�� �� �� ���� ����������:\n", Key::getKey(4))}, false, &Key::getKey(2), ""); //false, &Key::getKey(3), "���������� �� ��������, �� ����������� �� �����\n��� �������..\n ������, � ��� ������ ������� �����.."
	Room tualet2(h1, "������2");
	Room cor2(h1, "�������2");
	Room klad2(h1, "��������2");
	Room vanna2(h1, "�����2");

	// ����������� 2 �����
	
	spal2.addPath({"���������� ����", "������2"});
	cor2.addPath({"�������2", "��������2"});
	klad2.addPath({"�����2"});



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

	Player pl(enterText, 100, h1, spal2);

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
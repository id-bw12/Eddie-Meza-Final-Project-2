#include "NPC.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

void NPC::addFood()
{
	COORD xyPos;

	srand(unsigned(time(NULL)));

	npcX = rand() % (48 - 11) + 11;
	npcY = rand() % (13 - 6) + 6;

	xyPos.X = npcX + .25;
	xyPos.Y = npcY + .25;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	cout << npcChar;
}

void NPC::moveFood()
{
	COORD xyPos;

	changeCoord();

	xyPos.X = npcX;
	xyPos.Y = npcY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	cout << npcChar;

}

void NPC::changeCoord()
{
	srand(time(NULL));

	int x, y;

	do
	{
		x = rand() % 48 + 11;
		y = rand() % 13 + 6;

	}while (npcX == x && npcY == y);

	npcX = x;
	npcY = y;
}
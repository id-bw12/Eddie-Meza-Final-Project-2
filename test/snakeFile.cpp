/*
===========================================================================================
<< ID INFORMATION >>
===========================================================================================
Programmer                    : Eddie
Assignment #                  : Final Project
ASsignment Name				  : Snake Alive
Course # and Title            : CISC 205 OOPS C++ Object Oriented Programming
Class Meeting Time            : 9:35- 12:45 T, TH
Instructor                    : Professor Forman
Hours Spent                   : 15h
Degree of Difficulty          : 8
Date Completed                : 12/14/2014
File Name                     : Eddie Meza Final Project
===========================================================================================
<< PROGRAM DESCRIPTION >>
===========================================================================================
This purpose of the program create and play a snake game. The user signs in to a
predetermined account and chooses a option on the menu. Logo, play snake, instruction,
game history, high score, save score, and exit program.
===========================================================================================
<< CUSTOM DEFINED FUNCTIONS (alphabetical order) >>
===========================================================================================

snakeClass(void);

snakeClass(int _x, int _y, bool _head);

void giveChar(bool _head);

void setTail(bool _tail);

void drawSnakesegment();

void setSnakexpos(int _x){ xPos = _x;	}

void setSnakeypos(int _y){ yPos = _y; }

void swapSnakex(int &_x){ swap(xPos, _x); }

void swapSnakey(int &_y){ swap(yPos, _y); }

int getsnakeXpos() const{return xPos;}

int getsnakeYpos() const{return yPos;}

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#include "gameClass.h"
#include <Windows.h>
#include <iostream>

using namespace std;

snakeClass::snakeClass()
{}

snakeClass::snakeClass(int _x, int _y, bool _head)
{
	xPos = _x;
	yPos = _y;
	giveChar(_head);
}

void snakeClass::giveChar(bool _head)
{
	if (_head)
		snakeChar = '\002';
	else
		snakeChar = '\117';
}

void snakeClass::setTail(bool _tail)
{
	if (_tail)
		snakeChar = '\043';
	else
		snakeChar = '\117';
}

void snakeClass::drawSnakesegment()
{
	COORD cursorCoord;

	cursorCoord.X = getsnakeXpos();
	cursorCoord.Y = getsnakeYpos();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoord);

	cout << snakeChar;
}

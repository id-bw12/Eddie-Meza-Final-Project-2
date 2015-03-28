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

void hitEnter()

void moveCursor(int _x, int _y)

void clearScreen()

void changeColor(int _color)

void showCursor(bool _show)

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#ifndef EDUTIL_H
#define EDUTIL_H

#include <iostream>
#include <Windows.h>

using namespace std;

class EDUtil
{

public:
	static void hitEnter()
	{
		cout << "\t\t\t\311\315\315\315\315\315\315\315\315\315\315"
			<< "\315\315\315\315\315\315\315\315\315\315\315\273\n"
			<< "\t\t\t\272Hit ENTER To Continue\272\n"
			<< "\t\t\t\310\315\315\315\315\315\315\315\315\315\315"
			<< "\315\315\315\315\315\315\315\315\315\315\315\274\n\n";

		cin.ignore();

	}

	static void moveCursor(int _x, int _y)
	{
		COORD cursorCoord;

		cursorCoord.X = _x;
		cursorCoord.Y = _y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoord);
	}

	static void clearScreen()
	{
		system("CLS");
	}

	static void changeColor(int _color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	}

	static void showCursor(bool _show)
	{
		// thanks to 
		// http://stackoverflow.com/questions/18028808/blinking-underscore-with-console

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursor;
		GetConsoleCursorInfo(h, &cursor);
		cursor.bVisible = _show;
		SetConsoleCursorInfo(h, &cursor);
	};

};

#endif
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

void changeCoord(vector<snakeClass*> _snake);

void addFood(vector<snakeClass*> _snake);

void moveFood(vector<snakeClass*> _snake, int _ate);

int getFoodXpos() const{return foodX;}

int getFoodYpos() const{return foodY;}

double getOnepoint() const{ return points; }

double getTwopoint() const{ return points2; }

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#include "gameClass.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void foodClass::addFood(vector<snakeClass*> _snake)
{
	COORD xyPos;

	bool foodAdded = false;

	srand(unsigned(time(NULL)));

	do
	{
		foodX = rand() % 48 + 11;
		foodY = rand() % 13 + 6;

		if (foodX != _snake[0][0].getsnakeXpos() && foodY != _snake[0][0].getsnakeYpos())
			foodAdded = true;


	} while (!foodAdded);

	

	xyPos.X = foodX;
	xyPos.Y = foodY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	cout << foodChar;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void foodClass::moveFood(vector<snakeClass*> _snake, int _ate)
{
	COORD xyPos;

	changeCoord(_snake);

	xyPos.X = foodX;
	xyPos.Y = foodY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
	if (_ate == 5)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	cout << foodChar;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void foodClass::changeCoord(vector<snakeClass*> _snake)
{
	bool foodChanged = false;

	srand(unsigned(time(NULL)));

	int x, y;

	do
	{
		x = rand() % 48 + 11;
		y = rand() % 13 + 6;

		if (x != foodX && y != foodY)
			for (int i = 0; i < _snake.size(); i++)
			if (_snake[i][0].getsnakeXpos() != x && _snake[i][0].getsnakeYpos() != y)
					foodChanged = true;
				else
				{
					foodChanged = false;
					break;
				}
					
		

	} while (!foodChanged);

	foodX = x;
	foodY = y;
}
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

void setupBoard();

void drawBoard();

void moveSnake();

void ateFood(int _x, int _y, int _xPrev, int _yPrev);

void changeSpeed(int _x, int _y);

void deletingSnake();

void displaySnake();

void addTail(int _x, int _y);

void updateXY();

void getXY();

bool checkBound(int _x, int _y);

bool checkMove(Direction _direct);

bool checkSnakehit(int _x, int _y);

bool checkBehind(int _x, int _y);

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/


#include "gameClass.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

BoardClass::BoardClass()
{
	util.showCursor(false);

	playersnake.push_back(new snakeClass(25, 10, true));

	setupBoard();
	drawBoard();
	addFood(playersnake);
	displaySnake();
}

void BoardClass::setupBoard()
{
	gameBoard.resize(MAXROW);

	for (int i = 0; i < MAXROW; ++i)
		gameBoard[i].resize(MAXCOL);

	gameBoard[0][0] = '\311';
	gameBoard[MAXROW - 1][MAXCOL - 1] = '\274';
	gameBoard[0][MAXCOL - 1] = '\273';
	gameBoard[MAXROW - 1][0] = '\310';

	for (int i = 1; i < MAXCOL - 1; i++)
	{
		gameBoard[0][i] = '\315';
		gameBoard[MAXROW - 1][i] = '\315';
	}
	for (int i = 1; i < MAXROW - 1; i++)
	{
		gameBoard[i][0] = '\272';
		gameBoard[i][MAXCOL - 1] = '\272';
	}
}

void BoardClass::drawBoard()
{
	util.moveCursor(10, 5);

	for (int i = 0; i < MAXROW; i++){
		for (int j = 0; j < MAXCOL; j++){
			cout << gameBoard[i][j];
		}
		util.moveCursor(10, 5 + i + 1);
	}
}

bool BoardClass::checkMove(Direction direct)
{

	iter = playersnake.begin();
		switch (direct)
		{

		case LEFT:
			if (checkBound(-1,0))
				changeSpeed(-1, 0);
			else
				hitWall = true;
			break;

		case RIGHT:
			if (checkBound(1,0))
				changeSpeed(1, 0);
			else
				hitWall = true;
			break;

		case UP:
			if (checkBound(0,-1))
				changeSpeed(0, -1);
			else
				hitWall = true;
			break;

		case DOWN:
			if (checkBound(0,1))
				changeSpeed(0, 1);
			else
				hitWall = true;
			break;

		default:
			break;
	}

	return hitWall;

}

void BoardClass::changeSpeed(int x, int y)
{
	xSpeed = x;
	ySpeed = y;
}

void BoardClass::moveSnake()
{
	int xPrev, yPrev;
	int xPos, yPos;

	deletingSnake();
	
	for (iter = playersnake.begin(); iter != playersnake.end(); ++iter)
	{

		if (iter != playersnake.begin())
		{
			(*iter)->swapSnakex(xPrev);
			(*iter)->swapSnakey(yPrev);
		}
		else
		{
			xPrev = (*iter)->getsnakeXpos();
			yPrev = (*iter)->getsnakeYpos();
			updateXY();
		}
		xPos = (*iter)->getsnakeXpos(); yPos = (*iter)->getsnakeYpos();
	}

	displaySnake();

	ateFood(xPos, yPos, xPrev, yPrev);
}

void BoardClass::ateFood(int x, int y, int xPrev, int yPrev)
{
	if (x == getFoodXpos() && y == getFoodYpos())
	{
		addTail(xPrev, yPrev);
		playerScore += getOnepoint();
		moveFood(playersnake, foodAte);
		foodAte++;
		if (foodAte == 5)
		{
			food = new foodClass();
			food->moveFood(playersnake, foodAte);
			checkFood = new NChrono();
			checkFood->setThrottle(5);
			
		}

	}

	if (foodAte >= 5)
		if (x == food->getFoodXpos() && y == food->getFoodYpos())
		{
			addTail(xPrev, yPrev);
			playerScore += food->getTwopoint();
			delete food;
			food = nullptr;
			foodAte = 0;
		}
		
	if (foodAte >= 5)
	{
		if (checkFood->check())
		{
			util.moveCursor(food->getFoodXpos(), food->getFoodYpos());
			cout << " ";
			delete food;
			food = nullptr;
			delete checkFood;
			checkFood = nullptr;
			foodAte = 0;
		}
	}

}

void BoardClass::deletingSnake()
{
	COORD cursorCoord;

	for (iter = playersnake.begin(); iter != playersnake.end(); ++iter)
	{
		cursorCoord.X = (*iter)->getsnakeXpos();
		cursorCoord.Y = (*iter)->getsnakeYpos();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoord);
		
		cout << " ";
	}
}

void BoardClass::displaySnake()
{
	for (iter = playersnake.begin(); iter != playersnake.end(); ++iter)
	{
		util.changeColor(10);
		(*iter)->drawSnakesegment();
	}
	util.changeColor(7);
}

void BoardClass::updateXY()
{
	playersnake[0][0].setSnakexpos((playersnake[0][0].getsnakeXpos() + xSpeed));
	playersnake[0][0].setSnakeypos((playersnake[0][0].getsnakeYpos() + ySpeed));

}

void BoardClass::addTail(int x, int y)
{
	playersnake.push_back(new snakeClass(x, y, false));

	playersnake[playersnake.size() - 1][0].setTail(true);

	if (playersnake.size() > 2)
		playersnake[playersnake.size() - 2][0].setTail(false);
}

void BoardClass::getXY()
{
	cout.precision(2);
	cout << fixed;
	for (iter = playersnake.begin(); iter != playersnake.end(); ++iter)
	{
		cout << "X: " << (*iter)->getsnakeXpos() << " Y:" << (*iter)->getsnakeYpos() << "  ";
	}
}

bool BoardClass::checkBound(int x, int y)
{
	int xright = 69, xleft = 10, ytop = 5, ybot = 24;
	bool onBoard = false;

	if ((*iter)->getsnakeXpos() + x > xleft && (*iter)->getsnakeXpos()+ x < xright 
		&& (*iter)->getsnakeYpos() + y > ytop && (*iter)->getsnakeYpos() + y < ybot)
		onBoard = checkSnakehit(x, y);

	return onBoard;
}

bool BoardClass::checkSnakehit(int x, int y)
{
	bool snakeOK = true;

	if (playersnake.size() != 1)
		for (int i = 1; i < playersnake.size(); i++)
			if (playersnake[0][0].getsnakeXpos() + x != playersnake[i][0].getsnakeXpos() || playersnake[0][0].getsnakeYpos() + y != playersnake[i][0].getsnakeYpos())
				snakeOK = true;
			else
			{
				snakeOK = false;
				break;
			}

	return snakeOK;
}

bool BoardClass::checkBehind(int x, int y)
{
	bool snakeOK = true;

	if (playersnake.size() != 1)
		if (playersnake[0][0].getsnakeXpos() + x != playersnake[1][0].getsnakeXpos() || playersnake[0][0].getsnakeYpos() + y != playersnake[1][0].getsnakeYpos())
			snakeOK = true;
		else
			snakeOK = false;

	return snakeOK;
}
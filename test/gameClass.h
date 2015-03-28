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

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "EDUtil.h"
#include "DeltaTime.h"
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

//http://www.cplusplus.com/forum/beginner/94164/
//SweedJesus
//ktgee.net

class BoardClass;

class gameClass
{

public:
	int xSpeed = 1, ySpeed = 0, foodAte = 0;
	double playerScore = 0;
	bool hitWall = false;
	

};

class snakeClass
{
private:
	int xPos, yPos;
	char snakeChar = '/000';

public:
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

};

class foodClass
{
	
private:
	int foodX, foodY;
	double points = 1, points2 = 2;
	char foodChar = 'm';

public:
	void changeCoord(vector<snakeClass*> _snake);
	void addFood(vector<snakeClass*> _snake);
	void moveFood(vector<snakeClass*> _snake, int _ate);
	int getFoodXpos() const{return foodX;}
	int getFoodYpos() const{return foodY;}
	double getOnepoint() const{ return points; }
	double getTwopoint() const{ return points2; }

};

class BoardClass: public gameClass, foodClass
{
	friend class EDUtil;
public:
	BoardClass();
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
	static EDUtil util;

private:
	const int MAXCOL = 60, MAXROW = 20;
	foodClass *food;
	NChrono *checkFood;
	vector<vector<char>> gameBoard;
	vector<snakeClass*> playersnake;
	vector<snakeClass*>::iterator iter;
};

#endif
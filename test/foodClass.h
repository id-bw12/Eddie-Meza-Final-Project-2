#ifndef FOODCLASS_H
#define FOODCLASS_H

#include "snakeClass.h"
#include <string>
#include <vector>

using namespace std;

class foodClass
{

	public:
		void changeCoord(vector<snakeClass> snake);
		void addFood(vector<snakeClass> snake);
		void moveFood(vector<snakeClass> snake);

	char foodChar = 'm';
	double foodX, foodY;
		
};

#endif
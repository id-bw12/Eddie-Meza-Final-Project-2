#ifndef NPC_CLASS_H
#define NPC_CLASS_H

#include <string>

using namespace std;

class NPC
{

	public:
		void changeCoord();
		void addFood();
		void moveFood();

	char npcChar = '@';
	double npcX, npcY;

};

#endif
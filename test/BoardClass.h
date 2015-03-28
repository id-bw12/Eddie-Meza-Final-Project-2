#ifndef BOARDCLASS_H
#define BOARDCLASS_H

#include <vector>

using namespace std;

class BoardClass
{
public:
	BoardClass();
	void setupBoard();
	void drawBoard();
	void moveCursor(int x, int y);

private:
	const int MAXCOL = 60, MAXROW = 20;
	vector<vector<char>> gameBoard;
};


#endif
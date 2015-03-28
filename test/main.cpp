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

void welcomeScreen(const string NAME);

void menuItems();

void mainMenu(const string NAME);

void gameInstructions();

void signIn(string &userName);

void goSignin();

void logo();

void gameState(int &gameCount, string userName, vector<int> &gameScores);

void SnakeGame(int gameCount, string userName, vector<int> &gameScores, float speed);

void playAgain(bool &again);

void selectSpeed(float &speed);

void arrowKeys(BoardClass *game, Direction &snakeDirect);

void checkPause(BoardClass *game, bool &pause, Direction &snakeDirect);

void gameHistory(int gameNumber, vector<int> gameScore, string userName);

void highScore(int gameNumber, vector<int> gameScore, string userName);

void saveHistory(string userName, vector<int> gameScore, vector<vector<int>> &oldGame, string textFile, bool &checkName);

void sortScore(vector<int> &gameNumbers, vector<int> &gameScore);

void exitProgram(string userName, const string NAME);

void moverCursor(int x, int y ,BoardClass *game);

void showScore(int x, int y, BoardClass *game, int gameCount, string userName, vector<int> gameScores);

void gameOver(BoardClass *game);

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#include "gameClass.h"
#include "DeltaTime.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <fstream>		//Necessary for file I/O
#include <string>

using namespace std;
using namespace NUtil;

void welcomeScreen(const string NAME);

void menuItems();

void mainMenu(const string NAME);

void gameInstructions();

void signIn(string &userName);

void goSignin();

void logo();

void gameState(int &gameCount, string userName, vector<int> &gameScores);

void SnakeGame(int gameCount, string userName, vector<int> &gameScores, float speed);

void playAgain(bool &again);

void selectSpeed(float &speed);

void arrowKeys(BoardClass *game, Direction &snakeDirect);

void checkPause(BoardClass *game, bool &pause, Direction &snakeDirect);

void gameHistory(int gameNumber, vector<int> gameScore, string userName);

void highScore(int gameNumber, vector<int> gameScore, string userName);

void saveHistory(string userName, vector<int> gameScore, vector<vector<int>> &oldGame, string textFile, bool &checkName);

void sortScore(vector<int> &gameNumbers, vector<int> &gameScore);

void exitProgram(string userName, const string NAME);

void moverCursor(int x, int y ,BoardClass *game);

void showScore(int x, int y, BoardClass *game, int gameCount, string userName, vector<int> gameScores);

void gameOver(BoardClass *game);

int main()
{
	/**************************************************************
	***		CONST LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/

	const string MY_NAME("Eddie");

	/*************************************************************/

	welcomeScreen(MY_NAME);

	mainMenu(MY_NAME);

	cin.ignore();
}

////////////////////////////////////////////////////

//START FUNCTION DEFINITIONS 

////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

//NAME:			welcomeScreen()
//DESCRIPTION:	Displays the welcome Screen using NAME for the 
//				programs name nad calls on the hitEnter function.

//Calls: hitEnter

//Called By: main

///////////////////////////////////////////////////////////////////////////////

void welcomeScreen(const string NAME)
{

	cout << "\t\tWelcome to " << NAME << "'s Snake Alive game.\n";

	BoardClass::util.hitEnter();

	return;
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			menuItems
//DESCRIPTION:	Displays the menu items that are available and pass
//				userName to checkName to display the instructions.

//Calls: checkName

//Called By: mainMenu

///////////////////////////////////////////////////////////////////////////////
void menuItems()
{
	// Draw the menu
	cout << "\t\t\t\tMenu" << endl
		<< "\t\t\t I-Instruction" << endl
		<< "\t\t\t S-Sign in" << endl
		<< "\t\t\t L-Display Logo" << endl
		<< "\t\t\t P-Play Snake" << endl
		<< "\t\t\t G-Game Hitsory" << endl
		<< "\t\t\t H-High Score" << endl
		<< "\t\t\t C-Save Score" << endl
		<< "\t\t\t X\055Exit Program\n\n";

	cout << "\t\t Please enter your selection and hit ENTER: ";
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			mainMenu()
//DESCRIPTION:	Calls on the function to display the menu items
//				and goes in a while loop to make sure we don't 
//				exit the program and get user inputs multiple times.

//Calls: menuItems, signIn, hitEnter, clearScreen, logo, goSign, goGalton,
//		 playGalton, gameHistory, exitProgram, checkName

//Called By: 

///////////////////////////////////////////////////////////////////////////////
void mainMenu(const string NAME)
{

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS						***
	**************************************************************/
	char selection;		// User input character for menu selection

	string userName;	// User name

	vector<int> gameScores;
	vector<vector<int>> oldGame(10, vector<int>(2));

	int exitCount = 0, gameCount = 0;

	bool sameRun = false, addName = false;

	/**************************************************************/

	menuItems();

	while (true)
	{
		cin >> selection;

		switch (toupper(selection))
		{

		case 'I':
				gameInstructions();
			break;

		case 'S':
			if (userName.empty())
				signIn(userName);
			else
			{
				cout << "You already signed in.\n\n";
				BoardClass::util.hitEnter();
				cin.ignore();
				BoardClass::util.clearScreen();
			}
			break;

		case 'L':
			if (!userName.empty())
				logo();
			else
				goSignin();
			break;

		case 'P':
			if (!userName.empty())
			{
				system("CLS");
				gameState(gameCount, userName, gameScores);
			}
			else
				goSignin();
			break;

		case 'G':
			if (!userName.empty())
				gameHistory(gameCount, gameScores, userName);
			else
				goSignin();
			break;

		case 'H':
			if (!userName.empty())
				highScore(gameCount, gameScores, userName);
			else
				goSignin();
			break;

		case 'C':
			if (!userName.empty())
				saveHistory(userName, gameScores, oldGame, "High Score.txt", addName);
			else
				goSignin();
			break;

		case 'X':
			exitProgram(userName, NAME);
			break;

		default:
			if (exitCount < 4)
			{

				if (exitCount == 3)
					cout << "This is the third time you enter an invalidoption.\nIf you enter in an"
					<< " invalid option again the program well close.\n";
				else
					cout << selection << " is an invalid option.\n";

				BoardClass::util.hitEnter();
				cin.ignore();
				exitCount++; 
				BoardClass::util.clearScreen();
			}
			else
				if (exitCount == 4)
					exit(true);
			break;
		}
		menuItems();
	}

	return;
}

void gameInstructions()
{
	cout << "\nA standard snake game. You control the snake with the\n"
		 << "arrow keys. When you eat a food you grow one segment and\n"
		 << "get one point. Everytime you get five points a new food\n"
		 << "appears that give the player 2 points when eaten. If you\n"
		 << "hit the walls or one of your segements then you lose.\n"
		 << "\nBefore the game starts you have speed options and you\n"
		 << "pause the game by hitting the P key.\n\n";

	BoardClass::util.hitEnter();
	cin.ignore();

	system("CLS");
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			signIn
//DESCRIPTION:	Ask the user to input a name and stores it in the 
//				userName using call by refernce and greets the user
//				by the name they input.

//Calls: hitEnter, clearScreen

//Called By: mainMenu

///////////////////////////////////////////////////////////////////////////////
void signIn(string &userName)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/
	string accountName[] = { "Albert Einstein", "Madame Curie", "Eddie Meza", "Jammes Rolfe", "Ben Croshaw" };

	string inputNumber;

	int array = 0;

	/**************************************************************************************/
	cin.ignore();
	
	while (userName.empty())
	{
		cout << "\n\nPlease enter in your name:";
		getline(cin, inputNumber);

		for (string number : {"1111", "2222", "3333", "4444", "5555"})
		{
			if (inputNumber == number)
			{
				userName = accountName[array];
				break;
			}
			array++;
		}

		if (userName.empty())
		{
			cout << "Invlaid input. Please try again.\n\n";
			array = 0;
			BoardClass::util.hitEnter();
			BoardClass::util.clearScreen();
		}
	}

	cout << "Thank you " << userName << " for signing in.\n\n";
	BoardClass::util.hitEnter();
	BoardClass::util.clearScreen();

}

///////////////////////////////////////////////////////////////////////////////

//NAME:			Logo
//DESCRIPTION:	Shows the user the programmers logo and clears the 
//				screen when enter is hit.

//Calls: hitEnter, clearScreen

//Called By: mainMenu, 

///////////////////////////////////////////////////////////////////////////////
void logo()
{
	cout << "You have select the logo option.\n";
	BoardClass::util.hitEnter();
	cin.ignore();

	cout << "                ..  ,dkOOOOOOkxdc'.	            \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "            .'dONXd. .cKWMMMMMMMMMN0c		    \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "          'xXWMMMMMNx'  :ONMMMMMMMMWk. c;.          \333\333\n"; Sleep(100);
	cout << "        ;OWMMMMMMMMMMW0c. 'oKWMMMMMMX. oNKl. 	    \333\333\n"; Sleep(100);
	cout << "      ,OWMMMMMWWWNXXK0Oxd,  .;kNMMMMN. ;NMWXc.	    \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "     .ool;,,,''....            .,dKWN; 'XMMMWO.	    \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "    ....,;;;ldl.                   ;kc .KMMMMMK,    \333\333\n"; Sleep(100);
	cout << "  .xWMMMMMMMWd.                      .  0MMMMMMK'   \333\333\n"; Sleep(100);
	cout << "  cNMMMMMMMN:                           dWMMMMWX:   \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << " .KMMMMMMMN:                            dWMMMNd. .  \333\333\333\333\333\333\333\n"; Sleep(100);
	cout << " ,NMMMMMW0,                             ;NMWk. .kx.\n"; Sleep(100);
	cout << " cNMMMMXc.                              .K0:  cXW0. \333        \333\n"; Sleep(100);
	cout << " cNMMWx._':                             .c. ;0WMMK. \333\333      \333\333\n"; Sleep(100);
	cout << " ,NWO,_.dW0                               .kWMMMWk. \333\333\333    \333\333\333\n"; Sleep(100);
	cout << " .Oc  cXMMX.                            .lXMMMMMNc  \333\333\333\333  \333\333\333\333\n"; Sleep(100);
	cout << "    ;KWMMMX;                           :KWMMMMMMK.  \333\333\333\333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "   oWMMMMMN;                         ,0WMMMMMMMN,   \333\333\333\333\333\333\333\333\333\333\n"; Sleep(100);
	cout << "   .0WMMMMWd .o;                   .xNWWWMWMMWK;    \333\333  \333\333  \333\333\n"; Sleep(100);
	cout << "    .kWMMMWO .kW0c.               .ll:::,......	    \333\333      \333\333\n"; Sleep(100);
	cout << "      :KWMMK. dWMMXd'        .....',;;;:lllo'	    \333\333      \333\333\n"; Sleep(100);
	cout << "       .lKWK. ;NMMMMWO:. .l0XNNNNNWWMMMMWNx.	    \333\333	    \333\333\n"; Sleep(100);
	cout << "         .:d' 'NMMMMMMMKl. .cKWMMMMMMMWKo.\n"; Sleep(100);
	cout << "              .0WWMMMMMMMNO:  ,xNMWNOo'\n"; Sleep(100);
	cout << "              .;oxOKXNNNNXO;  .:'.\n"; Sleep(100);
	cout << "                     .....\n\n"; Sleep(100);

	BoardClass::util.hitEnter();
	BoardClass::util.clearScreen();

	return;

}

///////////////////////////////////////////////////////////////////////////////

//NAME:			goSign
//DESCRIPTION:	Displays a error message telling the user to sign
//				in before the access the options and clears the screen.

//Calls: hitEnter, clearScreen

//Called By: mainMenu

///////////////////////////////////////////////////////////////////////////////
void goSignin()
{
	cout << "You most sign in before you access this option\n";
	BoardClass::util.hitEnter();
	cin.ignore();
	BoardClass::util.clearScreen();
}

void gameState(int &gameCount, string userName, vector<int> &gameScores)
{
	bool again = true;

	float speed = 0;

	cin.ignore();

	selectSpeed(speed);

	while (again)
	{
		++gameCount;
		SnakeGame(gameCount, userName, gameScores, speed);

		playAgain(again);
		system("CLS");
	}
}

void selectSpeed(float &speed)
{
	char speedSelect;

	while (true)
	{
		cout << "Select a speed.(F for Fast, M for medium and, S for Slow):";
		
		cin >> speedSelect;

		if (toupper(speedSelect) == 'F')
			speed = .05;
		else
			if (toupper(speedSelect) == 'M')
				speed = .10;
			else
				if (toupper(speedSelect) == 'S')
					speed = .15;
				else
				{
					cout << "Invlaid input. Please try again.\n\n";
					BoardClass::util.hitEnter();
					cin.ignore();
					BoardClass::util.clearScreen();
				}
		if (speed != 0)
		{
			system("CLS");
			break;
		}
			
	}

}

void SnakeGame(int gameCount, string userName, vector<int> &gameScores, float speed)
{
	BoardClass *game = new BoardClass();
	NChrono dt = NChrono();
	Direction direct = RIGHT;
	
	bool running = true, pause = false;
	float time = speed;

	dt.setThrottle(time);

	showScore(0, 0, game, gameCount, userName, gameScores);

	while (running)
	{
		
		if (!pause)
		{
			arrowKeys(game, direct);

			if (dt.check())
			{
				if (game->checkMove(direct))
				{
					gameOver(game);
					gameScores.push_back(game->playerScore);
					delete game;
					game = nullptr;
					running = false;
				}
				else
				{
					showScore(0, 0, game, gameCount, userName, gameScores);
					game->moveSnake();
					dt.reset();
				}
			}
		}
		
		checkPause(game, pause, direct);
		
	}
	cin.ignore();
	cin.ignore();
	

}

void arrowKeys(BoardClass *game, Direction &snakeDirect)
{
	if (GetKeyState(VK_LEFT) < 0 && game->checkBehind(-1, 0))
			snakeDirect = LEFT;
	else
		if (GetKeyState(VK_RIGHT) < 0 && game->checkBehind(1,0))
				snakeDirect = RIGHT;
		else
			if (GetKeyState(VK_UP) < 0 && game->checkBehind(0, -1))
					snakeDirect = UP;
			else
				if (GetKeyState(VK_DOWN) < 0 && game->checkBehind(0, 1))
						snakeDirect = DOWN;
	
}

void moverCursor(int x, int y, BoardClass *game)
{
	game->util.moveCursor(x, y);
	cout << "\t\t";

	game->util.moveCursor(x, y);
	game->getXY();


}

void showScore(int x, int y, BoardClass *game, int gameCount, string userName, vector<int> gameScores)
{

	game->util.moveCursor(x, y);

	sort(gameScores.begin(), gameScores.end());

	if (gameScores.size() >= 1)
		cout << "Game# " << gameCount << " " << userName << " HighScore: " << gameScores[gameScores.size() - 1] << " Score:" << game->playerScore << " ";
	else
		cout << "Game# " << gameCount << " " << userName << " Score:" << game->playerScore << " " << game->foodAte;

}

void gameOver(BoardClass *game)
{
	int xPos = 35, yPos = 15;

	game->util.moveCursor(xPos, yPos);

	cout << "Game Over.";

}

void checkPause(BoardClass *game, bool &pause, Direction &snakeDirect)
{

	DWORD        mode;          /* Preserved console mode */
	DWORD count;  /* ignored */
	INPUT_RECORD event;         /* Input event */
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE); /* Get the console input handle */

	/* Preserve the original console mode */
	GetConsoleMode(hstdin, &mode);

	/* Set to no line-buffering, no echo, no special-key-processing */
	SetConsoleMode(hstdin, 0);


	if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0)
	{

		/* Get the input event */
		ReadConsoleInput(hstdin, &event, 1, &count);

		/* Only respond to key release events */
		if ((event.EventType == KEY_EVENT)
			&& !event.Event.KeyEvent.bKeyDown)
			switch (event.Event.KeyEvent.wVirtualKeyCode)
		{
			case 'P':
				if (pause)
				{
					pause = false;
					game->util.moveCursor(55, 0);
					cout << "\t\t\t";
				}
				else
				{
					pause = true;
					game->util.moveCursor(55, 0);
					cout << "Game Paused";
				}
				break;
		}
	}

	SetConsoleMode(hstdin, mode);
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			playAgain
//DESCRIPTION:	Tells the user the number of games they played using
//				gameNumber and userName to tell the user by name. Set
//				up the vector gameNumbers and shows the amount of games
//				played and the scores

//Calls: hitEnter, clearScreen

//Called By: mainMenu, 

///////////////////////////////////////////////////////////////////////////////

void playAgain(bool &again)
{
	int xPos = 25, yPos = 15;
	string select;
	char letter;

	BoardClass::util.moveCursor(xPos, yPos);
	
	while (true)
	{

		cout << "Would you like to play again Y/N:";
		getline(cin, select);

		 if (select == "Y" || select == "y")
		{
			again = true;
			break;
		}
		else
			if (select == "N" || select == "n")
			{
				again = false;
				break;
			}
			else
			{
				BoardClass::util.moveCursor(xPos, yPos);
				cout << "Invalid input.\t\t\t\t";
				BoardClass::util.moveCursor(xPos, yPos);
			}
	}
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			gameHistory
//DESCRIPTION:	Tells the user the number of games they played using
//				gameNumber and userName to tell the user by name. Set
//				up the vector gameNumbers and shows the amount of games
//				played and the scores

//Calls: hitEnter, clearScreen

//Called By: mainMenu, 

///////////////////////////////////////////////////////////////////////////////

void gameHistory(int gameNumber, vector<int> gameScore, string userName)
{
	vector<int> gameNumbers;

	cout << "\n\tYou chose to see the Game History.\n";
	BoardClass::util.hitEnter();
	cin.ignore();

	cout << "You have played " << gameNumber << " games so far, " << userName << ":\n\n";

	for (int i = 0; i < gameNumber; i++)
	{
		gameNumbers.push_back(i+1);
		cout << "Game#" << gameNumbers[i] << ": " << gameScore[i] << "\n";
	}

	BoardClass::util.hitEnter();
	BoardClass::util.clearScreen();

}

///////////////////////////////////////////////////////////////////////////////

//NAME:			saveHistory
//DESCRIPTION:	Writes in the file you send in using textFile, saves 
//				stores the games written in the oldGame vector so they wont be 
//				written again and before writing checks if the High Score is being
//				being written and sorts the struct.

//Calls: sortScore, hitEnter, clearScreen

//Called By: mainMenu

///////////////////////////////////////////////////////////////////////////////

void saveHistory(string userName,vector<int> gameScore, vector<vector<int>> &oldGame, string textFile, bool &checkName)
{
	/*************************************************************************************
	****		LOCAL VARIABLE DEFINITIONS
	**************************************************************************************/

	string gameFile(textFile);

	vector<int> gameNumbers;

	ofstream outPutfile(gameFile, ios::app);

	/**************************************************************************************/

	cout << "You chose to show the save file.\n";
	BoardClass::util.hitEnter();
	cin.ignore();

	for (int i = 0; i < gameScore.size(); i++)
		gameNumbers.push_back(i + 1);

	if (outPutfile.fail())
		cout << "Can't open file.";
	else
	{
		if (textFile == "High Score.txt")
		{
			sortScore(gameNumbers, gameScore);
			sort(oldGame.begin(), oldGame.end());
			if (!checkName)
			{
				outPutfile << userName << "\n";
				outPutfile << "High Score Table:\n";
				checkName = true;
			}
			
		}

		for (int i = 0; i < gameScore.size(); i++)
			if (oldGame[i][0] != gameNumbers[i] && oldGame[i][1] != gameScore[i])
			{
				outPutfile << "Game#" << gameNumbers[i] << ": " << gameScore[i] << "\n";
				cout << "Thanks - I will add \042Game#" << gameNumbers[i] << ": " << gameScore[i] << "\042 to my dictionary.\n";
				oldGame[i][1] = gameScore[i];
				oldGame[i][0] = gameNumbers[i];
			}
	}

	outPutfile.close();

	BoardClass::util.hitEnter();
	BoardClass::util.clearScreen();
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			highScore
//DESCRIPTION:	Tells the user the number of games they played using
//				gameNumber and userName to tell the user by name. Set
//				up the vector gameNumbers and sorts the score by Highest
//				to Lowest.

//Calls: hitEnter, clearScreen, sortScore

//Called By: mainMenu, 

///////////////////////////////////////////////////////////////////////////////

void highScore(int gameNumber, vector<int> gameScore, string userName)
{
	vector<int> gameNumbers;

	for (int i = 0; i < gameNumber; i++)
		gameNumbers.push_back(i + 1);

	sortScore(gameNumbers, gameScore);

	cout << "From highest to lowest : ";
	for (int i = 0; i < gameNumber; i++)
		cout << gameScore[i] << " ";

	cout << "\n\nHigh Score Table:" << endl;

	for (int i = 0; i < gameNumber; i++)
		cout << "Game#" << gameNumbers[i] << ": " << gameScore[i] << "\n";

	BoardClass::util.hitEnter();
	BoardClass::util.clearScreen();
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			sortScore
//DESCRIPTION:	Uses the vector gameNumber in a while and for loop to sort
//				the vectors gameScore and gameNumber in the struct gameHistory.

//Calls: 

//Called By: highScore, saveHistory

///////////////////////////////////////////////////////////////////////////////
void sortScore(vector<int> &gameNumbers, vector<int> &gameScore)
{
	double a, b;
	int gNumber, i = 0;

	while (i < gameNumbers.size())
	{
		for (int i = 0; i < gameNumbers.size() - 1; i++)
		{
			a = gameScore[i];
			b = gameScore[i + 1];
			gNumber = gameNumbers[i];

			if (a < b)
			{
				gameScore[i] = b;
				gameNumbers[i] = gameNumbers[i + 1];

				gameScore[i + 1] = a;
				gameNumbers[i + 1] = gNumber;
			}
		}
		i++;
	}
}

///////////////////////////////////////////////////////////////////////////////

//NAME:			exitProgram
//DESCRIPTION:	Postcondition: Says goodbye to the user by their name and says  
//				the uses the const string to show the program 1s title. Also 
//				shows the date, time, the ID info, and stars that were done.

//Calls: hitEnter, clearScreen

//Called By: mainMenu, 

///////////////////////////////////////////////////////////////////////////////
void exitProgram(string userName, const string NAME)
{
	cout << "\n\t You chose to exit\n\n";
	BoardClass::util.hitEnter();
	cin.ignore();

	cout << "Good bye " << userName << " and thanks for visiting " << NAME
		<< "'s Snake Alive game.\n";
	system("date /t");
	system("time /t");
	Sleep(150);

	cout << "\t\t\tID INFORMATION\n"
		<< "\tProgrammers\t\t:\tEddie Meza Jr.\n"
		<< "\tAssignment #\t\t:\tFinal Project\n"
		<< "\tAssignment Name\t\t:\tSnake Alive\n"
		<< "\tCourse # and Title\t:\tCISC 205 - OOPS\n"
		<< "\tClass Meeting Time\t:\tTTH 9 : 35 - 12 : 35\n"
		<< "\tInstructor\t\t:\tProfessor Forman\n"
		<< "\tHours\t\t\t:\t15H\n"
		<< "\tDifficulty\t\t:\t8\n"
		<< "\tCompletion Date\t\t:\t12/14/2014\n"
		<< "\tProject Name\t\t:\tEddie Meza Final Project\n\n"; Sleep(150);

	cout << "Stars\n"
		/*<< "1.STAR: Effectively use an iterator.\n\n"
		<< "2.STAR: Use a different ASCII character for the head of the snake and for the body of the snake.\n\n"
		<< "3.STAR: D. Continuously display during game-play, the game number, player’s name and currently\n"
		<< "updated score in the game \n\n"
		<< "4.STAR: Expand previous STAR to also display player’s highest score from all the games played\n"
		<< "in the current session\n\n"
		<< "5.STAR: Have the food randomly appearing only in places not occupied by any part of the snake\n"
		<< "and not embedded in the wall\n\n"
		<< "6.STAR: After the snake “eats” 5 pieces of food, have an additional piece of food randomly\n"
		<< "appear inside the playing area\n\n"
		<< "7.STAR: Expand the previous STAR to have the new food item be a different color and worth\n"
		<< "2 points, not the usual 1\n\n"
		<< "8.STAR: Expand the previous STAR to have the new food item disappear after 5 seconds if\n"
		<< "snake does not “eat” it\n\n"
		<< "9.STAR: Ensure when player moves snake horizontally in one direction that player cannot\n"
		<< "move horizontally in the opposite direction. Similarly, handle situation when moving\n"
		<< "vertically. I.e., The snake is moved with the keyboard function arrow keys – left,\n"
		<< "right, up, and down. Do not allow the snake to turn 180 degrees and move over itself.\n"
		<< "The snake must turn at right angles, with each segment turning at the same spot.\n\n"
		<< "10.STAR: L. Include a menu with options for:\n"
		<< "Instructions for playing the game\n"
		<< "Logging in where the only valid account numbers are 1111, 2222, 3333, 4444 and 5555\n"
		<< "which belong respectively to Albert Einstein, Madame Curie, yourself, and two people\n"
		<< "whom you admire.Do “error - checking” for “dirty” data and proceed only when a valid\n"
		<< "account number is entered\n"
		<< "Playing the game\n"
		<< "Display the game “history” : the game number, player’s name and player’s score of\n"
		<< "each game played in a single session\n"
		<< "Exiting the game\n\n"
		<< "11.STAR: Expand the previous STAR to include a menu item for the High Scores that\n"
		<< "include the game history information in numerical order from high to low\n\n"
		<< "12.STAR: Expand the previous STAR to include a menu item for storing and retrieving\n"
		<< "High Scores via a disk file that contains the High Scores across multiple sessions.\n\n"
		<< "13.STAR: Provide player with way to select speed of snake movement via three options\n"
		<< "of “slow”, “medium” and “speedy”\n\n"
		<< "14.STAR: Provide a way for user to pause game while playing and then can resume play\n\n"*/
		<< "Total Stars: 0\n\n"; Sleep(150);

	BoardClass::util.hitEnter();

	exit(EXIT_SUCCESS);
}
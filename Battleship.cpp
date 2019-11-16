// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>

int maxShips = 10;
const int smallRow = 8;
const int smallCols = 8;
int smallBoard[smallRow][smallCols]; //just make seperate things for ai shit. (AISmallClear, AISmallAttack, etc)... maybe a robot void function
//int aismallBoard[rows][columns];
const int medRow = 46;
const int medCols = 46;
int medBoard[medRow][medCols];
const int bigRow = 100;
const int bigCols = 100;
int bigBoard[bigRow][bigCols];

void SmallClear()
{
	for (int i = 0; i < smallRow; i++)
	{
		for (int j = 0; j < smallCols; j++)
		{
			smallBoard[i][j] = 0;
		}
	}
}

void SmallShow()
{
	for (int i = 0; i < smallRow; i++)
	{
		for (int j = 0; j < smallCols; j++)
		{
			std::cout << smallBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void MedClear()
{
	for (int i = 0; i < medRow; i++)
	{
		for (int j = 0; j < medCols; j++)
		{
			medBoard[i][j] = 0;
		}
	}
}

void MedShow()
{
	for (int i = 0; i < medRow; i++)
	{
		for (int j = 0; j < medCols; j++)
		{
			std::cout << medBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void BigClear()
{
	for (int i = 0; i < bigRow; i++)
	{
		for (int j = 0; j < bigCols; j++)
		{
			bigBoard[i][j] = 0;
		}
	}
}

void BigShow()
{
	for (int i = 0; i < bigRow; i++)
	{
		for (int j = 0; j < bigCols; j++)
		{
			std::cout << bigBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int SmallNumberOfShips()
{
	int c = 0;
	for (int i = 0; i < smallRow; i++)
	{
		for (int j = 0; j < smallCols; j++)
		{
			if (smallBoard[i][j] == 1)
			{
				c++;
			}
		}
	}
	return c;
}

int MedNumberOfShips()
{
	int c = 0;
	for (int i = 0; i < medRow; i++)
	{
		for (int j = 0; j < medCols; j++)
		{
			if (medBoard[i][j] == 1)
			{
				c++;
			}
		}
	}
	return c;
}

int BigNumberOfShips()
{
	int c = 0;
	for (int i = 0; i < bigRow; i++)
	{
		for (int j = 0; j < bigCols; j++)
		{
			if (bigBoard[i][j] == 1)
			{
				c++;
			}
		}
	}
	return c;
}

void SmallPlaceShips()
{
	int s = 0;
	while (s < maxShips)
	{
		int x = rand() % smallRow;
		int y = rand() % smallCols;
		if (smallBoard[x][y] != 1)
		{
			s++;
			smallBoard[x][y] = 1; 
		}
	}
}

void MedPlaceShips()
{
	int s = 0;
	while (s < maxShips)
	{
		int x = rand() % medRow;
		int y = rand() % medCols;
		if (medBoard[x][y] != 1)
		{
			s++;
			medBoard[x][y] = 1;
		}
	}
}

void BigPlaceShips()
{
	int s = 0;
	while (s < maxShips)
	{
		int x = rand() % bigRow;
		int y = rand() % bigCols;
		if (bigBoard[x][y] != 1)
		{
			s++;
			bigBoard[x][y] = 1;
		}
	}
}

bool SmallAttack(int x, int y)
{
	if (smallBoard[x][y] == 1)
	{
		std::cout << "Hit!" << std::endl;
		smallBoard[x][y] = 2;
		return true;
	}
	if(smallBoard[x][y+1] == 1 || smallBoard[x][y-1] == 1 || smallBoard[x+1][y] == 1 || smallBoard[x-1][y] == 1 || smallBoard[x-1][y-1] || smallBoard[x+1][y+1] || smallBoard[x+1][y-1] || smallBoard[x-1][y+1])
	{
		std::cout << "Near Miss!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Miss!" << std::endl;
		return false;
	}
}

bool MedAttack(int x, int y)
{ 
	if (medBoard[x][y] == 1)
	{
		std::cout << "Hit" << std::endl;
		medBoard[x][y] = 2;
		return true;
	}
	if (medBoard[x][y + 1] == 1 || medBoard[x][y - 1] == 1 || medBoard[x + 1][y] == 1 || medBoard[x - 1][y] == 1 || medBoard[x - 1][y - 1] || medBoard[x + 1][y + 1] || medBoard[x + 1][y - 1] || medBoard[x - 1][y + 1])
	{
		std::cout << "Near Miss!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Miss!" << std::endl;
		return false;
	}
}

bool BigAttack(int x, int y)
{ 
	if (bigBoard[x][y] == 1)
	{
		std::cout << "Hit" << std::endl;
		bigBoard[x][y] = 2;
		return true;
	}
	if (bigBoard[x][y + 1] == 1 || bigBoard[x][y - 1] == 1 || bigBoard[x + 1][y] == 1 || bigBoard[x - 1][y] == 1 || bigBoard[x - 1][y - 1] || bigBoard[x + 1][y + 1] || bigBoard[x + 1][y - 1] || bigBoard[x - 1][y + 1])
	{
		std::cout << "Near Miss!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Miss!" << std::endl;
		return false;
	}
}

void AIBattleShips()
{
	srand(time(NULL));
	int pos1;
	int pos2;
	int lastpos1;
	int lastpos2;
	int boardChoice;
	char prompt;

	std::cout << "Which board size do you want?\n1) Small (8x8)\n2) Medium (46x46)\n3) Big (100x100)" << std::endl;
	boardChoice = rand() % 3+1;
	switch (boardChoice)
	{
	case 1:
		SmallClear();
		SmallPlaceShips();
		while (1)
		{
			//initialize first vals for pos1 pos2, find way to tell AI that an attack was a near miss...
		}
		break;

	case 2:
		MedClear();
		MedPlaceShips();
		while (1)
		{

		}
		break;

	case 3:
		BigClear();
		BigPlaceShips();
		while (1)
		{

		}
		break;

	default:
		//don't really need this cuz the ai has boundries of what it can select...
		break;
	}
}
int main()
{
	srand(time(NULL));
	int pos1;
	int pos2;
	int boardChoice;
	char prompt;

	std::cout << "Which board size do you want?\n1) Small (8x8)\n2) Medium (46x46)\n3) Big (100x100)"; std::cin >> boardChoice;
	switch (boardChoice)
	{
	case 1:
		SmallClear();
		SmallPlaceShips();
		while (1)
		{
			std::cout << "Please input location "; std::cin >> pos1 >> pos2;
			if (SmallAttack(pos1, pos2))
			{
			}
			else
			{
			}
			std::cout << "Number of ships left:" << SmallNumberOfShips() << std::endl;
			std::cout << "Do you want to surrender? (y/n)"; std::cin >> prompt;
			if (prompt == 'y')
			{
			break;
			}
		}
		std::cout << "Game over" << std::endl;
		SmallShow();
		break;

	case 2:
		MedClear();
		MedPlaceShips();
		while (1)
		{
			std::cout << "Please input location "; std::cin >> pos1 >> pos2;
			if (MedAttack(pos1, pos2))
			{
			}
			else
			{
			}
			std::cout << "Number of ships left:" << MedNumberOfShips() << std::endl;
			std::cout << "Do you want to surrender? (y/n)"; std::cin >> prompt;
			if (prompt == 'y')
			{
				break;
			}
		}
		std::cout << "Game over" << std::endl;
		MedShow();
		break;

	case 3:
		BigClear();
		BigPlaceShips();
		while (1)
		{
			std::cout << "Please input location "; std::cin >> pos1 >> pos2;
			if (BigAttack(pos1, pos2))
			{
			}
			else
			{
			}
			std::cout << "Number of ships left:" << BigNumberOfShips() << std::endl;
			std::cout << "Do you want to surrender? (y/n)"; std::cin >> prompt;
			if (prompt == 'y')
			{
				break;
			}
		}
		std::cout << "Game over" << std::endl;
		BigShow();
		break;

	default:
		break;
	}
	return 0;
}
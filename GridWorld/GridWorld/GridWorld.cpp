// GridWorld.cpp : Basement simulator for the Deep Learning Project
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<random>

#include "World.h"


using namespace std;

struct location
{
	int x, y;
};

class validate
{
	bool checkTraps(location trap[7], location pos)
	{
		for (int i = 0; i < 7; i++)
		{
			if (pos.x == trap[i].x && pos.y == trap[i].y)
			{
				return true;
			}
		}
		return false;
	}


};

int main()
{
	location trap[7];
	trap[0].x = 1; trap[0].y = 3;
	trap[1].x = 2; trap[1].y = 7;
	trap[2].x = 3; trap[2].y = 4;
	trap[3].x = 5; trap[3].y = 2;
	trap[4].x = 6; trap[4].y = 5;
	trap[5].x = 6; trap[5].y = 7;
	trap[6].x = 7; trap[6].y = 2;

	location donut[4];
	donut[0].x = 1; donut[0].y = 1;
	donut[1].x = 1; donut[1].y = 8;
	donut[2].x = 8; donut[2].y = 1;
	donut[3].x = 8; donut[3].y = 8;

	location Tim;
	Tim.x = 3; Tim.y = 3;

	World();



	system("pause");
	return 0;
}
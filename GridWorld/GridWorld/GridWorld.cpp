// GridWorld.cpp : Basement simulator for the Deep Learning Project
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<random>

#include "World.h"


using namespace std;



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

	location Tim;
	Tim.x = 3; Tim.y = 3;

	World();



	system("pause");
	return 0;
}
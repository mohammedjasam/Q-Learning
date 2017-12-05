#include "stdafx.h"
#include "World.h"
#include<iomanip>
#include<map>
#include<conio.h>
#include <time.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>

using namespace std;

const int BASE_HEIGHT = 10;
const int BASE_WIDTH = 10;

char base[BASE_HEIGHT][BASE_WIDTH] = { { ' ' } };

location trap[7];

location donut[4];

location Tim;

int PlaceDonut(char base[10][10])
{
	srand(time(NULL));
	cout << "         IN PLACE DONUT FUNCTION    "<<endl<< "There is a donut: " << IS_THERE_DONUT_ON_MAP;

	if (IS_THERE_DONUT_ON_MAP != true)
	{
		double place_donut = rand() % 100;
		int the_corner = rand() % 4;
		cout <<"    The prob of donut is: " <<place_donut;

		if (place_donut < 25)
		{
			cout << "  placed in Corner: " << the_corner << endl;
			switch (the_corner)
			{
			case 0:
				base[1][1] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				return 0;
				break;
			case 1:
				base[1][8] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				return 1;
				break;
			case 2:
				base[8][1] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				return 2;
				break;
			case 3:
				base[8][8] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				return 3;
				break;
			}
		}
		else
		{
			//cout <<endl<< "No donut for Tim today prob was: " << place_donut << endl;
			return -1;
		}
	}
}


void dropTim(location Tim)
{
	cout << endl << "DROPPING TIMMMMMMM!!!!!!!" << endl;
	base[Tim.x][Tim.y] = 'R';
}

void renderWorld(location moved)
{
	int loc = PlaceDonut(base);

	

	base[Tim.x][Tim.y] = ' ';

	location recall = Tim;

	if (base[moved.x][moved.y] != 'X')
	{		
		base[moved.x][moved.y] = 'R';
		Tim.x = moved.x;
		Tim.y = moved.y;
		cout <<endl<< "Tims location " << Tim.x <<", " <<Tim.y<<endl;


		/*if (loc == 0)
		{
			if (base[1][1] == 'D' && Tim.x == 1 && Tim.y == 1)
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
		}
		else if (loc == 1)
		{
			if (base[1][8] == 'D' && Tim.x == 1 && Tim.y == 8)
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
		}
		else if (loc == 2)
		{
			if (base[8][1] == 'D' && Tim.x == 8 && Tim.y == 1)
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
			else if (base[8][1] == ' ')
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
		}
		else if (loc == 3)
		{
			if (base[8][8] == 'D' && Tim.x == 8 && Tim.y == 8)
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
			else if (base[8][8] == ' ')
			{
				IS_THERE_DONUT_ON_MAP = false;
			}
		}*/


	}
	else
	{
		base[recall.x][recall.y] = 'R';
	}

	if (((Tim.x == 1 && Tim.y == 1) && IS_THERE_DONUT_ON_MAP == true && loc == 0) || ((Tim.x == 1 && Tim.y == 8) && IS_THERE_DONUT_ON_MAP == true && loc == 1) || ((Tim.x == 8 && Tim.y == 1) && IS_THERE_DONUT_ON_MAP == true && loc == 2) || ((Tim.x == 8 && Tim.y == 8) && IS_THERE_DONUT_ON_MAP == true && loc == 3))
	{
		IS_THERE_DONUT_ON_MAP = false;
	}


	cout << endl << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;

	for (int i = 0; i < BASE_HEIGHT; i++)
	{
		cout << char(186);
		for (int j = 0; j < BASE_WIDTH; j++)
		{

			cout << setw(3) << base[i][j] << setw(3) << char(186);
			//cout << setw(3);

		}

		//cout <<endl<< "_______________________________________"<<endl;
		if (i != BASE_HEIGHT - 1)
		{
			cout << endl << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
		}
		else
		{
			cout << endl << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
		}

	}
}





struct direction
{
	int x;
};

void try_move(location Tim, int x, int y)
{
	Tim.x += x;
	Tim.y += y;
	//cout << "IM IN TRY MOVE";

	renderWorld(Tim);
}

void move_up(location Tim)
{
	try_move(Tim, 0, -1);
	//cout << "IM IN MOVE";
}

void move_down(location Tim)
{
	try_move(Tim, 0, 1);
}

void move_left(location Tim)
{
	try_move(Tim, -1, 0);
}

void move_right(location Tim)
{
	try_move(Tim, 1, 0);
}

void World()
{

	//location trap[7];
	trap[0].x = 1; trap[0].y = 3;
	trap[1].x = 2; trap[1].y = 7;
	trap[2].x = 3; trap[2].y = 4;
	trap[3].x = 5; trap[3].y = 2;
	trap[4].x = 6; trap[4].y = 5;
	trap[5].x = 6; trap[5].y = 7;
	trap[6].x = 7; trap[6].y = 2;

	//location donut[4];
	donut[0].x = 1; donut[0].y = 1;
	donut[1].x = 1; donut[1].y = 8;
	donut[2].x = 8; donut[2].y = 1;
	donut[3].x = 8; donut[3].y = 8;

	//location Tim;
	Tim.x = 3; Tim.y = 3;


	// Place walls
	base[0][0] = 'X';
	base[0][1] = 'X';
	base[0][2] = 'X';
	base[0][3] = 'X';
	base[0][4] = 'X';
	base[0][5] = 'X';
	base[0][6] = 'X';
	base[0][7] = 'X';
	base[0][8] = 'X';
	base[0][9] = 'X';

	base[9][0] = 'X';
	base[9][1] = 'X';
	base[9][2] = 'X';
	base[9][3] = 'X';
	base[9][4] = 'X';
	base[9][5] = 'X';
	base[9][6] = 'X';
	base[9][7] = 'X';
	base[9][8] = 'X';
	base[9][9] = 'X';

	base[1][0] = 'X';
	base[2][0] = 'X';
	base[3][0] = 'X';
	base[4][0] = 'X';
	base[5][0] = 'X';
	base[6][0] = 'X';
	base[7][0] = 'X';
	base[8][0] = 'X';

	base[1][9] = 'X';
	base[2][9] = 'X';
	base[3][9] = 'X';
	base[4][9] = 'X';
	base[5][9] = 'X';
	base[6][9] = 'X';
	base[7][9] = 'X';
	base[8][9] = 'X';

	base[6][4] = 'X';
	base[7][4] = 'X';
	base[8][4] = 'X';

	base[4][6] = 'X';
	base[5][6] = 'X';
	base[6][6] = 'X';

	base[2][4] = 'X';
	base[2][5] = 'X';
	base[2][6] = 'X';

	base[2][2] = 'X';
	base[3][2] = 'X';
	base[4][2] = 'X';

	
	dropTim(Tim);
	//cout << setw(10);

	renderWorld(Tim);

	int event = -1, i = 0;
	
	while (i < 100)
	{
		//event = rand() % 4;
		
		//if (event == 0) { move_up(Tim); }
		//else if (event == 1) { move_down(Tim); }
		//else if (event == 2) { move_right(Tim); }
		//else if (event == 3) { move_left(Tim); }
		//std::this_thread::sleep_for(std::chrono::seconds(1));


		cin >> event;

		if (event == 4) { move_up(Tim); }
		else if (event == 6) { move_down(Tim); }
		else if (event == 2) { move_right(Tim); }
		else if (event == 8) { move_left(Tim); }

	}
}

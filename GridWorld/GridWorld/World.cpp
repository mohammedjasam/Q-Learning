#include "stdafx.h"
#include "World.h"
#include<iomanip>
#include<map>
#include<conio.h>

using namespace std;

const int BASE_HEIGHT = 10;
const int BASE_WIDTH = 10;

char base[BASE_HEIGHT][BASE_WIDTH] = { { ' ' } };

location trap[7];

location donut[4];

location Tim;



void dropTim(location Tim)
{
	cout << endl << "DROPPING TIMMMMMMM!!!!!!!" << endl;
	base[Tim.x][Tim.y] = 'R';

}

void renderWorld(location moved)
{
	base[Tim.x][Tim.y] = ' ';
	location recall = Tim;
	if (base[moved.x][moved.y] != 'W')
	{
		base[moved.x][moved.y] = 'R';
		Tim.x = moved.x;
		Tim.y = moved.y;
	}
	else
	{
		base[recall.x][recall.y] = 'R';
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

void PlaceDonut(char base[10][10])
{
	srand(time(NULL));
	//cout << "IN PLACE DONUT FUNCTION";

	if (IS_THERE_DONUT_ON_MAP != true)
	{
		double place_donut = rand() % 100;
		int the_corner = rand() % 4;


		if (place_donut < 25)
		{
			cout << "Placing Donut in Corner: " << the_corner<<endl;
			switch (the_corner)
			{
			case 0:
				base[1][1] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				break;
			case 1:
				base[1][8] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				break;
			case 2:
				base[8][1] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				break;
			case 3:
				base[8][8] = 'D';
				IS_THERE_DONUT_ON_MAP = true;
				break;
			}
		}
		else
		{
			cout << "No donut for Tim today prob was: " << place_donut<<endl;
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
	cout << "IM IN TRY MOVE";

	renderWorld(Tim);
}

void move_up(location Tim)
{
	try_move(Tim, 0, -1);
	cout << "IM IN MOVE";
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
	base[0][0] = 'W';
	base[0][1] = 'W';
	base[0][2] = 'W';
	base[0][3] = 'W';
	base[0][4] = 'W';
	base[0][5] = 'W';
	base[0][6] = 'W';
	base[0][7] = 'W';
	base[0][8] = 'W';
	base[0][9] = 'W';

	base[9][0] = 'W';
	base[9][1] = 'W';
	base[9][2] = 'W';
	base[9][3] = 'W';
	base[9][4] = 'W';
	base[9][5] = 'W';
	base[9][6] = 'W';
	base[9][7] = 'W';
	base[9][8] = 'W';
	base[9][9] = 'W';

	base[1][0] = 'W';
	base[2][0] = 'W';
	base[3][0] = 'W';
	base[4][0] = 'W';
	base[5][0] = 'W';
	base[6][0] = 'W';
	base[7][0] = 'W';
	base[8][0] = 'W';

	base[1][9] = 'W';
	base[2][9] = 'W';
	base[3][9] = 'W';
	base[4][9] = 'W';
	base[5][9] = 'W';
	base[6][9] = 'W';
	base[7][9] = 'W';
	base[8][9] = 'W';

	base[6][4] = 'W';
	base[7][4] = 'W';
	base[8][4] = 'W';

	base[4][6] = 'W';
	base[5][6] = 'W';
	base[6][6] = 'W';

	base[2][4] = 'W';
	base[2][5] = 'W';
	base[2][6] = 'W';

	base[2][2] = 'W';
	base[3][2] = 'W';
	base[4][2] = 'W';

	PlaceDonut(base);
	dropTim(Tim);
	//cout << setw(10);

	renderWorld(Tim);

	int event = -1;

	while (event != 27)
	{
		cin >> event ;
		cout << event;

		if (event == 4) { move_up(Tim); }
		else if (event == 6) { move_down(Tim); }
		else if (event == 2) { move_right(Tim); }
		else if (event == 8) { move_left(Tim); }

		//switch(event)
		//{
		//	case 22472:
		//		cout << "IM IN SWITCH";
		//		move_up(Tim);
		//		break;
		//	case 22480:
		//		move_down(Tim);
		//		break;
		//	case 22477:
		//		move_right(Tim);
		//		break;
		//	case 22475:
		//		move_left(Tim);
		//		break;
		//}
	}
}

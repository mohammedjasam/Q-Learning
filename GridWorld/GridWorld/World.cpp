#include "stdafx.h"
#include "World.h"
#include<iomanip>
#include<map>

using namespace std;



void PlaceDonut(char base[10][10])
{
	srand(time(NULL));
	cout << "IN PLACE DONUT FUNCTION";

	if (IS_THERE_DONUT_ON_MAP != true)
	{
		double place_donut = rand() % 100;
		int the_corner = rand() % 4;


		if (place_donut < 25)
		{
			cout << "Placing Donut in Corner: " << the_corner;
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
			cout << "No donut for Tim today prob was: " << place_donut;
		}
	}
}

void dropTim(char base[10][10])
{
	cout << endl << "DROPPING TIMMMMMMM!!!!!!!" << endl;

}

void World()
{
	const int BASE_HEIGHT = 10;
	const int BASE_WIDTH = 10;

	char base[BASE_HEIGHT][BASE_WIDTH] = { { ' ' } };

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

	//cout << setw(10);
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
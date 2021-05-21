#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Dartboard.h"
#include "Player.h"

using namespace std;


void games()  //10000, 13sets, 5 games
{

	string name0 = "Joe";
	string name1 = "Sid";


	Player Players[2]; //creates an array of 

	Players[0].name = "Joe";
	Players[0].chance = 71;
	Players[0].score = 501;

	Players[1].name = "Sid";
	Players[1].chance = 73;
	Players[1].score = 501;

	Dartboard dartboard;

	bool done = false;

	int n_games = 0;

	for (int i = 0; i < 1000; i++)//10000 matches
	{
		for (int j = 0; j < 13; j++)//13 sets
		{
			//cout << "set " << j << endl;
			for (int k = 0; k < 5; k++)// 5 games
			{
				//cout << "game " << k << endl;
				done = false;

				for (int p = 0; p < 2 && !done; p++) // if done isnt true it runs again
				{
					Players[p].score = 501;
				}

				do//1 game
				{
					n_games++;
					
					for (int p = 0; p < 2 && !done; p++) // if done isnt true it runs again
					{
						//cout << Players[p].name << endl;

						for (int q = 0; q < 3 && !done; q++)
						{
							Players[p].playerthrow(dartboard);

							//cout << Players[p].score << endl;


							if (Players[p].score == 0)
							{
								done = true; //if score = 0 after throw then it is done
								Players[p].Scores_games++;

								/*if (Players[p].Scores_games == 3)
								{
								Players[p].Scores_games = 0;
								Players[p].Scores_sets++;

								if (Players[p].Scores_sets == 7)
								{
								Players[p].Scores_sets = 0;
								Players[p].Scores_matches++;



								}

								}*/


							}

						}

					}

				} while (!done); //equal to done

			}
		}

	}

	cout << n_games << endl;
	cout << name0 << " " << Players[0].Scores_games << endl;
	cout << name1 << " " << Players[1].Scores_games << endl;

}


int main() //main
{

	games();//function prototype 


	Player Players[2]; //creates an array of player objects

	srand(time(0)); //random number generator


	Players[0].name = "Joe";
	Players[0].chance = 71;
	Players[0].score = 501;



	Players[1].name = "Sid";
	Players[1].chance = 73;
	Players[1].score = 501;

	Dartboard dartboard;


	system("pause");

	return 0;

}
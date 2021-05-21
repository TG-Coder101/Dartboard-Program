#include "Player.h"
#include <iostream>


using namespace std;


void Player::playerthrow(Dartboard& Board)
{

	int actual_score;
	bool done = false;



	if (score >= 110) //throw triple 20 until 110 is met
	{
		actual_score = Board.throw_treble(20, chance);
		//cout << "treble_20" << endl;
	}
	else
	{
		if (score == 50) //throw a bullseye to win
		{

			actual_score = Board.throw_bull(chance);
			//cout << "bull" << endl;
		}
		else if (score >= 2 && score <= 40 && score % 2 == 0) //if score = double
		{
			actual_score = Board.throw_double(score / 2);
			//cout << "double" << score/2 << endl;
		}
		else
		{
			for (int i = 2; i <= 50 && !done; i += (i == 40) ? 10 : 2) //shorthand for loop
			{
				for (int j = 1; j <= 3 && !done; j++) //for every double single multiplier 
				{
					for (int z = 1; z <= 25 && !done; z += (z == 20) ? 5 : 1) //every base value
					{
						if (!(j == 3 && z == 25)) //exclude triple 25
						{

							int value = z * j;

							if (score - value == i) //if this throw leads to a double
							{

								if (value == 50)
								{
									actual_score = Board.throw_bull(chance);
									//cout << "bull" << endl;
									done = true;
								}


								switch (j) //choose right throw function
								{

								case 1:
									actual_score = Board.throw_single(z);
									//cout << "single" << z << endl; break;

								case 2:
									actual_score = Board.throw_double(z);
									//cout << "double" << z << endl; break;

								case 3:
									actual_score = Board.throw_treble(z, chance);
									//cout << "treble" << z << endl; break;
								}

								done = true;

							}

						}

					}

				}

			}
			if (!done)
			{

				actual_score = Board.throw_treble(20, chance);
				//cout << "treble_20" << endl;
			}
		}
	}

	if (actual_score <= score)
	{
		score -= actual_score;
	}
}


Player::Player()
{
}


Player::~Player()
{
}

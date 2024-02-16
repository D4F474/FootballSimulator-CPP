#include "CActions.h"

CActions::CActions()
{
	srand(time(NULL));
}
unsigned short ChanceOfSuccess()
{
	return rand() % 1 + 0;
}
unsigned short LongOrShort()
{
	return rand() % 1 + 0;
}

unsigned short CActions::randNumGenerator(unsigned short number)
{
	return rand() % number + 0;
}

float randomDouble() 
{
	return static_cast<float>(rand()) / RAND_MAX;
}
unsigned short CActions::PositionOfBall()
{
	return rand() % 3 + 1;
	//1 deffend side 2 mid side 3 attackers side
}
void CActions::FirstWhistle()
{
	randNumber = rand() % 1 + 0;
	Ball = randNumber;
}

bool CActions::simulateAlgorithm(float AStatOne,float AStatTwo,float AStatThree, float DStatOne, float DStatTwo, float DStatThree)
{
	// Изчисляване на общия успех на удара
	double totalSuccess = 0;
	for (int i = 0; i < 3; i++) {
		totalSuccess += ((AStatOne / 100) + (AStatTwo /100) + (AStatThree / 100)) * randomDouble();
	}
	double totalFailure = 0.17;
	for (int i = 0; i < 3; i++) {
		totalFailure += ((AStatOne / 100) + (AStatTwo / 100) + (AStatThree / 100)) * randomDouble();
	}

	// Ако общият успех на удара надвишава общия неуспех на вратаря, то ударът е успешен
	return totalSuccess > totalFailure;
}

void CActions::Shoot(CTeam& team1, CTeam& team2)
{
	successChance = 0; 
	unsigned short positionOfBall = PositionOfBall();
	unsigned short longOrShortShoot = LongOrShort();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;

	if (Ball == 0)
	{
		switch (positionOfBall)
		{
		case 1: //deffender 
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
			playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) // deffender vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else 
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else 
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else 
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling())) 
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //mid vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber <11)
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //Attacker vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			break;
		case 2: //middfielder
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //deffernder vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //mid vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //attacker vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			break;
		case 3://attacker
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //deffernder vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;

						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //mid vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getVision())) //attacker vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
							playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getFinishing(), playerHomeTeam->getPositionStats()->getShotPower(), playerHomeTeam->getPositionStats()->getLongShot(),
						playerAwayTeam->getPositionStats()->getGKPossitioning(), playerAwayTeam->getPositionStats()->getReflexes(), playerAwayTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team1.getStats()->incrementGoals();
						Ball = 1;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						Ball = 1;
					}
				}
			}
			break;
		}
	}
	else if (Ball = 1)
	{
		switch (positionOfBall)
		{
		case 1: //deffender 
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) // deffender vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementShotsOnTarget();
							team2.getStats()->incrementGoals();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotsOnTarget();
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementShotsOnTarget();
						team2.getStats()->incrementGoals();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementShotsOnTarget();
						std::cout << "superb save by the keeper!";
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //mid vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				playerAwayTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //Attacker vs deffender
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			break;
		case 2: //middfielder
			playerHomeTeam = team1.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //deffernder vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementShotsOnTarget();
							team2.getStats()->incrementGoals();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //mid vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //attacker vs mid
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			break;
		case 3://attacker
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //deffernder vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;

						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerHomeTeam = team1.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //mid vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerAwayTeam = team2.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementShotsOnTarget();
							team2.getStats()->incrementGoals();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotsOnTarget();
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementShotsOnTarget();
						team2.getStats()->incrementGoals();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (longOrShortShoot == 0) // gk with deffender "long shoot"
				{
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getVision())) //attacker vs attacker
					{
						team1.getStats()->incrementShotsOnTarget();
						playerHomeTeam = team1.getGKPlayer();
						if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
							playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
						{
							std::cout << "GOALLLL!!!! HOME Defender scores by long shoot!";
							team2.getStats()->incrementShotsOnTarget();
							team2.getStats()->incrementGoals();
							Ball = 0;
						}
						else
						{
							std::cout << "superb save by the keeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "That was far away from goal! I think he hit the plane!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else
				{
					playerAwayTeam = team2.getGKPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getFinishing(), playerAwayTeam->getPositionStats()->getShotPower(), playerAwayTeam->getPositionStats()->getLongShot(),
						playerHomeTeam->getPositionStats()->getGKPossitioning(), playerHomeTeam->getPositionStats()->getReflexes(), playerHomeTeam->getPositionStats()->getGKHandling()))
					{
						std::cout << "GOALLLL!!!! HOME Defender scores by short shoot!";
						team2.getStats()->incrementShotsOnTarget();
						team2.getStats()->incrementGoals();
						Ball = 0;
					}
					else
					{
						std::cout << "superb save by the keeper!";
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
				}
			}
			break;
		}
	}
}

void CActions::Pass(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	if (Ball == 0)
	{
		switch (positionOfBall)
		{
			case 1: // deffenders
				playerAwayTeam = team2.getDeffenderPlayer();
				if (LongOrShort() == 0)
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs deffender
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength())) 
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else 
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs deffender
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs deffender
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				else 
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs deffender
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs deffender
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs deffender
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				break;
			case 2://midfielders
				playerAwayTeam = team2.getMidPlayer();
				if (LongOrShort() == 0)
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs midfielders
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs midfielders
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs midfielders
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				else
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs midfielders
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs midfielders
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs midfielders
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				break;
			case 3 : //attackers
				playerAwayTeam = team2.getAttacker();
				if (LongOrShort() == 0)
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs attacker
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs attacker
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getLongPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				else
				{
					if (randNumber > 0 && randNumber < 5) //deffender vs attacker
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 4 && randNumber < 8)// mid vs attacker
					{
						playerHomeTeam = team1.getMidPlayer();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by midfielder!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
					else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
					{
						playerHomeTeam = team1.getAttacker();
						if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getStrength(),
							playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							std::cout << "Incredible long pass by attacker!";
							team1.getStats()->incrementPasses();
							Ball = 0;
						}
						else
						{
							std::cout << "Bad pass that was nice tackle!";
							team2.getStats()->incrementTackles();
							Ball = 1;
						}
					}
				}
				break;
		}
	}
	else if (Ball == 1)
	{
		switch (positionOfBall)
		{
		case 1: // deffenders
			playerHomeTeam = team1.getDeffenderPlayer();
			if (LongOrShort() == 0)
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs deffender
				{
					playerAwayTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs deffender
				{
					playerAwayTeam = team2.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs deffender
				{
					playerAwayTeam = team2.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			else
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs deffender
				{
					playerAwayTeam = team2.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs deffender
				{
					playerAwayTeam = team2.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs deffender
				{
					playerAwayTeam = team2.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			break;
		case 2://midfielders
			playerHomeTeam = team1.getMidPlayer();
			if (LongOrShort() == 0)
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs midfielders
				{
					playerAwayTeam = team2.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs midfielders
				{
					playerAwayTeam = team2.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs midfielders
				{
					playerAwayTeam = team2.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			else
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs midfielders
				{
					playerAwayTeam = team2.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs midfielders
				{
					playerAwayTeam = team2.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs midfielders
				{
					playerAwayTeam = team2.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			break;
		case 3: //attackers
			playerHomeTeam = team2.getAttacker();
			if (LongOrShort() == 0)
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs attacker
				{
					playerAwayTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs attacker
				{
					playerAwayTeam = team2.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
				{
					playerAwayTeam = team2.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getLongPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			else
			{
				if (randNumber > 0 && randNumber < 5) //deffender vs attacker
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 4 && randNumber < 8)// mid vs attacker
				{
					playerAwayTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by midfielder!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
				else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
				{
					playerAwayTeam = team1.getAttacker();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Incredible long pass by attacker!";
						team2.getStats()->incrementPasses();
						Ball = 1;
					}
					else
					{
						std::cout << "Bad pass that was nice tackle!";
						team1.getStats()->incrementTackles();
						Ball = 0;
					}
				}
			}
			break;
		}
	}

}

void CActions::Dribble(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	if (Ball = 0)
	{
		switch (positionOfBall)
		{

		case 1:// deffender
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber >8 && randNumber < 11)
			{
				playerHomeTeam = team1.getAttacker();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			break;
		case 2:// mid
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 8 && randNumber < 11)
			{
				playerHomeTeam = team1.getAttacker();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			break;
		case 3:
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 8 && randNumber < 11)
			{
				playerHomeTeam = team1.getAttacker();
				if (!simulateAlgorithm(playerHomeTeam->getPositionStats()->getDribbling(), playerHomeTeam->getPositionStats()->getBallControll(), playerHomeTeam->getPositionStats()->getStrength(),
					playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getSlideTackle(), playerAwayTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			break;
		}
	}
	else 
	{
		switch (positionOfBall)
		{
		case 1:// deffender
			playerHomeTeam = team1.getDeffenderPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			else if (randNumber > 8 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team2.getStats()->incrementTackles();
					Ball = 1;
				}
			}
			break;
		case 2:// mid
			playerHomeTeam = team2.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 8 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		case 3:
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 7)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 8 && randNumber < 11)
			{
				playerAwayTeam = team1.getAttacker();
				if (!simulateAlgorithm(playerAwayTeam->getPositionStats()->getDribbling(), playerAwayTeam->getPositionStats()->getBallControll(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getSlideTackle(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		}
	}
}

void CActions::Crossing(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	if (Ball == 0)
	{
		switch (positionOfBall)
		{
			case 1:
					playerAwayTeam = team2.getDeffenderPlayer();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else 
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				break;
			case 2:
				playerAwayTeam = team2.getMidPlayer();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				break;
			case 3:
				playerAwayTeam = team2.getAttacker();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getStrength(), playerHomeTeam->getPositionStats()->getCrossing(), playerHomeTeam->getPositionStats()->getVision(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getVision(), playerAwayTeam->getPositionStats()->getSlideTackle()))
					{
						std::cout << "Nice cross!";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						std::cout << "bad cross!";
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				break;
		}
	}
	else 
	{
		switch (positionOfBall)
		{
		case 1:
			playerHomeTeam = team1.getDeffenderPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		case 2:
			playerHomeTeam = team1.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		case 3:
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getStrength(), playerAwayTeam->getPositionStats()->getCrossing(), playerAwayTeam->getPositionStats()->getVision(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getVision(), playerHomeTeam->getPositionStats()->getSlideTackle()))
				{
					std::cout << "Nice cross!";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					std::cout << "bad cross!";
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		}
	}
}

void CActions::Heading(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = rand() % 10 + 0; // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	if (Ball == 0)
	{
		switch (positionOfBall)
		{
			case 1:
			playerAwayTeam = team2.getDeffenderPlayer();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				break;
			case 2:
				playerAwayTeam = team2.getMidPlayer();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				break;
			case 3:
				playerAwayTeam = team2.getAttacker();
				if (randNumber > 0 && randNumber < 5)
				{
					playerHomeTeam = team1.getDeffenderPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 4 && randNumber < 8)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice header by home deffnder and pass";
						team1.getStats()->incrementPasses();
						Ball = 0;
					}
					else 
					{
						team2.getStats()->incrementTackles();
						Ball = 1;
					}
				}
				else if (randNumber > 7 && randNumber < 11)
				{
					playerHomeTeam = team1.getAttacker();
					if (simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
					{
						playerAwayTeam = team2.getGKPlayer();
						team1.getStats()->incrementShotsOnTarget();
						if(simulateAlgorithm(playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getShortPass(), playerHomeTeam->getPositionStats()->getStrength(),
						playerAwayTeam->getPositionStats()->getStandTackle(), playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getStrength()))
						{
							team1.getStats()->incrementGoals();
							Ball = 1;
						}
					}
					else 
					{
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				break;
		}
	}
	else 
	{
		switch (positionOfBall)
		{
		case 1:
			playerHomeTeam = team1.getDeffenderPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		case 2:
			playerHomeTeam = team1.getMidPlayer();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			break;
		case 3:
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 0 && randNumber < 5)
			{
				playerAwayTeam = team1.getDeffenderPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					std::cout << "Nice header by home deffnder and pass";
					team2.getStats()->incrementPasses();
					Ball = 1;
				}
				else
				{
					team1.getStats()->incrementTackles();
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11)
			{
				playerAwayTeam = team2.getAttacker();
				if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
					playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
				{
					playerHomeTeam = team1.getGKPlayer();
					team2.getStats()->incrementShotsOnTarget();
					if (simulateAlgorithm(playerAwayTeam->getPositionStats()->getHeading(), playerAwayTeam->getPositionStats()->getShortPass(), playerAwayTeam->getPositionStats()->getStrength(),
						playerHomeTeam->getPositionStats()->getStandTackle(), playerHomeTeam->getPositionStats()->getHeading(), playerHomeTeam->getPositionStats()->getStrength()))
					{
						team2.getStats()->incrementGoals();
						Ball = 0;
					}
				}
				else
				{
					team2.getStats()->incrementShotOffTarget();
					Ball = 0;
				}
			}
			break;
		}
	}
}

//TODO
// оправи ball като се загуби топката
void CActions::YellowCard(CTeam& team1, CTeam& team2)
{
	randNumber = rand() % 10 + 0; // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:

		break;
	case 1:

		break;
	default:
		break;
	}
}
void CActions::RedCard(CTeam& team1, CTeam& team2)
{
	randNumber = rand() % 10 + 0; // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:

		break;
	case 1:

		break;
	default:
		break;
	}
}
void CActions::Penalty(CTeam& team1, CTeam& team2)
{
	randNumber = rand() % 10 + 0; // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:

		break;
	case 1:

		break;
	default:
		break;
	}
}
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
unsigned short CActions::Shoot(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	unsigned short longOrShortShoot = LongOrShort();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
		//Home team
	case 0:
		if (positionOfBall == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs midfielder
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " midfielder and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongShot() /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
							+ playerAwayTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerAwayTeam = team2.getGKPlayer();
						if (0.5 * (playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getLongPass() /
							playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getReflexes() +
							playerAwayTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team1.getStats()->incrementGoals();
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team1.getStats()->incrementShotsOnTarget();
							Ball = 1;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * ((playerHomeTeam->getPositionStats()->getFinishing() + playerHomeTeam->getPositionStats()->getShotPower() + playerHomeTeam->getPositionStats()->getBallControll()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning() + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerHomeTeam->getLastName() << std::endl;
						team1.getStats()->incrementGoals();
						team1.getStats()->incrementShotsOnTarget();
						Ball = 1;
					}
					else
					{
						std::cout << "What a miss!";
						team1.getStats()->incrementShotOffTarget();
						Ball = 1;
					}
				}
			}
		}
		break;
	case 1:
		if (positionOfBall == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs deffender
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker
			{
				playerAwayTeam = team2.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerHomeTeam = team1.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs midfielder
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << " midfielder and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker vs mid
			{
				playerAwayTeam = team2.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 1 && randNumber < 5) //DeffenderPlayer vs attacker
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs attacker
			{
				playerAwayTeam = team2.getMidPlayer();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by Midfielder: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by midfielder: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
			else if (randNumber > 7 && randNumber < 11) //attacker vs attacker
			{
				playerAwayTeam = team2.getAttacker();
				if (longOrShortShoot == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongShot() /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
							+ playerHomeTeam->getPositionStats()->getSprintSpeed())) > ChanceOfSuccess())
					{
						playerHomeTeam = team1.getGKPlayer();
						if (0.5 * (playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getLongPass() /
							playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getReflexes() +
							playerHomeTeam->getPositionStats()->getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							team2.getStats()->incrementGoals();
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
						else
						{
							std::cout << "Save by goalKeeper!";
							team2.getStats()->incrementShotsOnTarget();
							Ball = 0;
						}
					}
					else
					{
						std::cout << "Far away from goal!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
				else if (longOrShortShoot == 1) //Short Shot only GoalKeeper
				{
					playerHomeTeam = team1.getGKPlayer();
					if (0.5 * ((playerAwayTeam->getPositionStats()->getFinishing() + playerAwayTeam->getPositionStats()->getShotPower() + playerAwayTeam->getPositionStats()->getBallControll()) /
						(playerHomeTeam->getPositionStats()->getGKPossitioning() + playerHomeTeam->getPositionStats()->getGKHandling() + playerHomeTeam->getPositionStats()->getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by attacker: " << playerAwayTeam->getLastName() << std::endl;
						team2.getStats()->incrementGoals();
						team2.getStats()->incrementShotsOnTarget();
						Ball = 0;
					}
					else
					{
						std::cout << "What a miss!";
						team2.getStats()->incrementShotOffTarget();
						Ball = 0;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
unsigned short CActions::Pass(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0: //team 1 passing
		if (positionOfBall == 1) // def team deffenders
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNumber > 1 && randNumber < 5) //deffneder vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs deff
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //deffender vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						team1.getStats()->incrementPasses();
					}
					else
					{
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						team1.getStats()->incrementPasses();
					}
					else
					{
						team2.getStats()->incrementTackles();
					}
				}
			}
		}
		else if (positionOfBall == 2) // def team middfilders
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) //deffender vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 1 && randNumber < 5) //deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getLongPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getVision() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						Ball = 0;
						team1.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team2.getStats()->incrementTackles();
					}
				}
			}
		}
		break;
	case 1: //team 2 passsing
		if (positionOfBall == 1) // def team deffenders
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNumber > 1 && randNumber < 5) //deffneder vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs deff
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //deffender vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
		}
		else if (positionOfBall == 2) // def team middfilders
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) //deffender vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						Ball = 0;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 1;
						team1.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 1 && randNumber < 5) //deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
						Ball = 1;
						team2.getStats()->incrementPasses();
					}
					else
					{
						Ball = 0;
						team1.getStats()->incrementTackles();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
						team2.getStats()->incrementPasses();
					}
				}
			}
			else if (randNumber > 7 && randNumber > 11) //attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getLongPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team1.getStats()->incrementTackles();
					}
					else
					{
						Ball = 0;
						team2.getStats()->incrementPasses();
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getVision() + playerAwayTeam->getPositionStats()->getStrength()) /
						(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
						Ball = 1;
						team1.getStats()->incrementTackles();
					}
					else
					{
						Ball = 0;
						team2.getStats()->incrementPasses();
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
unsigned short CActions::Dribble(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:
		//dribble
		if (positionOfBall == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() +
						playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			//Mid vs deffenders
			else if (randNumber > 4 && randNumber < 8)
			{
				//CM
				playerHomeTeam = team1.getMidPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			else if (randNumber > 7 && randNumber < 10)
			{
				//Att vs deffender
				playerHomeTeam = team1.getAttacker();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by middfilder!: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			else if (randNumber == 0)
			{

				//GK
			}
		}
		else if (positionOfBall == 2)
			// mid side away team
		{
			playerAwayTeam = team2.getMidPlayer();
			//deffender vs mid
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
			}
			//mid vs mid
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by Midfilder: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			//attackers vs mid
			else if (randNumber > 7 && randNumber < 10)
			{
				playerHomeTeam = team1.getAttacker();
				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNumber == 0)
			{
				//GK
			}
		}
		else if (positionOfBall == 3)
			//attack side away team
		{
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();

				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerHomeTeam = team1.getMidPlayer();

				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			else if (randNumber > 7 && randNumber < 10)
			{
				playerHomeTeam = team1.getAttacker();

				if ((0.5 * (playerHomeTeam->getPositionStats()->getDribbling() + playerHomeTeam->getPositionStats()->getBallControll() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getSlideTackle() + playerAwayTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 0;
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNumber == 0)
			{
				//GK
			}
		}
		break;
	case 1:
		//dribble
		if (positionOfBall == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNumber > 1 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			//Mid vs deffenders
			else if (randNumber > 4 && randNumber < 8)
			{
				//CM
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			else if (randNumber > 7 && randNumber < 10)
			{
				//Att vs deffender
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by middfilder!: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
					std::cout << "Great tackle by deffender";
					team1.getStats()->incrementTackles();
				}
			}
			else if (randNumber == 0)
			{

				//GK
			}
		}
		else if (positionOfBall == 2)
			// mid side away team
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			//deffender vs mid
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
			}
			//mid vs mid
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by Midfilder: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
				//CM
			}
			//attackers vs mid
			else if (randNumber > 7 && randNumber < 10)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
				//Att
			}
			else if (randNumber == 0)
			{
				//GK
			}
		}
		else if (positionOfBall == 3)
			//attack side away team
		{
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 1 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();

				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8)
			{
				playerAwayTeam = team2.getMidPlayer();

				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
				//CM
			}
			else if (randNumber > 7 && randNumber < 10)
			{
				playerAwayTeam = team2.getAttacker();

				if ((0.5 * (playerAwayTeam->getPositionStats()->getDribbling() + playerAwayTeam->getPositionStats()->getBallControll() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getSlideTackle() + playerHomeTeam->getPositionStats()->getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
					Ball = 1;
				}
				else
				{
					Ball = 0;
				}
				//Att
			}
			else if (randNumber == 0)
			{
				//GK
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
unsigned short CActions::Crossing(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;

	switch (Ball)
	{
	case 0:
		if (positionOfBall == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNumber > 1 && randNumber < 5) // deffender vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home deffender! over away deffender";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work for away deffender";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs deffender
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder! over away deffender";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home midfilder great work for away deffender";
					Ball = 1;
				}
			}
			else if (randNumber > 9 && randNumber < 11) // attacker vs deffender
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker! over away deffender";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home attacker great work for away deffender";
					Ball = 1;
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) // deffnder vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home Deffender over away midfielder!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away midfielder!";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder over away midfielder!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home midfielder great work by away midfielder!";
					Ball = 1;
				}
			}
			else if (randNumber > 9 && randNumber < 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker over away midfielder!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home attacker great work by away midfielder!";
					Ball = 1;
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNumber > 1 && randNumber < 5) // deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home Deffender over away midfielder!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away midfielder!";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) //mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder over away attacker!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home midfielder great work by away attacker!";
					Ball = 1;
				}
			}
			else if (randNumber > 9 && randNumber < 11) // attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getStrength() + playerHomeTeam->getPositionStats()->getCrossing() + playerHomeTeam->getPositionStats()->getVision() /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getVision()
						+ playerAwayTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker over away attacker!";
					Ball = 0;
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away attacker";
					Ball = 1;
				}
			}
		}
		break;
	case 1:
		if (positionOfBall == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNumber > 1 && randNumber < 5) // deffender vs deffender
			{
				playerAwayTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away deffender! over home deffender";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work for home deffender";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs deffender
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder! over home deffender";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away midfilder great work for home deffender";
					Ball = 0;
				}
			}
			else if (randNumber > 9 && randNumber < 11) // attacker vs deffender
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker! over home deffender";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away attacker great work for home deffender";
					Ball = 0;
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerHomeTeam = team1.getMidPlayer();
			if (randNumber > 1 && randNumber < 5) // deffnder vs mid
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away Deffender over home midfielder!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home midfielder!";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // mid vs mid
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder over home midfielder!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away midfielder great work by home midfielder!";
					Ball = 0;
				}
			}
			else if (randNumber > 9 && randNumber < 11) //attacker vs mid
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker over home midfielder!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away attacker great work by home midfielder!";
					Ball = 0;
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerHomeTeam = team1.getAttacker();
			if (randNumber > 1 && randNumber < 5) // deffender vs attacker
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away Deffender over home midfielder!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home midfielder!";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) //mid vs attacker
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder over home attacker!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away midfielder great work by home attacker!";
					Ball = 0;
				}
			}
			else if (randNumber > 9 && randNumber < 11) // attacker vs attacker
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats()->getStrength() + playerAwayTeam->getPositionStats()->getCrossing() + playerAwayTeam->getPositionStats()->getVision() /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getVision()
						+ playerHomeTeam->getPositionStats()->getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker over home attacker!";
					Ball = 1;
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home attacker";
					Ball = 0;
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
unsigned short CActions::Heading(CTeam& team1, CTeam& team2)
{
	unsigned short positionOfBall = PositionOfBall();
	randNumber = rand() % 10 + 0; // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:
		if (positionOfBall == 1) //deffender side
		{
			playerAwayTeam = team2.getDeffenderPlayer(); //deffender vs deffender
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs deffender
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs deffender
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 1;
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerAwayTeam = team2.getMidPlayer(); //deffender vs midfielder
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs midfielder
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs midfielder
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 1;
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getDeffenderPlayer(); //deffender vs deffender
			if (randNumber > 1 && randNumber < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs deffender
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 0;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 1;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs deffender
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker have to beat and goalkeeper!!!";
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning()) + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes() > ChanceOfSuccess())
					{
						std::cout << "What a incredible header by home attacker and this is goal!!!!";
						Ball = 1;
					}
					else {
						std::cout << "What a save!!!";
						Ball = 1;
					}
				}
				else
				{
					std::cout << "Poor heading by attacker and this is chance for away team!";
					Ball = 1;
				}
			}
		}
		break;
	case 1:
		if (positionOfBall == 1) //deffender side
		{
			playerHomeTeam = team1.getDeffenderPlayer(); //deffender vs deffender
			if (randNumber > 1 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs deffender
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs deffender
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
		}
		else if (positionOfBall == 2)
		{
			playerHomeTeam = team1.getMidPlayer(); //deffender vs midfielder
			if (randNumber > 1 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs midfielder
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs midfielder
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getShortPass() + playerAwayTeam->getPositionStats()->getStrength()) /
					(playerHomeTeam->getPositionStats()->getStandTackle() + playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
		}
		else if (positionOfBall == 3)
		{
			playerAwayTeam = team2.getAttacker(); //Attacker vs deffender
			if (randNumber > 1 && randNumber < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home deffnder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 4 && randNumber < 8) // midfielder vs deffender
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home midfielder and pass";
					Ball = 1;
				}
				else
				{
					std::cout << "Poor heading by midfielder and this is chance for away team!";
					Ball = 0;
				}
			}
			else if (randNumber > 7 && randNumber < 11) // attacker vs deffender
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
					(playerAwayTeam->getPositionStats()->getStandTackle() + playerAwayTeam->getPositionStats()->getHeading() + playerAwayTeam->getPositionStats()->getStrength()) > ChanceOfSuccess())
				{
					std::cout << "Nice header by home Attacker have to beat and goalkeeper!!!";
					playerAwayTeam = team2.getGKPlayer();
					if (0.5 * (playerHomeTeam->getPositionStats()->getHeading() + playerHomeTeam->getPositionStats()->getShortPass() + playerHomeTeam->getPositionStats()->getStrength()) /
						(playerAwayTeam->getPositionStats()->getGKPossitioning()) + playerAwayTeam->getPositionStats()->getGKHandling() + playerAwayTeam->getPositionStats()->getReflexes() > ChanceOfSuccess())
					{
						std::cout << "What a incredible header by home attacker and this is goal!!!!";
						Ball = 0;
					}
					else {
						std::cout << "What a save!!!";
						Ball = 0;
					}
				}
				else
				{
					std::cout << "Poor heading by deffender and this is chance for away team!";
					Ball = 0;
				}
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
//TODO
// оправи ball като се загуби топката
unsigned short CActions::YellowCard(CTeam& team1, CTeam& team2)
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
	return 0;
}
unsigned short CActions::RedCard(CTeam& team1, CTeam& team2)
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
	return 0;
}
unsigned short CActions::Penalty(CTeam& team1, CTeam& team2)
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
	return 0;
}
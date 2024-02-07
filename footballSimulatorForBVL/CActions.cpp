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
	randNum = rand() % 1 + 0;
	if (randNum > 0)
	{
		Ball = randNum;
	}
}
unsigned short CActions::Shoot(CTeam& team1, CTeam& team2)
{
	randNum = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
		//Home team
	case 0:
		if (PositionOfBall() == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNum > 1 && randNum < 5) //DeffenderPlayer
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
							+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
					{
						if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
							playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
							playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							Ball = 1;
						}
					}
					else
					{
						FirstWhistle();
					}
				}
				else if (LongOrShort() == 1) //Short Shot only GoalKeeper
				{
					if (0.5 * ((playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getBallControll()) /
						(playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getGKHandling() + playerAwayTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << std::endl;
					}
					else
					{
						Ball = 1;
					}
				}
				//action
			}
			else if (randNum > 4 && randNum < 8) //MidPlayer
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (randNum > 1 && randNum < 5) //DeffenderPlayer
				{
					playerHomeTeam = team1.getMidPlayer();
					if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
					{
						if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
							(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
								+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
						{
							if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
								playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
								playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
							{
								std::cout << "Goal!!!!! Incredible shoot by centrall mid: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
								Ball = 1;
							}
						}
						else
						{
							FirstWhistle();
						}
					}
					else if (LongOrShort() == 1) //Short Shot only GoalKeeper
					{
						if (0.5 * ((playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getBallControll()) /
							(playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getGKHandling() + playerAwayTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
						{
							std::cout << "Goal!!!!! Incredible shoot by central mid: " << playerHomeTeam->getLastName() << std::endl;
						}
						else
						{
							Ball = 1;
						}
					}
				}
				else if (randNum > 7 && randNum < 10) //AttackerPlayer
				{
					playerAwayTeam = team2.getDeffenderPlayer();
					if (randNum > 1 && randNum < 5) //DeffenderPlayer
					{
						playerHomeTeam = team1.getAttacker();
						if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
						{
							if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
								(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
									+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
									playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
									playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						else if (LongOrShort() == 1) //Short Shot only GoalKeeper
						{
							if (0.5 * ((playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getBallControll()) /
								(playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getGKHandling() + playerAwayTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
							{
								std::cout << "Goal!!!!! Incredible shoot by central mid: " << playerHomeTeam->getLastName() << std::endl;
							}
							else
							{
								Ball = 1;
							}
						}
					}
				}
				else if (PositionOfBall() == 2)
				{
					playerAwayTeam = team2.getMidPlayer();
					if (randNum > 1 && randNum < 5) //DeffenderPlayer
					{
						playerHomeTeam = team1.getDeffenderPlayer();
						if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
						{
							if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
								(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
									+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
									playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
									playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						//action
					}
					else if (randNum > 4 && randNum < 8) //MidPlayer
					{
						playerAwayTeam = team2.getMidPlayer();
						if (randNum > 1 && randNum < 5) //DeffenderPlayer
						{
							playerHomeTeam = team1.getMidPlayer();
							if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
								(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
									+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
									playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
									playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by centrall mid: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						else if (randNum > 7 && randNum < 10) //AttackerPlayer
						{
							playerAwayTeam = team2.getDeffenderPlayer();
							if (randNum > 1 && randNum < 5) //DeffenderPlayer
							{
								playerHomeTeam = team1.getAttacker();
								if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongShot() /
									(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
										+ playerAwayTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
								{
									if (0.5 * (playerHomeTeam->getPositionStats().getFinishing() + playerHomeTeam->getPositionStats().getShotPower() + playerHomeTeam->getPositionStats().getLongPass() /
										playerAwayTeam->getPositionStats().getGKPossitioning() + playerAwayTeam->getPositionStats().getReflexes() +
										playerAwayTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
									{
										std::cout << "Goal!!!!! Incredible shoot by " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
										Ball = 1;
									}
								}
								else
								{
									FirstWhistle();
								}
							}
						}
					}
				}
			}
			break;
	case 1:
		if (PositionOfBall() == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			if (randNum > 1 && randNum < 5) //DeffenderPlayer
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
							+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
					{
						if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
							playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
							playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
						{
							std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
							Ball = 1;
						}
					}
					else
					{
						FirstWhistle();
					}
				}
				else if (LongOrShort() == 1) //Short Shot only GoalKeeper
				{
					if (0.5 * ((playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getBallControll()) /
						(playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getGKHandling()
							+ playerHomeTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
					{
						std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << std::endl;
					}
					else
					{
						Ball = 1;
					}
				}
				//action
			}
			else if (randNum > 4 && randNum < 8) //MidPlayer
			{
					playerHomeTeam = team1.getDeffenderPlayer();
				if (randNum > 1 && randNum < 5) //DeffenderPlayer
				{
					playerAwayTeam = team2.getMidPlayer();
					if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
					{
						if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
							(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
								+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
						{
							if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
								playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
								playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
							{
								std::cout << "Goal!!!!! Incredible shoot by centrall mid: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
								Ball = 1;
							}
						}
						else
						{
							FirstWhistle();
						}
					}
					else if (LongOrShort() == 1) //Short Shot only GoalKeeper
					{
						if (0.5 * ((playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getBallControll()) /
							(playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getGKHandling() + playerHomeTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
						{
							std::cout << "Goal!!!!! Incredible shoot by central mid: " << playerHomeTeam->getLastName() << std::endl;
						}
						else
						{
							Ball = 1;
						}
					}
				}
				else if (randNum > 7 && randNum < 10) //AttackerPlayer
				{
						playerHomeTeam = team1.getDeffenderPlayer();
					if (randNum > 1 && randNum < 5) //DeffenderPlayer
					{
					playerAwayTeam = team1.getAttacker();
						if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
						{
							if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
								(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
									+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
									playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
									playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						else if (LongOrShort() == 1) //Short Shot only GoalKeeper
						{
							if (0.5 * ((playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getBallControll()) /
								(playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getGKHandling() + playerHomeTeam->getPositionStats().getReflexes()) > ChanceOfSuccess()))
							{
								std::cout << "Goal!!!!! Incredible shoot by central mid: " << playerHomeTeam->getLastName() << std::endl;
							}
							else
							{
								Ball = 1;
							}
						}
					}
				}
				else if (PositionOfBall() == 2)
				{
					playerHomeTeam = team1.getMidPlayer();
					if (randNum > 1 && randNum < 5) //DeffenderPlayer
					{
						playerAwayTeam = team2.getDeffenderPlayer();
						if (LongOrShort() == 0) // Long Shot deffender + goalkeeper
						{
							if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
								(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
									+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
									playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
									playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by deffender: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						//action
					}
					else if (randNum > 4 && randNum < 8) //MidPlayer
					{
						playerHomeTeam = team1.getMidPlayer();
						if (randNum > 1 && randNum < 5) //DeffenderPlayer
						{
							playerAwayTeam = team2.getMidPlayer();
							if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
								(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
									+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
							{
								if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
									playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
									playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
								{
									std::cout << "Goal!!!!! Incredible shoot by centrall mid: " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
									Ball = 1;
								}
							}
							else
							{
								FirstWhistle();
							}
						}
						else if (randNum > 7 && randNum < 10) //AttackerPlayer
						{
							playerHomeTeam = team1.getDeffenderPlayer();
							if (randNum > 1 && randNum < 5) //DeffenderPlayer
							{
								playerAwayTeam = team2.getAttacker();
								if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongShot() /
									(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
										+ playerHomeTeam->getPositionStats().getSprintSpeed())) > ChanceOfSuccess())
								{
									if (0.5 * (playerAwayTeam->getPositionStats().getFinishing() + playerAwayTeam->getPositionStats().getShotPower() + playerAwayTeam->getPositionStats().getLongPass() /
										playerHomeTeam->getPositionStats().getGKPossitioning() + playerHomeTeam->getPositionStats().getReflexes() +
										playerHomeTeam->getPositionStats().getGKHandling()) > ChanceOfSuccess())
									{
										std::cout << "Goal!!!!! Incredible shoot by " << playerHomeTeam->getLastName() << " deffender and goalkeeper are watching stressed!" << std::endl;
										Ball = 1;
									}
								}
								else
								{
									FirstWhistle();
								}
							}
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
	}
}
unsigned short CActions::Pass(CTeam& team1, CTeam& team2)
{
	randNum = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0: //team 1 passing
		if (PositionOfBall() == 1) // def team deffenders
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNum > 1 && randNum < 5) //deffneder vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if(0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs deff
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //deffender vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
					}
				}
			}
		}
		else if(PositionOfBall() == 2) // def team middfilders
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNum > 1 && randNum < 5) //deffender vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
					}
				}
			}
		}
		else if (PositionOfBall() == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNum > 1 && randNum < 5) //deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getLongPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerHomeTeam->getPositionStats().getShortPass() + playerHomeTeam->getPositionStats().getVision() + playerHomeTeam->getPositionStats().getStrength()) /
						(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
					}
				}
			}
		}
		break;
	case 1: //team 2 passsing
		if (PositionOfBall() == 1) // def team deffenders
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			if (randNum > 1 && randNum < 5) //deffneder vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs deff
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //deffender vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
					}
				}
			}
		}
		else if (PositionOfBall() == 2) // def team middfilders
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNum > 1 && randNum < 5) //deffender vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
					}
				}
			}
		}
		else if (PositionOfBall() == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNum > 1 && randNum < 5) //deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by deffenderhe just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Middfilder he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Middfilder he just made deffenders look stupid!";
					}
				}
			}
			else if (randNum > 7 && randNum > 11) //attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (LongOrShort() == 0) //long pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getLongPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice long pass by Attacker he just made deffenders look stupid!";
					}
				}
				else if (LongOrShort() == 1) //short pass
				{
					if (0.5 * (playerAwayTeam->getPositionStats().getShortPass() + playerAwayTeam->getPositionStats().getVision() + playerAwayTeam->getPositionStats().getStrength()) /
						(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength()))
					{
						std::cout << "Nice short pass by Attacker he just made deffenders look stupid!";
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
	randNum = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;
	switch (Ball)
	{
	case 0:
		//dribble
		if (PositionOfBall() == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNum > 1 && randNum < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() +
						playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			//Mid vs deffenders
			else if (randNum > 4 && randNum < 8)
			{
				//CM
				playerHomeTeam = team1.getMidPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			else if (randNum > 7 && randNum < 10)
			{
				//Att vs deffender
				playerHomeTeam = team1.getAttacker();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by middfilder!: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			else if (randNum == 0)
			{

				//GK
			}
		}
		else if (PositionOfBall() == 2)
			// mid side away team
		{
			playerAwayTeam = team2.getMidPlayer();
			//deffender vs mid
			if (randNum > 1 && randNum < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
			}
			//mid vs mid
			else if (randNum > 4 && randNum < 8)
			{
				playerHomeTeam = team1.getMidPlayer();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by Midfilder: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			//attackers vs mid
			else if (randNum > 7 && randNum < 10)
			{
				playerHomeTeam = team1.getAttacker();
				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNum == 0)
			{
				//GK
			}
		}
		else if (PositionOfBall() == 3)
			//attack side away team
		{
			playerAwayTeam = team2.getAttacker();
			if (randNum > 1 && randNum < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();

				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
			}
			else if (randNum > 4 && randNum < 8)
			{
				playerHomeTeam = team1.getMidPlayer();

				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			else if (randNum > 7 && randNum < 10)
			{
				playerHomeTeam = team1.getAttacker();

				if ((0.5 * (playerHomeTeam->getPositionStats().getDribbling() + playerHomeTeam->getPositionStats().getBallControll() + playerHomeTeam->getPositionStats().getStrength()) /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getSlideTackle() + playerAwayTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNum == 0)
			{
				//GK
			}
		}
		break;
	case 1:
		//dribble
		if (PositionOfBall() == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNum > 1 && randNum < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			//Mid vs deffenders
			else if (randNum > 4 && randNum < 8)
			{
				//CM
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			else if (randNum > 7 && randNum < 10)
			{
				//Att vs deffender
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by middfilder!: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
					std::cout << "Great tackle by deffender";
					team1.getStats().incrementTackles();
				}
			}
			else if (randNum == 0)
			{

				//GK
			}
		}
		else if (PositionOfBall() == 2)
			// mid side away team
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			//deffender vs mid
			if (randNum > 1 && randNum < 5)
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
			}
			//mid vs mid
			else if (randNum > 4 && randNum < 8)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by Midfilder: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			//attackers vs mid
			else if (randNum > 7 && randNum < 10)
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNum == 0)
			{
				//GK
			}
		}
		else if (PositionOfBall() == 3)
			//attack side away team
		{
			playerHomeTeam = team1.getAttacker();
			if (randNum > 1 && randNum < 5)
			{
				playerAwayTeam = team2.getDeffenderPlayer();

				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
			}
			else if (randNum > 4 && randNum < 8)
			{
				playerAwayTeam = team2.getMidPlayer();

				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//CM
			}
			else if (randNum > 7 && randNum < 10)
			{
				playerAwayTeam = team2.getAttacker();

				if ((0.5 * (playerAwayTeam->getPositionStats().getDribbling() + playerAwayTeam->getPositionStats().getBallControll() + playerAwayTeam->getPositionStats().getStrength()) /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getSlideTackle() + playerHomeTeam->getPositionStats().getStrength())) > ChanceOfSuccess())
				{
					std::cout << "Wonderful dribble by deffender: " << playerHomeTeam->getLastName();
				}
				else
				{
					Ball = 1;
				}
				//Att
			}
			else if (randNum == 0)
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
	randNum = randNumGenerator(10); // choosing a player
	CPlayer* playerHomeTeam = nullptr;
	CPlayer* playerAwayTeam = nullptr;

	switch (Ball)
	{
	case 0:
		if (PositionOfBall() == 1)
		{
			playerAwayTeam = team2.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNum > 1 && randNum < 5) // deffender vs deffender
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home deffender! over away deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work for away deffender";
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs deffender
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder! over away deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by home midfilder great work for away deffender";
				}
			}
			else if (randNum > 9 && randNum < 11) // attacker vs deffender
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker! over away deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by home attacker great work for away deffender";
				}
			}
		}
		else if (PositionOfBall() == 2)
		{
			playerAwayTeam = team2.getMidPlayer();
			if (randNum > 1 && randNum < 5) // deffnder vs mid
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home Deffender over away midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away midfielder!";
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs mid
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder over away midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by home midfielder great work by away midfielder!";
				}
			}
			else if (randNum > 9 && randNum < 11) //attacker vs mid
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker over away midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by home attacker great work by away midfielder!";
				}
			}
		}
		else if (PositionOfBall() == 3)
		{
			playerAwayTeam = team2.getAttacker();
			if (randNum > 1 && randNum < 5) // deffender vs attacker
			{
				playerHomeTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home Deffender over away midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away midfielder!";
				}
			}
			else if (randNum > 4 && randNum < 8) //mid vs attacker
			{
				playerHomeTeam = team1.getMidPlayer();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home midfielder over away attacker!";
				}
				else
				{
					std::cout << "It wasnt best cross by home midfielder great work by away attacker!";
				}
			}
			else if (randNum > 9 && randNum < 11) // attacker vs attacker
			{
				playerHomeTeam = team1.getAttacker();
				if (0.5 * (playerHomeTeam->getPositionStats().getStrength() + playerHomeTeam->getPositionStats().getCrossing() + playerHomeTeam->getPositionStats().getVision() /
					(playerAwayTeam->getPositionStats().getStandTackle() + playerAwayTeam->getPositionStats().getVision()
						+ playerAwayTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by home attacker over away attacker!";
				}
				else
				{
					std::cout << "It wasnt best cross by home deffender great work by away attacker";
				}
			}
		}
		break;
	case 1:
		if (PositionOfBall() == 1)
		{
			playerHomeTeam = team1.getDeffenderPlayer();
			// deffender vs deffenders
			if (randNum > 1 && randNum < 5) // deffender vs deffender
			{
				playerAwayTeam = team1.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away deffender! over home deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work for home deffender";
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs deffender
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder! over home deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by away midfilder great work for home deffender";
				}
			}
			else if (randNum > 9 && randNum < 11) // attacker vs deffender
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker! over home deffender";
				}
				else
				{
					std::cout << "It wasnt best cross by away attacker great work for home deffender";
				}
			}
		}
		else if (PositionOfBall() == 2)
		{
			playerHomeTeam = team1.getMidPlayer();
			if (randNum > 1 && randNum < 5) // deffnder vs mid
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away Deffender over home midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home midfielder!";
				}
			}
			else if (randNum > 4 && randNum < 8) // mid vs mid
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder over home midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by away midfielder great work by home midfielder!";
				}
			}
			else if (randNum > 9 && randNum < 11) //attacker vs mid
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker over home midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by away attacker great work by home midfielder!";
				}
			}
		}
		else if (PositionOfBall() == 3)
		{
			playerHomeTeam = team1.getAttacker();
			if (randNum > 1 && randNum < 5) // deffender vs attacker
			{
				playerAwayTeam = team2.getDeffenderPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away Deffender over home midfielder!";
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home midfielder!";
				}
			}
			else if (randNum > 4 && randNum < 8) //mid vs attacker
			{
				playerAwayTeam = team2.getMidPlayer();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away midfielder over home attacker!";
				}
				else
				{
					std::cout << "It wasnt best cross by away midfielder great work by home attacker!";
				}
			}
			else if (randNum > 9 && randNum < 11) // attacker vs attacker
			{
				playerAwayTeam = team2.getAttacker();
				if (0.5 * (playerAwayTeam->getPositionStats().getStrength() + playerAwayTeam->getPositionStats().getCrossing() + playerAwayTeam->getPositionStats().getVision() /
					(playerHomeTeam->getPositionStats().getStandTackle() + playerHomeTeam->getPositionStats().getVision()
						+ playerHomeTeam->getPositionStats().getSlideTackle())) > ChanceOfSuccess())
				{
					std::cout << "Nice cross by away attacker over home attacker!";
				}
				else
				{
					std::cout << "It wasnt best cross by away deffender great work by home attacker";
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
unsigned short CActions::Heading(CTeam& team1, CTeam& team2)
{
	randNum = rand() % 10 + 0; // choosing a player
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
unsigned short CActions::YellowCard(CTeam& team1, CTeam& team2)
{
	randNum = rand() % 10 + 0; // choosing a player
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
	randNum = rand() % 10 + 0; // choosing a player
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
	randNum = rand() % 10 + 0; // choosing a player
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
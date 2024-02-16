#include "CStartMatch.h"

CStartMatch::CStartMatch()
{
}

CStartMatch::CStartMatch(CTeam*& team1, CTeam*& team2) 
{
	FirstWhistle(team1, team2);
}

void CStartMatch::FirstWhistle(CTeam*& team1, CTeam*& team2)
{
	ballForTeam();
	while (minute < 90)
	{
		system("CLS");
		//shoot pass dribble crossing, heading, yellowcard,redcard,penalty
		switch (randNumGenerator(8))
		{
			case 0:
				randNumGenerator(100) <= 30 ? Shoot(*team1, *team2) : Pass(*team1, *team2);
				break;
			case 1:
				Pass(*team1, *team2);
				break;
			case 2:
				randNumGenerator(100) <= 50 ? Dribble(*team1, *team2) : Pass(*team1, *team2);
				break;
			case 3:
				randNumGenerator(100) <= 40 ? Crossing(*team1, *team2) : Pass(*team1, *team2);
				break;
			case 4:
				randNumGenerator(100) <= 40 ? Heading(*team1, *team2) : Pass(*team1, *team2);
				break;
			case 5:
				YellowCard(*team1, *team2);
				break;
			case 6:
				RedCard(*team1, *team2);
				break;
			case 7 :
				Penalty(*team1, *team2);
				break;
		}
		seconds += 30;
		if (seconds == 60)
		{
			seconds = 0;
			minute++;
		}
	}
	system("CLS");
	std::cout << team1->getTeamName() << "              -         " << team2->getTeamName() << std::endl;
	std::cout << team1->getStats()->Goals << " Goal " << team2->getStats()->Goals << std::endl;
	std::cout << team1->getStats()->ShotsOnTarget << " Shots on Target " << team2->getStats()->ShotsOnTarget << std::endl;
	std::cout << team1->getStats()->ShotOffTarget << " Shots off Target " << team2->getStats()->ShotOffTarget << std::endl;
	std::cout << team1->getStats()->Tackles << " Tackles " << team2->getStats()->Tackles << std::endl;
	std::cout << team1->getStats()->Passes << " Completed passes " << team2->getStats()->Passes << std::endl;
	std::cout << team1->getStats()->RedCard << " Red cards " << team2->getStats()->RedCard << std::endl;
	std::cout << team1->getStats()->YellowCard << " yellow cards " << team2->getStats()->YellowCard << std::endl;
}
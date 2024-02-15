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
	while (true)
	{
		system("CLS");
		//shoot pass dribble crossing, heading, yellowcard,redcard,penalty
		switch (randNumGenerator(4))
		{
			case 0:
				Shoot(*team1, *team2);
				break;
			case 1:
				Pass(*team1, *team2);
				break;
			case 2:
				Dribble(*team1, *team2);
				break;
			case 3:
				Crossing(*team1, *team2);
				break;
			case 4:
				Heading(*team1, *team2);
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
		if (minute == 90) 
		{
			break;
		}
		minute++;
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
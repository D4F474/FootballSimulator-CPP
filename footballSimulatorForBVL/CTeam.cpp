#include "CTeam.h"
CTeam::CTeam(std::string nameOfTeam, unsigned short points, unsigned short goals, unsigned short wins, unsigned short loses, unsigned short draws)
{
	NameOfTeam = nameOfTeam;
	Points = points;
	Goals = goals;
	Wins = wins;
	Loses = loses;
	Draws = draws;
	srand(time(NULL));
}

void CTeam::addPlayer(CPlayer& player)
{
	TeamRating += player.getOVR();
	Players.push_back(&player);
}

std::ostream& operator << (std::ostream& toStream, const CTeam* team)
{
	toStream << "Team name: " << team->NameOfTeam << std::endl
		<< "Team Rating: " << team->TeamRating / team->TeamSize << std::endl
		<< "Goals: " << team->Goals << std::endl
		<< "Wins: " << team->Wins << std::endl
		<< "Draws: " << team->Draws << std::endl
		<< "Loses: " << team->Loses << std::endl
		<< "Points: " << team->Points << std::endl;
	return toStream;

}

void CTeam::printPlayers() const
{
	for (int i = 0; i < Players.size(); i++)
	{
		std::cout << *Players[i] << std::endl;
	}
}
CPlayer* CTeam::getGKPlayer() const
{
	return Players[0];
}

CPlayer* CTeam::getDeffenderPlayer()
{
	randomNum = 0;
	randomNum = rand() % 1 + 4;
	if (Players[randomNum]->getPossition() == "RB" || Players[randomNum]->getPossition() == "CB" || Players[randomNum]->getPossition() == "LB")
	{
		return Players[randomNum];
	}
	
}

CPlayer* CTeam::getMidPlayer()
{
	randomNum = 0;
	randomNum = rand() % 3 + 5;
	if (Players[randomNum]->getPossition() == "CM")
	{
		return Players[randomNum];
	}
}

CPlayer* CTeam::getAttacker()
{
	randomNum = 0;
	randomNum = rand() % 3 + 8;
	if (Players[randomNum]->getPossition() == "LW" || Players[randomNum]->getPossition() == "ST" || Players[randomNum]->getPossition() == "RW" )
	{
		return Players[randomNum];
	}

}

CMatchStats* CTeam::getStats()
{
	return statForMatch;
}
#include "CMatchStats.h"

CMatchStats::CMatchStats() 
{
	Goals = 0;
	Minutes = 0;
	Tackles = 0;
	ShotsOnTarget = 0;
	ShotOffTarget = 0;
	Offside = 0;
	Passes = 0;
	YellowCard = 0;
	RedCard = 0;
}

void CMatchStats::incrementTackles()
{
	Tackles++;
}

void CMatchStats::incrementGoals()
{
	Goals++;
}

void CMatchStats::incrementPossesion()
{
	//from 100 -32 etc;
}
void CMatchStats::incrementShotsOnTarget()
{
	ShotsOnTarget++;
}
void CMatchStats::incrementShotOffTarget()
{
	ShotOffTarget++;
}
void CMatchStats::incrementOffSide()
{
	Offside++;
}
void CMatchStats::incrementPasses()
{
	Passes++;
}
void CMatchStats::incrementYellowCards()
{
	YellowCard++;
}
void CMatchStats::incrementRedCards()
{
	RedCard++;
}

void CMatchStats::incrementMinutes()
{
	Minutes++;
}
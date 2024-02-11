#include "CMatchStats.h"

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
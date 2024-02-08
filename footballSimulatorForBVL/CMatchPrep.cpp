#include "CMatchPrep.h"

void CMatchPrep::ballForTeam() 
{
	srand(time(NULL));
	Ball = rand() % 1 + 0;
}
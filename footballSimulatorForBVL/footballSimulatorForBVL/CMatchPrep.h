#ifndef C_MATCH_PREP
#define C_MATCH_PREP

#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CMatchPrep
{
public:
	unsigned short Ball; //0 or 1 if the number is 0 home team is playing if it is 1 away team have the ball
	unsigned short PlayerPlayedWithBall;
	void ballForTeam();
};
#endif
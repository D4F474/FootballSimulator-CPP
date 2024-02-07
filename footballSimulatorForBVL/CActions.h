#ifndef C_ACTIONS
#define C_ACTIONS
#include "CMatchPrep.h"
#include "CTeam.h"
#include <stdlib.h>
#include <time.h>

	static unsigned short ChanceOfSuccess();
	static unsigned short LongOrShort();

class CActions : public CMatchPrep
{
protected:
	unsigned short randNum;
public:
	CActions();
	static unsigned short randNumGenerator(unsigned short number);
	virtual void FirstWhistle();
	unsigned short Shoot(CTeam& team1, CTeam& team2);
	unsigned short Pass(CTeam& team1, CTeam& team2);
	unsigned short Dribble(CTeam& team1, CTeam& team2);
	unsigned short Crossing(CTeam& team1, CTeam& team2);
	unsigned short Penalty(CTeam& team1, CTeam& team2);
	unsigned short Heading(CTeam& team1, CTeam& team2);
	unsigned short YellowCard(CTeam& team1, CTeam& team2);
	unsigned short RedCard(CTeam& team1, CTeam& team2);
	unsigned short PositionOfBall(); // is on deff side mid side att side
};
#endif
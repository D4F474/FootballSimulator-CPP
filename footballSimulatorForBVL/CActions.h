#ifndef C_ACTIONS
#define C_ACTIONS
#include "CMatchPrep.h"
#include "CTeam.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

	static unsigned short ChanceOfSuccess();
	static unsigned short LongOrShort();
	float randomDouble();
class CActions : public CMatchPrep
{
protected:
	unsigned short randNumber;
public:
	std::vector<CPlayer*> stats;
	CActions();
	bool simulateAlgorithm(float AStatOne, float AStatTwo, float AStatThree, float DStatOne, float DStatTwo, float DStatThree);
	static unsigned short randNumGenerator(unsigned short number);
	virtual void FirstWhistle();
	void Shoot(CTeam& team1, CTeam& team2);
	void Pass(CTeam& team1, CTeam& team2);
	void Dribble(CTeam& team1, CTeam& team2);
	void Crossing(CTeam& team1, CTeam& team2);
	void Penalty(CTeam& team1, CTeam& team2);
	void Heading(CTeam& team1, CTeam& team2);
	void YellowCard(CTeam& team1, CTeam& team2);
	void RedCard(CTeam& team1, CTeam& team2);
	unsigned short PositionOfBall(); // is on deff side mid side att side
};
#endif
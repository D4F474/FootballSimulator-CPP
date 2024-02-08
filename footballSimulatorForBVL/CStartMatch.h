#ifndef C_START_MATCH
#define C_START_MATCH

#include "CActions.h"
class CStartMatch : public CActions
{
public:
	CStartMatch();
	CStartMatch(CTeam& team1, CTeam& team2);
	void FirstWhistle(CTeam& team1, CTeam& team2);
};
#endif
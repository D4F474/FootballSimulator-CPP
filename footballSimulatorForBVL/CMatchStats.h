#ifndef C_MATCH_STATS
#define C_MATCH_STATS

class CMatchStats
{
public:
	unsigned short Goals;
	unsigned short Minutes;
	unsigned short Possesion;
	unsigned short Tackles;
	unsigned short ShotsOnTarget;
	unsigned short ShotOffTarget;
	unsigned short Offside;
	unsigned short Passes;
	unsigned short YellowCard;
	unsigned short RedCard;

	void incrementGoals();
	void incrementPossesion();
	void incrementTackles();
	void incrementShotsOnTarget();
	void incrementShotOffTarget();
	void incrementOffSide();
	void incrementPasses();
	void incrementYellowCards();
	void incrementRedCards();
};
#endif
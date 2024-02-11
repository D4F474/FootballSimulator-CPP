#ifndef C_TEAM
#define C_TEAM
#include "CPlayer.h"
#include "CMatchStats.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

const unsigned short MAX_SIZE_OF_TEAM = 10;

class CTeam
{
private:
	std::vector<CPlayer*> Players;
	std::string NameOfTeam;
	CMatchStats* statForMatch;
	unsigned short randomNum;
	unsigned short Points;
	unsigned short Goals;
	unsigned short Wins;
	unsigned short Loses;
	unsigned short Draws;
	unsigned short TeamSize = 11;
	float TeamRating;
		
public:
	//32 23 4 5 5
	CTeam(std::string nameOfTeam, unsigned short points, unsigned short goals, unsigned short wins, unsigned short loses, unsigned short draws);
	friend std::ostream& operator << (std::ostream& toStream, const CTeam& team);
	void addPlayer(CPlayer& player);
	void printPlayers() const;
	CMatchStats* getStats() ;
	CPlayer* getGKPlayer() const;
	CPlayer* getDeffenderPlayer();
	CPlayer* getMidPlayer();
	CPlayer* getAttacker();
};
#endif
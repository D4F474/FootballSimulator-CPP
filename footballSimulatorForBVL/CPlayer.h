#ifndef C_Player
#define C_Player
#include <iostream>
#include "CPosition.h"
class CPlayer
{
protected:
	std::string FIRSTNAME;
	std::string LASTNAME;
	std::string POSSITION;
	unsigned short GOALS = 0;
	unsigned short ASSITS = 0;
	unsigned short YELLOW_CARDS = 0;
	unsigned short RED_CARDS = 0;
	unsigned short AGE = 0;
	double OVR = 0.01;
	CPosition* POSITION_STATS;
public:
	CPlayer();
	CPlayer(std::string firstName, std::string lastName, std::string possition, unsigned short age, CPosition*& positionStats);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getPossition() const;
	unsigned short getAge() const;
	unsigned short getOVR() const;
	CPosition* getPositionStats();
	friend std::ostream& operator << (std::ostream& toStream, const CPlayer& player);
};
#endif


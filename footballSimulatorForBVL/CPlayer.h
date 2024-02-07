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
	unsigned short GOALS;
	unsigned short ASSITS;
	unsigned short YELLOW_CARDS;
	unsigned short RED_CARDS;
	unsigned short AGE;
	float OVR;
	CPosition POSITION_STATS;
public:
	CPlayer(std::string firstName, std::string lastName, std::string possition, unsigned short age, CPosition& positionStats);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getPossition() const;
	unsigned short getAge() const;
	unsigned short getOVR() const;
	CPosition getPositionStats() const;
	friend std::ostream& operator << (std::ostream& toStream, const CPlayer& player);
};
#endif


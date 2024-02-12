#include "CPlayer.h"
//"Dafin", "Dafinov", "GK", "20", Position
CPlayer::CPlayer(std::string* firstName, std::string* lastName, std::string* possition, unsigned short* age, CPosition* positionStats)
{
	FIRSTNAME = firstName; 
	LASTNAME = lastName;
	POSSITION = possition;
	AGE = age;
	POSITION_STATS = *&positionStats;
	OVR = POSITION_STATS->getOVR();
}
std::string CPlayer::getFirstName()const
{
	return *FIRSTNAME;
}
std::string CPlayer::getLastName() const
{
	return *LASTNAME;
}
std::string CPlayer::getPossition() const
{
	return *POSSITION;
}
unsigned short CPlayer::getAge() const
{
	return *AGE;
}
unsigned short CPlayer::getOVR() const
{
	return OVR;
}
CPosition* CPlayer::getPositionStats() 
{
	return POSITION_STATS;
}
std::ostream& operator <<(std::ostream& toStream, const CPlayer& player)
{
	toStream << "---------------------" << std::endl
		<< "First name: " << player.FIRSTNAME << std::endl
		<< "Last name: " << player.LASTNAME << std::endl
		<< "Age: " << player.AGE << std::endl
		<< "position: " << player.POSSITION << std::endl
		<< "******************" << std::endl
		<< "Stats: " << std::endl
		<< "OVR: "<<player.OVR << std::endl
		<< player.POSITION_STATS << std::endl
		<< "******************";
	return toStream;
}

#include "CPosition.h"

CPosition::CPosition(std::string* pos, float* acceleration, float* stamina, float* strength, float* sprintSpeed,
	float* vision, float* slideTackle, float* standTackle, float* ballControll,
	float* dribbling, float* crossing, float* shortPass, float* longPass,
	float* heading, float* shotPower, float* longShot, float* penalties,
	float* finishing, float* GKPosstioning, float* GKDiving, float* GKHandling, float* GKKicking, float* Reflexes)
{
		*&POS = *&pos;
		*&ACCELERATION = *&acceleration;
		*&STAMINA = *&stamina;
		*&STRENGTH = *&strength;
		*&SPRINT_SPEED = *&sprintSpeed;
		*&DRIBBLING = *&dribbling;
		*&CROSSING = *&crossing;
		*&SHORT_PASS = *&shortPass;
		*&LONG_PASS = *&longPass;
		*&VISION = *&vision;
		*&SLIDE_TACKLE = *&slideTackle;
		*&STAND_TACKLE = *&standTackle;
		*&BALL_CONTROLL = *&ballControll;
		*&HEADING = *&heading;
		*&SHOT_POWER = *&shotPower;
		*&LONG_SHOT = *&longShot;
		*&PENALTIES = *&penalties;
		*&FINISHING = *&finishing;
		*&GK_POSSITIONING = *&GKPosstioning;
		*&GK_DIVING = *&GKDiving;
		*&GK_HANDLING = *&GKHandling;
		*&GK_KICKING = *&GKKicking;
		*&GK_REFLEXES = *&Reflexes;

	if (*POS == "ST" || *POS == "RW" || *POS == "LW")
	{
		//пРащаме с attackers coef-ти
		CAttackers* coef = new CAttackers();
		*OVR = (*ACCELERATION * *coef->COEF_ACCELERATION) + (*STAMINA * *coef->COEF_STAMINA) + (*STRENGTH * *coef->COEF_STRENGTH) + (*SPRINT_SPEED * *coef->COEF_SPRINT_SPEED) + (*DRIBBLING * *coef->COEF_DRIBBLING) + (*CROSSING * *coef->COEF_CROSSING) + (*SHORT_PASS * *coef->COEF_SHORT_PASS)
			+ (*LONG_PASS * *coef->COEF_LONG_PASS) + (*VISION * *coef->COEF_VISION) + (*SLIDE_TACKLE * *coef->COEF_SLIDE_TACKLE) + (*STAND_TACKLE * *coef->COEF_STAND_TACKLE) + (*BALL_CONTROLL * *coef->COEF_BALL_CONTROLL)
			+ (*HEADING * *coef->COEF_HEADING) + (*SHOT_POWER * *coef->COEF_SHOT_POWER) + (*LONG_SHOT * *coef->COEF_LONG_SHOT) + (*PENALTIES * *coef->COEF_PENALTIES) + (*FINISHING * *coef->COEF_FINISHING)
			+ (*GK_POSSITIONING * *coef->GK_POSITIONING) + (*GK_DIVING * *coef->GK_DIVING) + (*GK_HANDLING * *coef->GK_HANDLING) + (*GK_KICKING * *coef->GK_KICKING) + (*GK_REFLEXES * *coef->GK_REFLEXES);
		delete coef;
	}
	else if (*POS == "CM")
	{
		CCentralMid* coef = new CCentralMid();
		*OVR = (*ACCELERATION * *coef->COEF_ACCELERATION) + (*STAMINA * *coef->COEF_STAMINA) + (*STRENGTH * *coef->COEF_STRENGTH) + (*SPRINT_SPEED * *coef->COEF_SPRINT_SPEED) + (*DRIBBLING * *coef->COEF_DRIBBLING) + (*CROSSING * *coef->COEF_CROSSING) + (*SHORT_PASS * *coef->COEF_SHORT_PASS)
			+ (*LONG_PASS * *coef->COEF_LONG_PASS) + (*VISION * *coef->COEF_VISION) + (*SLIDE_TACKLE * *coef->COEF_SLIDE_TACKLE) + (*STAND_TACKLE * *coef->COEF_STAND_TACKLE) + (*BALL_CONTROLL * *coef->COEF_BALL_CONTROLL)
			+ (*HEADING * *coef->COEF_HEADING) + (*SHOT_POWER * *coef->COEF_SHOT_POWER) + (*LONG_SHOT * *coef->COEF_LONG_SHOT) + (*PENALTIES * *coef->COEF_PENALTIES) + (*FINISHING * *coef->COEF_FINISHING)
			+ (*GK_POSSITIONING * *coef->GK_POSITIONING) + (*GK_DIVING * *coef->GK_DIVING) + (*GK_HANDLING * *coef->GK_HANDLING) + (*GK_KICKING * *coef->GK_KICKING) + (*GK_REFLEXES * *coef->GK_REFLEXES);
		delete coef;
	}
	else if (*POS == "CB" || *POS == "RB" || *POS == "LB")
	{
		CDeffenders* coef = new CDeffenders();
		*OVR = (*ACCELERATION * *coef->COEF_ACCELERATION) + (*STAMINA * *coef->COEF_STAMINA) + (*STRENGTH * *coef->COEF_STRENGTH) + (*SPRINT_SPEED * *coef->COEF_SPRINT_SPEED) + (*DRIBBLING * *coef->COEF_DRIBBLING) + (*CROSSING * *coef->COEF_CROSSING) + (*SHORT_PASS * *coef->COEF_SHORT_PASS)
			+ (*LONG_PASS * *coef->COEF_LONG_PASS) + (*VISION * *coef->COEF_VISION) + (*SLIDE_TACKLE * *coef->COEF_SLIDE_TACKLE) + (*STAND_TACKLE * *coef->COEF_STAND_TACKLE) + (*BALL_CONTROLL * *coef->COEF_BALL_CONTROLL)
			+ (*HEADING * *coef->COEF_HEADING) + (*SHOT_POWER * *coef->COEF_SHOT_POWER) + (*LONG_SHOT * *coef->COEF_LONG_SHOT) + (*PENALTIES * *coef->COEF_PENALTIES) + (*FINISHING * *coef->COEF_FINISHING)
			+ (*GK_POSSITIONING * *coef->GK_POSITIONING) + (*GK_DIVING * *coef->GK_DIVING) + (*GK_HANDLING * *coef->GK_HANDLING) + (*GK_KICKING * *coef->GK_KICKING) + (*GK_REFLEXES * *coef->GK_REFLEXES);
		delete coef;
	}
	else if(*POS == "GK")
	{
		CGoalKeeper* coef = new CGoalKeeper();
		*OVR = (*ACCELERATION * *coef->COEF_ACCELERATION) + (*STAMINA * *coef->COEF_STAMINA) + (*STRENGTH * *coef->COEF_STRENGTH) + (*SPRINT_SPEED * *coef->COEF_SPRINT_SPEED) + (*DRIBBLING * *coef->COEF_DRIBBLING) + (*CROSSING * *coef->COEF_CROSSING) + (*SHORT_PASS * *coef->COEF_SHORT_PASS)
			+ (*LONG_PASS * *coef->COEF_LONG_PASS) + (*VISION * *coef->COEF_VISION) + (*SLIDE_TACKLE * *coef->COEF_SLIDE_TACKLE) + (*STAND_TACKLE * *coef->COEF_STAND_TACKLE) + (*BALL_CONTROLL * *coef->COEF_BALL_CONTROLL)
			+ (*HEADING * *coef->COEF_HEADING) + (*SHOT_POWER * *coef->COEF_SHOT_POWER) + (*LONG_SHOT * *coef->COEF_LONG_SHOT) + (*PENALTIES * *coef->COEF_PENALTIES) + (*FINISHING * *coef->COEF_FINISHING)
			+ (*GK_POSSITIONING * *coef->GK_POSITIONING) + (*GK_DIVING * *coef->GK_DIVING) + (*GK_HANDLING * *coef->GK_HANDLING) + (*GK_KICKING * *coef->GK_KICKING) + (*GK_REFLEXES * *coef->GK_REFLEXES);
		delete coef;
	}
}

//getters
float CPosition::getAcceleration() const
{
	return *ACCELERATION;
}
float CPosition::getStamina() const
{
	return *STAMINA;
}
float CPosition::getStrength() const
{
	return *STRENGTH;
}
float CPosition::getSprintSpeed() const
{
	return *SPRINT_SPEED;
}
float CPosition::getVision() const
{
	return *VISION;
}
float CPosition::getSlideTackle() const
{
	return *SLIDE_TACKLE;
}
float CPosition::getStandTackle() const
{
	return *STAND_TACKLE;
}
float CPosition::getBallControll() const
{
	return *BALL_CONTROLL;
}
float CPosition::getDribbling() const
{
	return *DRIBBLING;
}
float CPosition::getCrossing() const
{
	return *CROSSING;
}
float CPosition::getShortPass() const
{
	return *SHORT_PASS;
}
float CPosition::getLongPass() const
{
	return *LONG_PASS;
}
float CPosition::getHeading() const
{
	return *HEADING;
}
float CPosition::getShotPower() const
{
	return *SHOT_POWER;
}
float CPosition::getLongShot() const
{
	return *LONG_SHOT;
}
float CPosition::getPenalties() const
{
	return *PENALTIES;
}
float CPosition::getFinishing() const
{
	return *FINISHING;
}
float CPosition::getGKPossitioning() const
{
	return *GK_POSSITIONING;
}
float CPosition::getGKHandling() const
{
	return *GK_HANDLING;
}
float CPosition::getGKKicking() const
{
	return *GK_KICKING;
}
float CPosition::getReflexes() const
{
	return *GK_REFLEXES;
} 
double CPosition::getOVR() const
{
	return *OVR;
}

std::ostream& operator << (std::ostream& toStream, const CPosition& stats)
{
	toStream << "Acceleration: " << stats.ACCELERATION << std::endl
		<< "Stamina: " << stats.STAMINA << std::endl
		<< "Strength: " << stats.STRENGTH << std::endl
		<< "Sprint speed: " << stats.SPRINT_SPEED << std::endl
		<< "Vision: " << stats.VISION << std::endl
		<< "Slide tackle: " << stats.SLIDE_TACKLE << std::endl
		<< "Stand tackle: " << stats.STAND_TACKLE << std::endl
		<< "Ball controll: " << stats.BALL_CONTROLL << std::endl
		<< "Dribble: " << stats.DRIBBLING << std::endl
		<< "Crossing: " << stats.CROSSING << std::endl
		<< "Short pass: " << stats.SHORT_PASS << std::endl
		<< "Long pass: " << stats.LONG_PASS << std::endl
		<< "Heading: " << stats.HEADING << std::endl
		<< "Shot power: " << stats.SHOT_POWER << std::endl
		<< "Long shot: " << stats.LONG_SHOT << std::endl
		<< "Penalties: " << stats.PENALTIES << std::endl
		<< "Finishing: " << stats.FINISHING << std::endl
		<< "GK positioning: " << stats.GK_POSSITIONING << std::endl
		<< "GK diving: " << stats.GK_DIVING << std::endl
		<< "GK handling: " << stats.GK_HANDLING << std::endl
		<< "GK kicking: "<< stats.GK_KICKING << std::endl
		<< "GK Reflexes: " << stats.GK_REFLEXES << std::endl;
	return toStream;
}
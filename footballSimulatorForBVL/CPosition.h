#ifndef C_Position
#define C_Position
#include <iostream>
#include "CAttackers.h"
#include "CDeffenders.h"
#include "CCentralMid.h"
#include "CGoalKeeper.h"
class CPosition 
{
	private:
		std::string POS;
		float ACCELERATION;
		float STAMINA;
		float STRENGTH;
		float SPRINT_SPEED;
		float VISION;
		float SLIDE_TACKLE;
		float STAND_TACKLE;
		float BALL_CONTROLL;
		float DRIBBLING;
		float CROSSING;
		float SHORT_PASS;
		float LONG_PASS;
		float HEADING;
		float SHOT_POWER;
		float LONG_SHOT;
		float PENALTIES;
		float FINISHING;
		float GK_POSSITIONING;
		float GK_DIVING;
		float GK_HANDLING;
		float GK_KICKING;
		float GK_REFLEXES;
		float OVR;
	public:
		CPosition(std::string pos, float acceleration, float stamina, float strength, float sprintSpeed,
			float vision, float slideTackle, float standTackle, float ballControll,
			float dribbling, float crossing, float shortPass, float longPass,
			float heading, float shotPower, float longShot, float penalties,
			float finishing, float GKPosstioning, float GKDiving, float GKHandling, float GKKicking, float Reflexes);
		
		float getAcceleration() const;
		float getStamina() const;
		float getStrength() const;
		float getSprintSpeed() const;
		float getVision() const;
		float getSlideTackle() const;
		float getStandTackle() const;
		float getBallControll() const;
		float getDribbling() const;
		float getCrossing() const;
		float getShortPass() const;
		float getLongPass() const;
		float getHeading() const;
		float getShotPower() const;
		float getLongShot() const;
		float getPenalties() const;
		float getFinishing() const;
		float getGKPossitioning() const;
		float getGKHandling() const;
		float getGKKicking() const;
		float getReflexes() const;
		float getOVR() const;

		friend std::ostream& operator << (std::ostream& toStream, const CPosition& stats);
};
#endif
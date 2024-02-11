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
		std::string POS = "";
		float* ACCELERATION = 0;
		float* STAMINA = 0;
		float* STRENGTH = 0;
		float* SPRINT_SPEED = 0;
		float* VISION = 0;
		float* SLIDE_TACKLE = 0;
		float* STAND_TACKLE = 0;
		float* BALL_CONTROLL = 0;
		float* DRIBBLING = 0;
		float* CROSSING = 0;
		float* SHORT_PASS = 0;
		float* LONG_PASS = 0;
		float* HEADING = 0;
		float* SHOT_POWER = 0;
		float* LONG_SHOT = 0;
		float* PENALTIES = 0;
		float* FINISHING = 0;
		float* GK_POSSITIONING = 0;
		float* GK_DIVING = 0;
		float* GK_HANDLING = 0;
		float* GK_KICKING = 0;
		float* GK_REFLEXES = 0;
		double* OVR = 0;
	public:
		CPosition();
		CPosition(std::string* pos, float* acceleration, float* stamina, float* strength, float* sprintSpeed,
			float* vision, float* slideTackle, float* standTackle, float* ballControll,
			float* dribbling, float* crossing, float* shortPass, float* longPass,
			float* heading, float* shotPower, float* longShot, float* penalties,
			float* finishing, float* GKPosstioning, float* GKDiving, float* GKHandling, float* GKKicking, float* Reflexes);
		
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
		double getOVR() const;

		friend std::ostream& operator << (std::ostream& toStream, const CPosition& stats);
};
#endif
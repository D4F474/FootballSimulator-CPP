#ifndef C_Attackers
#define C_Attackers
#include "CPosition.h"
class CAttackers
{
public:
	CAttackers();
	float* COEF_ACCELERATION = new float;
	float* COEF_STAMINA = new float;
	float* COEF_STRENGTH = new float;
	float* COEF_SPRINT_SPEED = new float;
	float* COEF_VISION = new float;
	float* COEF_SLIDE_TACKLE = new float;
	float* COEF_STAND_TACKLE = new float;
	float* COEF_BALL_CONTROLL = new float;
	float* COEF_DRIBBLING = new float;
	float* COEF_CROSSING = new float;
	float* COEF_SHORT_PASS = new float;
	float* COEF_LONG_PASS = new float;
	float* COEF_HEADING = new float;
	float* COEF_SHOT_POWER = new float;
	float* COEF_LONG_SHOT = new float;
	float* COEF_PENALTIES = new float;
	float* COEF_FINISHING = new float;
	float* GK_POSITIONING = new float;
	float* GK_DIVING = new float;
	float* GK_HANDLING = new float;
	float* GK_KICKING = new float;
	float* GK_REFLEXES = new float;

};
#endif

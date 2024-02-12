#ifndef C_Attackers
#define C_Attackers
#include "CPosition.h"
class CAttackers
{
public:
	CAttackers();
	float* COEF_ACCELERATION;
	float* COEF_STAMINA;
	float* COEF_STRENGTH ;
	float* COEF_SPRINT_SPEED ;
	float* COEF_VISION;
	float* COEF_SLIDE_TACKLE;
	float* COEF_STAND_TACKLE;
	float* COEF_BALL_CONTROLL;
	float* COEF_DRIBBLING;
	float* COEF_CROSSING ;
	float* COEF_SHORT_PASS;
	float* COEF_LONG_PASS;
	float* COEF_HEADING;
	float* COEF_SHOT_POWER;
	float* COEF_LONG_SHOT;
	float* COEF_PENALTIES;
	float* COEF_FINISHING;
	float* GK_POSITIONING;
	float* GK_DIVING;
	float* GK_HANDLING;
	float* GK_KICKING;
	float* GK_REFLEXES;

};
#endif

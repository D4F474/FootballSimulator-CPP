#include "CAttackers.h"

CAttackers::CAttackers()
{
	*COEF_ACCELERATION = 0.12;
	*COEF_STAMINA = 0.1;
	*COEF_STRENGTH = 0.08;
	*COEF_SPRINT_SPEED = 0.12;
	*COEF_VISION = 0.1;
	*COEF_SLIDE_TACKLE = 0.08;
	*COEF_STAND_TACKLE = 0.08;
	*COEF_BALL_CONTROLL = 0.07;
	*COEF_DRIBBLING = 0.07;
	*COEF_CROSSING = 0.08;
	*COEF_SHORT_PASS = 0.08;
	*COEF_LONG_PASS = 0.08;
	*COEF_HEADING = 0.06;
	*COEF_SHOT_POWER = 0.1;
	*COEF_LONG_SHOT = 0.1;
	*COEF_PENALTIES = 0.1;
	*COEF_FINISHING = 0.11;
	*GK_POSITIONING = 0.01;
	*GK_DIVING = 0.01;
	*GK_HANDLING = 0.01;
	*GK_KICKING = 0.01;
	*GK_REFLEXES = 0.01;
}
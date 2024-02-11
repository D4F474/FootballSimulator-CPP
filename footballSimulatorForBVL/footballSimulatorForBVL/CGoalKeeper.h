#ifndef C_GOALKEEPER
#define C_GOALKEEPER
class CGoalKeeper
{
public:
	const float COEF_ACCELERATION = 0.04;
	const float COEF_STAMINA = 0.06;
	const float COEF_STRENGTH = 0.06;
	const float COEF_SPRINT_SPEED = 0.04;
	const float COEF_VISION = 0.13;
	const float COEF_SLIDE_TACKLE =0.11;
	const float COEF_STAND_TACKLE = 0.11;
	const float COEF_BALL_CONTROLL = 0.05;
	const float COEF_DRIBBLING =0.03;
	const float COEF_CROSSING = 0.01;
	const float COEF_SHORT_PASS = 0.03;
	const float COEF_LONG_PASS = 0.06;
	const float COEF_HEADING = 0.01;
	const float COEF_SHOT_POWER =0.05;
	const float COEF_LONG_SHOT = 0.04;
	const float COEF_PENALTIES = 0.1;
	const float COEF_FINISHING = 0.01;
	const float GK_POSITIONING = 0.15;
	const float GK_DIVING = 0.15;
	const float GK_HANDLING = 0.15;
	const float GK_KICKING = 0.15;
	const float GK_REFLEXES = 0.15;
};
#endif
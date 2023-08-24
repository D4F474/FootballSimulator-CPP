#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> 
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//numberOfClubs
const unsigned short spartakSofia = 0;
const unsigned short chamkoria = 1;
const unsigned short cherniOrli = 2;
const unsigned short Etar = 3;
const unsigned short torpedoRazgrad = 4;
const unsigned short odrisa = 5;
const unsigned short rilskiOrli = 6;
const unsigned short trakiq = 7;
const unsigned short arsenalSofia = 8;
const unsigned short slava = 9;
const unsigned short olimpik = 10;
const unsigned short Irinopolis = 11;
const unsigned short shumen = 12;
const unsigned short odesos = 13;

//Goal Keeper Coef
const double GK_POSSITIONING = 0.12;
const double GK_Diving = 0.12f;
const double GK_Handling = 0.12;
const double GK_Kicking = 0.12;
const double GK_Reflexes = 0.12;
const double GK_Short_pass = 0.07;
const double GK_Long_pass = 0.07;
const double GK_Vision = 0.1;
const double GK_Aggression = 0.02;
const double GK_Reactions = 0.05;
const double GK_Acceleration = 0.1;
const double GK_Stamina = 0.08;
const double GK_Balance = 0.1;

//Right And Left BackCoef
const double RB_LB_ACCELERATION = 0.1;
const double RB_LB_STAMINA = 0.08;
const double RB_LB_STRENGTH = 0.06;
const double RB_LB_SPRINT_SPEED = 0.06;
const double RB_LB_AGILITY = 0.04;
const double RB_LB_VISION = 0.1;
const double RB_LB_SLIDE_TACKLE = 0.12;
const double RB_LB_STAND_TACKLE = 0.12;
const double RB_LB_BALL_CONTROL = 0.07;
const double RB_LB_DRIBBLING = 0.05;
const double RB_LB_CROSSING = 0.05;
const double RB_LB_SHORT_PASS = 0.04;
const double RB_LB_LONG_PASS = 0.04;

//Central Back Coef
const double CB_SLIDE_TACKLE = 0.15;
const double CB_STAND_TACKLE = 0.15;
const double CB_AGGRESSION = 0.06;
const double CB_VISION = 0.09;
const double CB_ACCELERATION = 0.07;
const double CB_STAMINA = 0.1;
const double CB_STRENGTH = 0.1;
const double CB_BALANCE = 0.1;
const double CB_JUMPING = 0.05;
const double CB_HEADING = 0.06;
const double CB_SHOT_POWER = 0.05;
const double CB_BALL_CONTROL = 0.04;
const double CB_DRIBBLING = 0.04;

//Central Defense Midfilder Coef
const double CDM_BALL_CONTROL = 0.15;
const double CDM_DRIBBLING = 0.15;
const double CDM_CROSSING = 0.04;
const double CDM_SHORT_PASS = 0.12;
const double CDM_LONG_PASS = 0.12;
const double CDM_SHOT_POWER = 0.06;
const double CDM_LONG_SHOT = 0.05;
const double CDM_PENALTIES = 0.03;
const double CDM_BALANCE = 0.06;
const double CDM_STAMINA = 0.1;
const double CDM_JUMPING = 0.06;
const double CDM_SLIDE_TACKLE = 0.06;
const double CDM_STAND_TACKLE = 0.08;

//Central Midfilder Coef
const double CM_BALL_CONTROL = 0.14;
const double CM_DRIBBLING = 0.13;
const double CM_CROSSING = 0.05;
const double CM_SHORT_PASS = 0.1;
const double CM_LONG_PASS = 0.12;
const double CM_SHOT_POWER = 0.06;
const double CM_LONG_SHOT = 0.05;
const double CM_PENALTIES = 0.04;
const double CM_BALANCE = 0.06;
const double CM_STAMINA = 0.07;
const double CM_JUMPING = 0.07;
const double CM_SLIDE_TACKLE = 0.04;
const double CM_STAND_TACKLE = 0.06;

//Central Attack Midfilder Coef
const double CAM_BALL_CONTROL = 0.12;
const double CAM_DRIBBLING = 0.09;
const double CAM_CROSSING = 0.02;
const double CAM_SHORT_PASS = 0.1;
const double CAM_LONG_PASS = 0.14;
const double CAM_SHOT_POWER = 0.08;
const double CAM_LONG_SHOT = 0.07;
const double CAM_PENALTIES = 0.05;
const double CAM_BALANCE = 0.05;
const double CAM_STAMINA = 0.08;
const double CAM_JUMPING = 0.08;
const double CAM_SLIDE_TACKLE = 0.05;
const double CAM_STAND_TACKLE = 0.06;

//Right/Left Winger Coef
const double RW_LW_SHOT_POWER = 0.07;
const double RW_LW_FINISHING = 0.1;
const double RW_LW_LONG_SHOT = 0.09;
const double RW_LW_CURVE = 0.1;
const double RW_LW_FK_ACC = 0.07;
const double RW_LW_VOLLEYS = 0.05;
const double RW_LW_CROSSING = 0.12;
const double RW_LW_SHORT_PASS = 0.1;
const double RW_LW_LONG_PASS = 0.15;
const double RW_LW_BALL_CONTROL = 0.09;
const double RW_LW_DRIBLING = 0.1;
const double RW_LW_ACCELERATION = 0.12;
const double RW_LW_SPRINT_SPEEED = 0.11;

//Striker Coef
const double ST_HEADING = 0.08;
const double ST_SHOT_POWER = 0.13;
const double ST_FINISHING = 0.15;
const double ST_CURVE = 0.09;
const double ST_PENALTIES = 0.04;
const double ST_VOLLEYS = 0.07;
const double ST_VISION = 0.08;
const double ST_ACCELERATION = 0.07;
const double ST_STRENGTH = 0.08;
const double ST_SPRINT_SPEED = 0.1;
const double ST_JUMPING = 0.1;
const double ST_BALL_CONTROL = 0.1;
const double ST_DRIBBLING = 0.1;

const unsigned short MAX_TEAMS = 14;

//Menu Constants
const unsigned short MENU_OPTIONS = 5;
const unsigned short TEAMSSTATSBYMATCH = 1;


struct goalKeeper
{
	string nameOfPlayer;
	float gkPositioning = 0, gkDiving = 0, gkHandling = 0, gkKicking = 0, gkReflex = 0, shortPass = 0, longPass = 0, vision = 0, aggression = 0, reactions = 0, acceleration = 0, stamina = 0, balance = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct centralBack1
{
	string nameOfPlayer;
	float slideTackle = 0, standTackle = 0, aggression = 0, vision = 0, acceleration = 0, stamina = 0, strength = 0, balance = 0, jumping = 0, heading = 0, shotPower = 0, ballControl = 0, dribbling = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct centralBack2
{
	string nameOfPlayer;
	float slideTackle = 0, standTackle = 0, aggression = 0, vision = 0, acceleration = 0, stamina = 0, strength = 0, balance = 0, jumping = 0, heading = 0, shotPower = 0, ballControl = 0, dribbling = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct rightBack
{
	string nameOfPlayer;
	float acceleration = 0, stamina = 0, strength = 0, sprintSpeed = 0, agility = 0, vision = 0, slideTackle = 0, stanTackle = 0, ballControl = 0, dribbling = 0, crossing = 0, shortPass = 0, longPass = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct leftBack
{
	string nameOfPlayer;
	float acceleration = 0, stamina = 0, strength = 0, sprintSpeed = 0, agility = 0, vision = 0, slideTackle = 0, stanTackle = 0, ballControl = 0, dribbling = 0, crossing = 0, shortPass = 0, longPass = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct centralMiddfilder1
{
	string nameOfPlayer;
	float ballControl = 0, dribbling = 0, crossing = 0, shortPass = 0, longPass = 0, shotPower = 0, longShot = 0, penalties = 0, balance = 0, stamina = 0, jumping = 0, slideTackle = 0, standTackle = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct centralMiddfilder2
{
	string nameOfPlayer;
	float ballControl = 0, dribbling = 0, crossing = 0, shortPass = 0, longPass = 0, shotPower = 0, longShot = 0, penalties = 0, balance = 0, stamina = 0, jumping = 0, slideTackle = 0, standTackle = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct centralAttackMiddfilder
{
	string nameOfPlayer;
	float ballControl = 0, dribbling = 0, crossing = 0, shortPass = 0, longPass = 0, shotPower = 0, longShot = 0, penalties = 0, balance = 0, stamina = 0, jumping = 0, slideTackle = 0, standTackle = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct leftWinger
{
	string nameOfPlayer;
	float shotPower = 0, finishing = 0, longShot = 0, curve = 0, fKAcc = 0, volleys = 0, crossing = 0, shortPass = 0, longPass = 0, ballControl = 0, dribbling = 0, acceleration = 0, sprintSpeed = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct rightWinger
{
	string nameOfPlayer;
	float shotPower = 0, finishing = 0, longShot = 0, curve = 0, fKAcc = 0, volleys = 0, crossing = 0, shortPass = 0, longPass = 0, ballControl = 0, dribbling = 0, acceleration = 0, sprintSpeed = 0, overall = 0, energy = 100, sharpnes = 30;
};
struct striker
{
	string nameOfPlayer;
	float heading = 0, shotPower = 0, finishing = 0, curve = 0, penalties = 0, voleys = 0, vision = 0, acceleration = 0, strength = 0, sprintSpeed = 0, jumping = 0, ballControl = 0, dribbling = 0, overall = 0, energy = 100, sharpnes = 30;
};

struct footballPlayer
{
	string clubName;
	goalKeeper statsForGK;
	centralBack1 statsForCB1;
	centralBack2 statsForCB2;
	rightBack statsForRB;
	leftBack statsForLB;
	centralMiddfilder1 statsForCM1;
	centralMiddfilder2 statsForCM2;
	centralAttackMiddfilder statsForCAM;
	leftWinger statsForLW;
	rightWinger statsForRW;
	striker statsForST;
	float sumOVRByTeam =0;
	float deffencePercent = 0;
	float midPercent = 0;
	float fowardPercent = 0;
	unsigned short points =0, matchesPlayed = 0,wins = 0 ,draws =0, loses =0, scoredGoals = 0, fans =0, concededGoals = 0;
	short goalDiff = 0;
};

//prototypes
unsigned short menu();
int enterStatsByPlayer();
void showTeams();
void overalSum();
void leaderBoard();
void simulateMatches();
void summingOVRByPossition();
void randomTeamToAttack(struct matchStats& msH, struct matchStats& msA);
void teamHome(struct matchStats& msH, struct matchStats& msA);
void teamAway(struct matchStats& msA, struct matchStats& msH);
void scoringHome(struct matchStats& msH, struct matchStats& msA);
unsigned short possesionHome(struct matchStats& msH, struct matchStats& msA);
void chanceCreatedHome(struct matchStats& msH);
void eventsCreatedHome(struct matchStats& msH);
void injuryHome(unsigned short randomPickEvent, struct matchStats& msH);
void redCardHome(unsigned short randomPickEvent, struct matchStats& msH);
void yellowcardHome(unsigned short randomPickEvent, struct matchStats& msH);
void scoringAway(struct matchStats& msA, struct matchStats& msH);
unsigned short possesionAway(struct matchStats& msA , struct matchStats& mH);
void chanceCreatedAway(struct matchStats& msA);
void eventsCreatedAway(struct matchStats& msA);
void injuryAway(unsigned short randomPickEvent, struct matchStats& msA);
void redCardAway(unsigned short randomPickEvent, struct matchStats& msA);
void yellowcardAway(unsigned short randomPickEvent, struct matchStats& msA);



//variables
unsigned short teamCounter = 1;
footballPlayer stats[14];
unsigned short enteredTeamsCount = 0;
unsigned short goalsTeam1 = 0;
unsigned short goalsTeam2 = 0;
vector<string>leaderboard;


int main()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_TEAMS; i++)
	{
		enterStatsByPlayer();

	}

		overalSum();

		unsigned short menuItem;
	do
	{
		menuItem = menu();
		switch (menuItem)
		{
		case 1: showTeams();
			system("PAUSE");
			system("CLS");
			 break;
		case 2: leaderBoard(); break;
		case 3:summingOVRByPossition();
			   simulateMatches();
				break;
		//case 4: checkNameOfTeams(); break;
		default:
			cout << "Stop program";
		}
	} while (menuItem != MENU_OPTIONS);
	return 0;
}

unsigned short menu()
{
	unsigned short choise;
	cout << "*******" << endl;
	cout << "*** Menu ***" << endl;
	cout << "1.Check Teams" << endl;
	cout << "2.Check leaderboard" << endl;
	cout << "3.Simulate match" << endl;
	cout << "4.Simulate round" << endl;
	cout << "5.Quit" << endl;
	do {
		cout << "Choise option" << endl;
		cin >> choise;
	} while (choise < 1 || choise > MENU_OPTIONS);
	return choise;
}

int enterStatsByPlayer()
{
		ifstream ifs;
		string stringFromFile;


		ifs.open("C:\\Users\\d4f474\\Desktop\\project\\Team" + to_string(teamCounter) + ".txt");
		if (!ifs)
		{
			cout << "CANT OPEN THIS SHIT";
		}
		else {
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].clubName = stringFromFile;
			//GK
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForGK.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.gkPositioning += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.gkDiving += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.gkHandling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.gkKicking += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.gkReflex += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.aggression += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.reactions += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForGK.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

			//RB
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForRB.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.acceleration += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.strength += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.sprintSpeed += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.agility += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.slideTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.stanTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRB.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

			//CB1
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForCB1.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.slideTackle += num;
			}
			catch (const invalid_argument& e) {

				return -1;

			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.standTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.aggression += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.strength += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.heading += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB1.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

			//CB2
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForCB2.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.slideTackle += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.standTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.aggression += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.strength += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.heading += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCB2.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

			//LB
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForLB.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.acceleration += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.strength += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.sprintSpeed += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.agility += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.slideTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.stanTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLB.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {

				float num = stof(stringFromFile);

				stats[enteredTeamsCount].statsForLB.longPass += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {

				return -1;
			}
			//CM1
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForCM1.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.ballControl += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.longShot += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.penalties += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.slideTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM1.standTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

			//CM2
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForCM2.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.ballControl += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {

				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.longShot += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.penalties += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.slideTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCM2.standTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			//CAM
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForCAM.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.ballControl += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.longShot += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.penalties += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.balance += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.stamina += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.slideTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForCAM.standTackle += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			//RW
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForRW.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.shotPower += num;
			}
			catch (const invalid_argument& e) {

				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.finishing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.longShot += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.curve += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.fKAcc += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.volleys += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForRW.sprintSpeed += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			//ST
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForST.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.heading += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.finishing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.curve += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.penalties += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.voleys += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.vision += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.strength += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.sprintSpeed += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.jumping += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForST.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			//LW
			getline(ifs, stringFromFile);
			stats[enteredTeamsCount].statsForLW.nameOfPlayer = stringFromFile;
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.shotPower += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.finishing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.longShot += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.curve += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.fKAcc += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.volleys += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.crossing += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.shortPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.longPass += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.ballControl += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.dribbling += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.acceleration += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}
			getline(ifs, stringFromFile);
			try {
				float num = stof(stringFromFile);
				stats[enteredTeamsCount].statsForLW.sprintSpeed += num;
			}
			catch (const invalid_argument& e) {
				return -1;
			}
			catch (const out_of_range& e) {
				return -1;
			}

		}
		ifs.close();
		enteredTeamsCount++;
		teamCounter++;
		return 0;
	}

void showTeams()
{
	system("CLS");
	for (int i = 0; i < teamCounter-1; i++)
	{
		cout << i + 1 <<". " << stats[i].clubName << " OVR:" << setprecision(2)<< stats[i].sumOVRByTeam << endl;
		cout << "                                                         GK: " << stats[i].statsForGK.nameOfPlayer  <<" OVR: "<<stats[i].statsForGK.overall << endl;
		cout << "RB: " << stats[i].statsForRB.nameOfPlayer << " OVR: " << stats[i].statsForRB.overall;
		cout << "            RCB: " << stats[i].statsForCB1.nameOfPlayer <<"            LCB: " << stats[i].statsForCB2.nameOfPlayer;
		cout << "  LB:" << stats[i].statsForLB.nameOfPlayer << " OVR: "<< stats[i].statsForLB.overall << endl;
		cout << "                                    RCM: " << stats[i].statsForCM1.nameOfPlayer << "OVR: " << stats[i].statsForCM1.overall << "            LCM: " << stats[i].statsForCM2.nameOfPlayer << "OVR: " << stats[i].statsForCM1.overall << endl;
		cout << "                                                CAM: " << stats[i].statsForCAM.nameOfPlayer << "OVR: " << stats[i].statsForCAM.overall << endl;
		cout << "                 RW: " << stats[i].statsForRW.nameOfPlayer << "OVR: " << stats[i].statsForRW.overall << "            ST: " << stats[i].statsForST.nameOfPlayer <<stats[i].statsForST.overall << "            LW: " << stats[i].statsForLW.nameOfPlayer << "OVR: " << stats[i].statsForLW.overall << endl;
		cout << "---------------------" << endl;
	
	}
		system("Pause");
	}

void overalSum()
{
	for (int i = 0; i < teamCounter - 1; i++)
	{
		//GK
		stats[i].statsForGK.overall =round((GK_POSSITIONING * stats[i].statsForGK.gkPositioning) + (GK_Diving * stats[i].statsForGK.gkDiving) + (GK_Handling*stats[i].statsForGK.gkHandling) + (GK_Kicking * stats[i].statsForGK.gkKicking) + (GK_Reflexes*stats[i].statsForGK.gkReflex) + (GK_Short_pass * stats[i].statsForGK.shortPass) + (GK_Long_pass *stats[i].statsForGK.longPass) + (GK_Vision * stats[i].statsForGK.vision) + (GK_Aggression * stats[i].statsForGK.aggression) + (GK_Reactions * stats[i].statsForGK.reactions) + (GK_Acceleration * stats[i].statsForGK.acceleration) + (GK_Stamina * stats[i].statsForGK.stamina) + (GK_Balance * stats[i].statsForGK.balance)); // почни да правиш сметките за ovr на играчите
		//RB
		stats[i].statsForRB.overall = round((RB_LB_ACCELERATION * stats[i].statsForRB.acceleration) + (RB_LB_STAMINA * stats[i].statsForRB.stamina) + (RB_LB_STRENGTH * stats[i].statsForRB.strength) + (RB_LB_SPRINT_SPEED * stats[i].statsForRB.sprintSpeed) + (RB_LB_AGILITY * stats[i].statsForRB.agility) + (RB_LB_VISION * stats[i].statsForRB.vision) + (RB_LB_SLIDE_TACKLE * stats[i].statsForRB.slideTackle) + (RB_LB_STAND_TACKLE * stats[i].statsForRB.stanTackle) + (RB_LB_BALL_CONTROL * stats[i].statsForRB.ballControl) + (RB_LB_DRIBBLING * stats[i].statsForRB.dribbling) + (RB_LB_CROSSING * stats[i].statsForRB.crossing) + (RB_LB_SHORT_PASS * stats[i].statsForRB.shortPass) + (RB_LB_LONG_PASS * stats[i].statsForRB.longPass));
		//CB
		stats[i].statsForCB1.overall = round((CB_SLIDE_TACKLE * stats[i].statsForCB1.slideTackle) + (CB_STAND_TACKLE * stats[i].statsForCB1.standTackle) + (CB_AGGRESSION * stats[i].statsForCB1.aggression) + (CB_VISION * stats[i].statsForCB1.vision) + (CB_ACCELERATION * stats[i].statsForCB1.acceleration) + (CB_STAMINA * stats[i].statsForCB1.stamina) + (CB_STRENGTH * stats[i].statsForCB1.strength) + (CB_BALANCE * stats[i].statsForCB1.balance) + (CB_JUMPING * stats[i].statsForCB1.jumping) + (CB_HEADING * stats[i].statsForCB1.heading) + (CB_SHOT_POWER * stats[i].statsForCB1.shotPower) + (CB_BALL_CONTROL* stats[i].statsForCB1.ballControl) + (CB_DRIBBLING* stats[i].statsForCB1.dribbling));
		stats[i].statsForCB2.overall = round((CB_SLIDE_TACKLE * stats[i].statsForCB2.slideTackle) + (CB_STAND_TACKLE * stats[i].statsForCB2.standTackle) + (CB_AGGRESSION * stats[i].statsForCB2.aggression) + (CB_VISION * stats[i].statsForCB2.vision) + (CB_ACCELERATION * stats[i].statsForCB2.acceleration) + (CB_STAMINA * stats[i].statsForCB2.stamina) + (CB_STRENGTH * stats[i].statsForCB2.strength) + (CB_BALANCE * stats[i].statsForCB2.balance) + (CB_JUMPING * stats[i].statsForCB2.jumping) + (CB_HEADING * stats[i].statsForCB2.heading) + (CB_SHOT_POWER * stats[i].statsForCB2.shotPower) + (CB_BALL_CONTROL * stats[i].statsForCB2.ballControl) + (CB_DRIBBLING * stats[i].statsForCB2.dribbling));
		//LB
		stats[i].statsForLB.overall = round((RB_LB_ACCELERATION * stats[i].statsForLB.acceleration) + (RB_LB_STAMINA * stats[i].statsForLB.stamina) + (RB_LB_STRENGTH * stats[i].statsForLB.strength) + (RB_LB_SPRINT_SPEED * stats[i].statsForLB.sprintSpeed) + (RB_LB_AGILITY * stats[i].statsForLB.agility) + (RB_LB_VISION * stats[i].statsForLB.vision) + (RB_LB_SLIDE_TACKLE * stats[i].statsForLB.slideTackle) + (RB_LB_STAND_TACKLE * stats[i].statsForLB.stanTackle) + (RB_LB_BALL_CONTROL * stats[i].statsForLB.ballControl) + (RB_LB_DRIBBLING * stats[i].statsForLB.dribbling) + (RB_LB_CROSSING * stats[i].statsForLB.crossing) + (RB_LB_SHORT_PASS * stats[i].statsForLB.shortPass) + (RB_LB_LONG_PASS * stats[i].statsForLB.longPass));
		//CM
		stats[i].statsForCM1.overall = round((CM_BALL_CONTROL * stats[i].statsForCM1.ballControl) + (CM_DRIBBLING * stats[i].statsForCM1.dribbling) + (CM_CROSSING * stats[i].statsForCM1.crossing) + (CM_SHORT_PASS * stats[i].statsForCM1.shortPass) + (CM_LONG_PASS *stats[i].statsForCM1.longPass) + (CM_SHOT_POWER * stats[i].statsForCM1.shotPower) + (CM_LONG_SHOT * stats[i].statsForCM1.longShot) + (CM_PENALTIES * stats[i].statsForCM1.penalties) + (CM_BALANCE * stats[i].statsForCM1.balance) + (CM_STAMINA * stats[i].statsForCM1.stamina) + (CM_JUMPING * stats[i].statsForCM1.jumping) + (CM_SLIDE_TACKLE * stats[i].statsForCM1.slideTackle) + (CM_STAND_TACKLE * stats[i].statsForCM1.standTackle));
		stats[i].statsForCM2.overall = round((CM_BALL_CONTROL * stats[i].statsForCM2.ballControl) + (CM_DRIBBLING * stats[i].statsForCM2.dribbling) + (CM_CROSSING * stats[i].statsForCM2.crossing) + (CM_SHORT_PASS * stats[i].statsForCM2.shortPass) + (CM_LONG_PASS * stats[i].statsForCM2.longPass) + (CM_SHOT_POWER * stats[i].statsForCM2.shotPower) + (CM_LONG_SHOT * stats[i].statsForCM2.longShot) + (CM_PENALTIES * stats[i].statsForCM2.penalties) + (CM_BALANCE * stats[i].statsForCM2.balance) + (CM_STAMINA * stats[i].statsForCM2.stamina) + (CM_JUMPING * stats[i].statsForCM2.jumping) + (CM_SLIDE_TACKLE * stats[i].statsForCM2.slideTackle) + (CM_STAND_TACKLE * stats[i].statsForCM2.standTackle));
		//CAM
		stats[i].statsForCAM.overall = round((CAM_BALL_CONTROL * stats[i].statsForCAM.ballControl) + (CAM_DRIBBLING * stats[i].statsForCAM.dribbling) + (CAM_CROSSING * stats[i].statsForCAM.crossing) + (CAM_SHORT_PASS * stats[i].statsForCAM.shortPass) + (CAM_LONG_PASS * stats[i].statsForCAM.longPass) + (CAM_SHOT_POWER * stats[i].statsForCAM.shotPower) + (CAM_LONG_SHOT * stats[i].statsForCAM.longShot) + (CAM_PENALTIES * stats[i].statsForCAM.penalties) + (CAM_BALANCE * stats[i].statsForCAM.balance) + (CAM_STAMINA * stats[i].statsForCAM.stamina) + (CAM_JUMPING * stats[i].statsForCAM.jumping) + (CAM_SLIDE_TACKLE * stats[i].statsForCAM.slideTackle) + (CAM_STAND_TACKLE * stats[i].statsForCAM.standTackle));
		//RW
		stats[i].statsForRW.overall = round((RW_LW_SHOT_POWER * stats[i].statsForRW.shotPower) + (RW_LW_FINISHING * stats[i].statsForRW.finishing) + (RW_LW_LONG_SHOT * stats[i].statsForRW.longShot) + (RW_LW_CURVE * stats[i].statsForRW.curve) + (RW_LW_FK_ACC * stats[i].statsForRW.fKAcc) + (RW_LW_VOLLEYS * stats[i].statsForRW.volleys) + (RW_LW_CROSSING * stats[i].statsForRW.crossing) +(RW_LW_SHORT_PASS * stats[i].statsForRW.shortPass) + (RW_LW_LONG_PASS * stats[i].statsForRW.longPass) + (RW_LW_BALL_CONTROL * stats[i].statsForRW.ballControl) + (RW_LW_DRIBLING * stats[i].statsForRW.dribbling) + (RW_LW_ACCELERATION * stats[i].statsForRW.acceleration) + (RW_LW_SPRINT_SPEEED * stats[i].statsForRW.sprintSpeed));
		//ST
		stats[i].statsForST.overall = round((ST_HEADING * stats[i].statsForST.heading) + (ST_SHOT_POWER * stats[i].statsForST.shotPower) + (ST_FINISHING * stats[i].statsForST.finishing) + (ST_CURVE * stats[i].statsForST.curve) + (ST_PENALTIES * stats[i].statsForST.penalties) + (ST_VOLLEYS * stats[i].statsForST.voleys) + (ST_VISION * stats[i].statsForST.vision) + (ST_ACCELERATION * stats[i].statsForST.acceleration) + (ST_STRENGTH * stats[i].statsForST.strength) + (ST_SPRINT_SPEED * stats[i].statsForST.sprintSpeed) + (ST_JUMPING * stats[i].statsForST.jumping) + (ST_BALL_CONTROL * stats[i].statsForST.ballControl) + (ST_DRIBBLING * stats[i].statsForST.dribbling));
		//LW
		stats[i].statsForLW.overall = ((RW_LW_SHOT_POWER * stats[i].statsForLW.shotPower) + (RW_LW_FINISHING * stats[i].statsForLW.finishing) + (RW_LW_LONG_SHOT * stats[i].statsForLW.longShot) + (RW_LW_CURVE * stats[i].statsForLW.curve) + (RW_LW_FK_ACC * stats[i].statsForLW.fKAcc) + (RW_LW_VOLLEYS * stats[i].statsForLW.volleys) + (RW_LW_CROSSING * stats[i].statsForLW.crossing) + (RW_LW_SHORT_PASS * stats[i].statsForLW.shortPass) + (RW_LW_LONG_PASS * stats[i].statsForLW.longPass) + (RW_LW_BALL_CONTROL * stats[i].statsForLW.ballControl) + (RW_LW_DRIBLING * stats[i].statsForLW.dribbling) + (RW_LW_ACCELERATION * stats[i].statsForLW.acceleration) + (RW_LW_SPRINT_SPEEED * stats[i].statsForLW.sprintSpeed));
	}
	for (int i = 0; i < teamCounter - 1; i++)
	{
		stats[i].sumOVRByTeam = round((stats[i].statsForGK.overall + stats[i].statsForRB.overall + stats[i].statsForCB1.overall + stats[i].statsForCB2.overall + stats[i].statsForLB.overall + stats[i].statsForCM1.overall + stats[i].statsForCM2.overall + stats[i].statsForCAM.overall + stats[i].statsForRW.overall + stats[i].statsForST.overall + stats[i].statsForRW.overall) /11);
	}
}

void leaderBoard()
{

	for (int i = 0; i < teamCounter - 1; i++)
	{
		stats[i].goalDiff = stats[i].scoredGoals - stats[i].concededGoals;
	}

	vector<int> sortedTeams;
	for (int i = 0; i < teamCounter -1; i++) {
		sortedTeams.push_back(i);
	}
	sort(sortedTeams.begin(), sortedTeams.end(), [](int i, int j) {
		if (stats[i].points != stats[j].points) {
			return stats[i].points > stats[j].points;
		}
		else {
			return stats[i].goalDiff > stats[j].goalDiff;
		}
		});

	system("CLS");
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|" << std::setw(6) << "POS" << "|" << std::setw(16) << "Club Name" << "|" << setw(4) << "Wins" << "|" << setw(5) << "Draws" << "|" << setw(5) << "Loses" << "|" << setw(6) << "GoalsS" "|" << setw(6) << "GoalsC" << "|" << setw(6) << "GoalsD" << "|" << setw(6) << "Points" << "|" << endl;
	unsigned short countTeams = 1;
	for (int i = 0; i < teamCounter-1; i++) {
		int index = sortedTeams[i];
		cout << "|" << setw(4) << countTeams++ << ". |" << setw(16) << stats[index].clubName << "|" << setw(4) << stats[index].wins << "|" << setw(5) << stats[index].draws << "|" << setw(5) << stats[index].loses << "|" << setw(6) << stats[index].scoredGoals << "|" << setw(6) << stats[index].concededGoals << "|" << setw(6) << stats[index].goalDiff << "|" << setw(6) << stats[index].points << "|" << endl;
	}
	cout << "----------------------------------------------------------------------" << std::endl;
	system("Pause");
	system("CLS");
}

struct matchStats
{
	unsigned short goalScored = 0, possesions = 0, shots = 0, tackles = 0, touches = 0, passesCompleted = 0, passedMissed = 0, injury=0, yellowCard= 0, redCard = 0;
};

void simulateMatches()
{
	matchStats msH, msA;
	summingOVRByPossition();
	system("CLS");
	for (int i = 0; i <= 90; i++)
	{
		cout << "Minute: " << i << setw(15) << stats[spartakSofia].clubName << ": " << msH.goalScored << setw(15) << stats[shumen].clubName << ": " << msA.goalScored << endl;
		cout << "Home" << setw(50) << "Away" << endl;
		cout << msH.shots << setw(25) << "Shots" << setw(25) << msA.shots << endl;
		cout << msH.passesCompleted << setw(25) << "passes completed" << setw(25) << msA.passesCompleted << endl;
		cout << msH.tackles << setw(25) << "Tackles" << setw(25) << msA.tackles << endl;
		cout << msH.yellowCard << setw(25) << "Yellow card" << setw(25) << msA.yellowCard << endl;
		cout << msH.redCard << setw(25) << "Red card" << setw(25) << msA.redCard << endl;
		cout << msH.injury << setw(25) << "injury" << setw(25) << msA.injury << endl;
		cout << msH.passedMissed << setw(25) << "Missed pass" << setw(25) << msA.passedMissed << endl;

		if (i == 45)
		{
			cout << "first time over!";
			system("PAUSE");
		}
		else
		{
			randomTeamToAttack(msH, msA);
			chrono::milliseconds duration(1000);
			this_thread::sleep_for(duration);
			system("CLS");
		}

	}
	system("CLS");
	cout << "Match over!!" << endl;
	cout << stats[spartakSofia].clubName << ": " << msH.goalScored << setw(15) << stats[shumen].clubName << ": " << msA.goalScored << endl;
	cout << "Home" << setw(50) << "Away" << endl;
	cout << msH.shots << setw(25) << "Shots" << setw(25) << msA.shots << endl;
	cout << msH.passesCompleted << setw(25) << "passes completed" << setw(25) << msA.passesCompleted << endl;
	cout << msH.tackles << setw(25) << "Tackles" << setw(25) << msA.tackles << endl;
	cout << msH.yellowCard << setw(25) << "Yellow card" << setw(25) << msA.yellowCard << endl;
	cout << msH.redCard << setw(25) << "Red card" << setw(25) << msA.redCard << endl;
	cout << msH.injury << setw(25) << "injury" << setw(25) << msA.injury << endl;
	cout << msH.passedMissed << setw(25) << "Missed pass" << setw(25) << msA.passedMissed << endl;
	if (msH.goalScored > msA.goalScored)
	{
		stats[spartakSofia].points += 3;
	}
	else if (msH.goalScored == msA.goalScored)
	{
		stats[spartakSofia].points += 1;
		stats[shumen].points += 1;
	}
	else
	{
		stats[shumen].points += 3;
	}
	system("PAUSE");
	system("CLS");
}

void summingOVRByPossition()
{
	for (int i = 0; i < teamCounter - 1; i++)
	{
		stats[i].deffencePercent = ((stats[i].statsForGK.overall + stats[i].statsForRB.overall + stats[i].statsForCB1.overall + stats[i].statsForCB2.overall + stats[i].statsForLB.overall) / 5)/100;
		stats[i].midPercent = ((stats[i].statsForCM1.overall + stats[i].statsForCM2.overall + stats[i].statsForCM2.overall + stats[i].statsForCAM.overall) / 3)/100;
		stats[i].fowardPercent = ((stats[i].statsForRW.overall + stats[i].statsForST.overall + stats[i].statsForLW.overall) / 3)/100;
	}
}


void randomTeamToAttack(struct matchStats& msH, struct matchStats& msA)
{
	unsigned short teamPicker = 0;
	teamPicker = rand() % 2 + 1;

	switch (teamPicker)
	{
		//home team
	case 1:
		teamHome(msH, msA);
		break;
		//away team
	case 2:
		teamAway(msA, msH);
		break;
	}
}

void teamHome(struct matchStats& msH, struct matchStats& msA)
{
	unsigned short randomNumForEvent = 0, checkToContinue =0, randomTimesPassed =0;
	double randomPickNumber = 0;
	randomTimesPassed = rand() % 80 + 1;
	randomNumForEvent = rand() % 3 + 1;
	randomPickNumber = ((double)rand() / (RAND_MAX));

	switch (randomNumForEvent)
	{
	case 1:
		if (randomPickNumber > stats[shumen].deffencePercent) {
			scoringHome(msH, msA);
		}
		else {
		}
		break;
		//possesion
	case 2:
		if (randomPickNumber > stats[shumen].midPercent) {
			for (int i = 0; i <= randomTimesPassed; i++) {
				checkToContinue = possesionHome(msH, msA);
			}
		}
		else {
			
		}
		break;
		//chance created
	case 3:
		if (randomPickNumber > stats[shumen].deffencePercent) {
			chanceCreatedHome(msH);
		}
		else {

		}
		break;
		//Events yellow/red/injury
	case 4:
		eventsCreatedHome(msH);
		break;

	}
}

void teamAway(struct matchStats& msA, struct matchStats& msH)
{
	unsigned short checkToContinue = 0, randomNumForEvent = 0, randomTimesPassed = 0;
	double randomPickNumber = 0;
	randomTimesPassed = rand() % 23 + 1;
	randomNumForEvent = rand() % 3 + 1;
	randomPickNumber = ((double)rand() / (RAND_MAX));
	
	switch (randomNumForEvent)
	{
		//scoring
	case 1:
		if (randomPickNumber > stats[spartakSofia].deffencePercent) {
			scoringAway(msA, msH);
		}
		else {
		}
		break;
		//possesion
	case 2:
			if (randomPickNumber > stats[spartakSofia].midPercent) {
				for (int i = 0; i <= randomTimesPassed; i++) {
				 checkToContinue = possesionAway(msA, msH);
				}
			}
		else {
		}
		break;
		//chance created
	case 3:
		if (randomPickNumber > stats[spartakSofia].deffencePercent) {
			chanceCreatedAway(msA);
		}
		else {
		}
		break;
		//Events yellow/red/injury
	case 4:
		eventsCreatedAway(msA);
		break;

	}
}

void scoringHome(struct matchStats& msH, struct matchStats& msA)
{
	unsigned short randomPickPlayer = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickPlayer = rand() % 3 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		//LW
		if (stats[spartakSofia].statsForLW.dribbling + 15 < randomPercent1 && stats[shumen].statsForCB1.standTackle < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[spartakSofia].statsForLW.finishing + 15 > randomPercent1 && stats[shumen].statsForGK.gkReflex < randomPercent2)
			{

				stats[spartakSofia].scoredGoals++;
				stats[shumen].concededGoals++;
				msH.goalScored+=1;
				
			}
			else {

				msH.shots += 1;
			}
		}
		else {

				msA.tackles += 1;
		}
		break;
	case 2:
		//ST
		if (stats[spartakSofia].statsForST.dribbling + 15 > randomPercent1  && stats[shumen].statsForCB1.standTackle < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[spartakSofia].statsForST.finishing + 15 > randomPercent1 && stats[shumen].statsForGK.gkReflex < randomPercent2)
			{

				msH.goalScored += 1;
				stats[spartakSofia].scoredGoals++;
				stats[shumen].concededGoals++;
			}
			else {

				msH.shots += 1;
			}
		}
		else {

			msA.tackles += 1;
		}
		break;
	case 3:
		//RW
		if (stats[spartakSofia].statsForRW.dribbling + 15 < randomPercent1 && stats[shumen].statsForCB1.standTackle < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[spartakSofia].statsForRW.finishing + 15 < randomPercent1 && stats[shumen].statsForGK.gkReflex < randomPercent2)
			{

				msH.goalScored += 1;
				stats[spartakSofia].scoredGoals++;
				stats[shumen].concededGoals++;
			}
			else {

				msH.shots += 1;
			}
		}
		else {

			msA.tackles += 1;
		}
		break;
	}
}

unsigned short possesionHome(struct matchStats& msH, struct matchStats& msA)
{
	unsigned short randomNumForEvent = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	double randomPickNumber = 0;

	randomNumForEvent = rand() % 3 + 1;
	randomPickNumber = ((double)rand() / (RAND_MAX));
	
	switch (randomNumForEvent)
	{
		//RCM1
	case 1:
		if (stats[spartakSofia].statsForCM1.shortPass + 15 >= randomPercent1)
		{
			msH.passesCompleted +=1;
			return 0;
		}
		else if (stats[shumen].statsForCM1.standTackle + 15 < randomPercent2)
		{

			
			msA.tackles += 1;
			msH.passedMissed += 1;
			return -1;
		}
		else
		{
			msH.passedMissed += 1;
			return -1;
		}
		break;

		//CAM
	case 2:
		if (stats[spartakSofia].statsForCAM.longPass + 15 >= randomPercent1)
		{
			msH.passesCompleted += 1;
			return 0;
		}
		else if (stats[shumen].statsForCAM.slideTackle + 10 < randomPercent2)
		{
			msA.tackles += 1;
			msH.passedMissed += 1;
			return -1;
		}
		else
		{
			msH.passedMissed += 1;
			return -1;
		}
		break;

		//RCM2
	case 3:
		if (stats[spartakSofia].statsForCM2.shortPass + 15 >= randomPercent1)
		{
			msH.passesCompleted += 1;
			return 0;
		}
		else if (stats[shumen].statsForCM2.standTackle + 10 < randomPercent2)
		{
			msA.tackles += 1;
			msH.passedMissed += 1;
			return -1;
		}
		else
		{
			msH.passedMissed += 1;
			return -1;
		}
		break;
	}
}

void chanceCreatedHome(struct matchStats& msH)
{
	unsigned short randomPickPlayer = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickPlayer = rand() % 3 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;

	switch (randomPickPlayer)
	{
	case 1: 
				msH.shots += 1;
		break;
	case 2:
		msH.shots += 1;
		break;
	case 3:
			msH.shots += 1;
		break;
	}
}

void eventsCreatedHome(struct matchStats& msH)
{
	unsigned short randomPickEvent = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickEvent = rand() % 3 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	switch (randomPickEvent)
	{
		//injury
	case 1:
		injuryHome(randomPickEvent, msH);
		break;

		//redcard
	case 2:
		redCardHome(randomPickEvent, msH);
		break;

		//yellowcard
	case 3:
		yellowcardHome(randomPickEvent, msH);
		break;
	}
}

void injuryHome(unsigned short randomPickEvent, struct matchStats& msH)
{
	unsigned short randomPickPlayer = 0, randomChance = 0;
	randomPickPlayer = rand() % 11 + 1;
	randomChance = rand() % 100 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		if (randomChance <= 5) {
			cout << "Goalkeeper have injury!";
		}
		break;
	case 2:
		if (randomChance <= 5) {
			cout << "Rightback have injury!";
		}
		break;
	case 3:
		if (randomChance <= 5) {
			cout << "Centraback have injury!";
		}
		break;
	case 4:
		if (randomChance <= 5) {
			cout << "Centraback have injury!";
		}
		break;
	case 5:
		if (randomChance <= 5) {
			cout << "Leftback have injury!";
		}
		break;
	case 6:
		if (randomChance <= 5) {
			cout << "Right central middfilder have injury!";
		}
		break;
	case 7:
		if (randomChance <= 5) {
			cout << "Central atack middfilder have injury!";
		}
		break;
	case 8:
		if (randomChance <= 5) {
			cout << "Left central middfilder have injury!";
		}
		break;
	case 9:
		if (randomChance <= 5) {
			cout << "Left winger back have injury!";
		}
		break;
	case 10:
		if (randomChance <= 5) {
			cout << "Striker have injury!";
		}
		break;
	case 11:
		if (randomChance <= 5) {
			cout << "Right winger have injury!";
		}
		break;
	}
	msH.injury++;
}

void redCardHome(unsigned short randomPickEvent, struct matchStats& msH)
{
	unsigned short randomPickPlayer = 0, randomChance;
	randomPickPlayer = rand() % 11 + 1;
	randomChance = rand() % 100 + 1;
	switch (randomPickEvent)
	{
	case 1:
		if (randomChance <= 5) {
			cout << "Goalkeeper have red card!";
		}
		break;
	case 2:
		if (randomChance <= 5) {
			cout << "Rightback have red card!";
		}
		break;
	case 3:
		if (randomChance <= 5) {
			cout << "Centraback have red card!";
		}
		break;
	case 4:
		if (randomChance <= 5) {
			cout << "Centraback have red card!";
		}
		break;
	case 5:
		if (randomChance <= 5) {
			cout << "Leftback have red card!";
		}
		break;
	case 6:
		if (randomChance <= 5) {
			cout << "Right central middfilder have red card!";
		}
		break;
	case 7:
		if (randomChance <= 5) {
			cout << "Central atack middfilder have red card!";
		}
		break;
	case 8:
		if (randomChance <= 5) {
			cout << "Left central middfilder have red card!";
		}
		break;
	case 9:
		if (randomChance <= 5) {
			cout << "Left winger back have red card!";
		}
		break;
	case 10:
		if (randomChance <= 5) {
			cout << "Striker have red card!";
		}
		break;
	case 11:
		if (randomChance <= 5) {
			cout << "Right winger have red card!";
		}
		break;
	}
	msH.redCard++;
}

void yellowcardHome(unsigned short randomPickEvent, struct matchStats& msH)
{
	unsigned short randomPickPlayer = 0, randomChance = 0;
	randomChance = rand() % 100 + 1;
	randomPickPlayer = rand() % 11 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		if (randomChance <= 10) {
			cout << "Goalkeeper have yellow card!";
		}
		break;
	case 2:
		if (randomChance <= 10) {
			cout << "Rightback have yellow card!";
		}
		break;
	case 3:
		if (randomChance <= 10) {
			cout << "Centraback have yellow card!";
		}
		break;
	case 4:
		if (randomChance <= 10) {
			cout << "Centraback have yellow card!";
		}
		break;
	case 5:
		if (randomChance <= 10) {
			cout << "Leftback have yellow card!";
		}
		break;
	case 6:
		if (randomChance <= 10) {
			cout << "Right central middfilder have yellow card!";
		}
		break;
	case 7:
		if (randomChance <= 10) {
			cout << "Central atack middfilder have yellow card!";
		}
		break;
	case 8:
		if (randomChance <= 10) {
			cout << "Left central middfilder have yellow card!";
		}
		break;
	case 9:
		if (randomChance <= 10) {
			cout << "Left winger back have yellow card!";
		}
		break;
	case 10:
		if (randomChance <= 10) {
			cout << "Striker have yellow card!";
		}
		break;
	case 11:
		if (randomChance <= 10) {
			cout << "Right winger have yellow card!";
		}
		break;
	}
	msH.yellowCard++;
}

void scoringAway(struct matchStats& msA, struct matchStats& msH)
{
	unsigned short randomPickPlayer = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickPlayer = rand() % 3 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		//LW
		if (stats[shumen].statsForLW.dribbling + 10 < randomPercent1 && stats[spartakSofia].statsForCB1.standTackle + 15 < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[shumen].statsForLW.finishing + 10 > randomPercent1 && stats[spartakSofia].statsForGK.gkReflex + 15 < randomPercent2)
			{
				
				stats[shumen].scoredGoals++;
				stats[spartakSofia].concededGoals++;
				msA.goalScored += 1;
			}
			else {

				msA.shots += 1;
			}
		}
		else {

			msH.tackles += 1;
		}
		break;
	case 2:
		//ST
		if (stats[shumen].statsForST.dribbling + 10 > randomPercent1 && stats[spartakSofia].statsForCB1.standTackle + 15 < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[shumen].statsForST.finishing + 10 > randomPercent1 && stats[spartakSofia].statsForGK.gkReflex + 15 < randomPercent2)
			{

				stats[shumen].scoredGoals++;
				stats[spartakSofia].concededGoals++;
				msA.goalScored += 1;
			}
			else {

				msA.shots += 1;
			}
		}
		else {

			msH.tackles += 1;
		}
		break;
	case 3:
		//RW
		if (stats[shumen].statsForRW.dribbling + 10 < randomPercent1 && stats[spartakSofia].statsForCB1.standTackle + 15 < randomPercent2)
		{
			randomPercent1 = rand() % 100 + 1;
			randomPercent2 = rand() % 100 + 1;

			if (stats[shumen].statsForRW.finishing + 10 < randomPercent1 && stats[spartakSofia].statsForGK.gkReflex + 15 < randomPercent2)
			{

				msA.goalScored += 1;
				stats[shumen].scoredGoals++;
				stats[spartakSofia].concededGoals++;
			}
			else {

				msA.shots += 1;
			}
		}
		else {

			msH.tackles += 1;
		}
		break;
	}
}

unsigned short possesionAway(struct matchStats& msA,struct matchStats& msH)
{
	unsigned short randomNumForEvent = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	double randomPickNumber = 0;
	randomNumForEvent = rand() % 3 + 1;
	randomPickNumber = ((double)rand() / (RAND_MAX));

	switch (randomNumForEvent)
	{
		//RCM1
	case 1:
		if (stats[shumen].statsForCM1.shortPass + 10 >= randomPercent1)
		{
			msA.passesCompleted += 1;
			return 0;
		}
		else if (stats[spartakSofia].statsForCM1.standTackle + 15 < randomPercent2)
		{
			msH.tackles += 1;
			msA.passedMissed += 1;
			return -1;
		}
		else
		{
			 msA.passedMissed += 1;
			 return -1;
		}
		break;

		//CAM
	case 2:
		if (stats[shumen].statsForCAM.longPass + 10 >= randomPercent1)
		{
			msA.passesCompleted += 1;
			return 0;
		}
		else if (stats[spartakSofia].statsForCAM.standTackle + 15 < randomPercent2)
		{
			msH.tackles += 1;
			msA.passedMissed += 1;
			return -1;
		}
		else
		{
			msA.passedMissed += 1;
			return -1;
		}
		break;

		//RCM2
	case 3:
		if (stats[shumen].statsForCM2.shortPass +10 >= randomPercent1)
		{
			msA.passesCompleted += 1;
			return 0;
		}
		else if (stats[spartakSofia].statsForCM2.standTackle + 15 < randomPercent2)
		{
			msH.tackles += 1;
			msA.passedMissed += 1;
			return -1;
		}
		else
		{
			msA.passedMissed += 1;
			return -1;
		}
		break;
	}
}

void chanceCreatedAway(struct matchStats& msA)
{
	unsigned short randomPickPlayer = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickPlayer = rand() % 3 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	switch (randomPickPlayer)
	{
	case 1:
				msA.shots += 1;
		break;
	case 2:
		msA.shots += 1;
		break;
	case 3:
			msA.shots += 1;
		break;
	}
}

void eventsCreatedAway(struct matchStats& msA)
{
	unsigned short randomPickEvent = 0, randomPercent1 = 0, randomPercent2 = 0;
	randomPickEvent = rand() % 4 + 1;
	randomPercent1 = rand() % 100 + 1;
	randomPercent2 = rand() % 100 + 1;
	switch (randomPickEvent)
	{
		//injury
	case 1:
		injuryAway(randomPickEvent, msA);
		break;

		//redcard
	case 2:
		redCardAway(randomPickEvent,msA);
		break;

		//yellowcard
	case 3:
		yellowcardAway(randomPickEvent, msA);
		break;
	case 4:
		cout << "Nothin happen!";
		break;
	}
}

void injuryAway(unsigned short randomPickEvent, struct matchStats& msA)
{
	unsigned short randomPickPlayer = 0;
	randomPickPlayer = rand() % 11 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		cout << "Goalkeeper have injury!";
		break;
	case 2:
		cout << "Rightback have injury!";
		break;
	case 3:
		cout << "Centraback have injury!";
		break;
	case 4:
		cout << "Centraback have injury!";
		break;
	case 5:
		cout << "Leftback have injury!";
		break;
	case 6:
		cout << "Right central middfilder have injury!";
		break;
	case 7:
		cout << "Central atack middfilder have injury!";
		break;
	case 8:
		cout << "Left central middfilder have injury!";
		break;
	case 9:
		cout << "Left winger back have injury!";
		break;
	case 10:
		cout << "Striker have injury!";
		break;
	case 11:
		cout << "Right winger have injury !";
		break;
	}
	msA.injury++;
}

void redCardAway(unsigned short randomPickEvent, struct matchStats& msA)
{
	unsigned short randomPickPlayer = 0, randomChance;
	randomPickPlayer = rand() % 11 + 1;
	randomChance = rand() % 100 + 1;
	switch (randomPickEvent)
	{
	case 1:
		if (randomChance <= 5) {
			cout << "Goalkeeper have red card!";
		}
		break;
	case 2:
		if (randomChance <= 5) {
			cout << "Rightback have red card!";
		}
		break;
	case 3:
		if (randomChance <= 5) {
			cout << "Centraback have red card!";
		}
		break;
	case 4:
		if (randomChance <= 5) {
			cout << "Centraback have red card!";
		}
		break;
	case 5:
		if (randomChance <= 5) {
			cout << "Leftback have red card!";
		}
		break;
	case 6:
		if (randomChance <= 5) {
			cout << "Right central middfilder have red card!";
		}
		break;
	case 7:
		if (randomChance <= 5) {
			cout << "Central atack middfilder have red card!";
		}
		break;
	case 8:
		if (randomChance <= 5) {
			cout << "Left central middfilder have red card!";
		}
		break;
	case 9:
		if (randomChance <= 5) {
			cout << "Left winger back have red card!";
		}
		break;
	case 10:
		if (randomChance <= 5) {
			cout << "Striker have red card!";
		}
		break;
	case 11:
		if (randomChance <= 5) {
			cout << "Right winger have red card!";
		}
		break;
	}
	msA.redCard++;
}

void yellowcardAway(unsigned short randomPickEvent, struct matchStats& msA)
{
	unsigned short randomPickPlayer = 0, randomChance = 0;
	randomChance = rand() % 100 + 1;
	randomPickPlayer = rand() % 11 + 1;
	switch (randomPickPlayer)
	{
	case 1:
		if (randomChance <= 10) {
			cout << "Goalkeeper have yellow card!";
		}
		break;
	case 2:
		if (randomChance <= 10) {
			cout << "Rightback have yellow card!";
		}
		break;
	case 3:
		if (randomChance <= 10) {
			cout << "Centraback have yellow card!";
		}
		break;
	case 4:
		if (randomChance <= 10) {
			cout << "Centraback have yellow card!";
		}
		break;
	case 5:
		if (randomChance <= 10) {
			cout << "Leftback have yellow card!";
		}
		break;
	case 6:
		if (randomChance <= 10) {
			cout << "Right central middfilder have yellow card!";
		}
		break;
	case 7:
		if (randomChance <= 10) {
			cout << "Central atack middfilder have yellow card!";
		}
		break;
	case 8:
		if (randomChance <= 10) {
			cout << "Left central middfilder have yellow card!";
		}
		break;
	case 9:
		if (randomChance <= 10) {
			cout << "Left winger back have yellow card!";
		}
		break;
	case 10:
		if (randomChance <= 10) {
			cout << "Striker have yellow card!";
		}
		break;
	case 11:
		if (randomChance <= 10) {
			cout << "Right winger have yellow card!";
		}
		break;
	}
	msA.yellowCard++;
}
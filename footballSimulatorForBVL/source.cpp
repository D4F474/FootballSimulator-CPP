#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "CTeam.h"
#include "CPosition.h"
#include "CPlayer.h"
#include "CStartMatch.h"

const unsigned short MAIN_MENU_OPTIONS = 2;


void readFile(std::vector<CTeam*>& teams);
void printTeam(const std::vector<CTeam*>& teams);
void startMatch(std::vector<CTeam*>& teams);
unsigned short menu();
int main()
{
	//read from file

	std::vector<CTeam*> teams;
	unsigned short menuItem;
	readFile(teams);
	//CTeam* team = new CTeam("Spartak Sofia", 32, 23, 4, 5, 7);
	//CPosition* Position =new CPosition("GK", 19, 32, 43, 54, 12, 76, 23, 12, 43, 65, 12, 43, 21, 34, 21, 43, 65, 34, 12, 96, 65, 76);
	//CPlayer* player = new CPlayer("dafin","dafinov", "ST", 29, *Position);
	do
	{
		menuItem = menu();
		switch (menuItem)
		{
		case 1:
			system("CLS");
			printTeam(teams);
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			startMatch(teams);
			system("PAUSE");
			break;
		default:
			std::cout << "Stop program";
		}
	} while (menuItem != MAIN_MENU_OPTIONS);
	return 0;
}
unsigned short menu()
{
	unsigned short choise;
	std::cout << "*******" << std::endl;
	std::cout << "*** Menu ***" << std::endl;
	do {
		std::cout << "1.Print teams!" << std::endl;
		std::cout << "2.Start Match" << std::endl;
		std::cout << "Choise option" << std::endl;
		std::cin >> choise;
	} while (choise < 1 || choise > MAIN_MENU_OPTIONS);
	return choise;
}
 // не го четеее
void readFile(std::vector<CTeam*>& teams)
{
	std::ifstream file;
	file.open("footballTeams.txt");
	if (file.fail())
	{
		std::cout << "cant find this file!";
	}
	else
	{
		while (true)
		{
		std::string line = " ";
		std::getline(file, line);
		if (line == "*")
		{
			continue;
		}
			std::string TeamName = " ", firstName = " ", lastName = " ", position = " ", pos = " ";
			unsigned short points = 0,  goals = 0,  wins = 0,  loses = 0,  draws = 0,  age = 0;
			float acceleration = 0, stamina = 0, strength = 0, sprintSpeed = 0, vision = 0, slideTackle = 0, standTackle = 0, ballControll = 0, dribbling = 0, crossing = 0, shortPass = 0,
			 longPass = 0, heading = 0, shotPower = 0, longShot = 0, penalties = 0, finishing = 0, GKpositioning = 0, GKDiving = 0, GKHandling = 0, GKkicking = 0, GKReflex = 0;
			//Readfiles
			TeamName = line;
			std::getline(file, line);
			std::stringstream ss(line);
			ss >> points;
			ss >> goals;
			ss >> wins;
			ss >> loses;
			ss >> draws;
			//CTeam: std::string nameOfTeam, unsigned short points, unsigned short goals, unsigned short wins, unsigned short loses, unsigned short draws
			//std::cout << TeamName << " " << points << " " << goals << " " << loses << " " << draws << std::endl;
			std::getline(file, line);
			
			if (line == "-")
			{
				break;
			}
			else if (line == "&")
			{
			CTeam* team = new CTeam(TeamName, points, goals, wins, loses, draws);
				for (int i = 0; i < 11; i++)
				{
					std::getline(file, line);
					std::stringstream ss(line);
					//player
					ss >> firstName;
					ss >> lastName;
					ss >> age;
					ss >> position;
					//possiton ovr
					ss >> acceleration; ss >> stamina; ss >> strength; ss >> sprintSpeed; ss >> vision; ss >> slideTackle; ss >> standTackle; ss >> ballControll; ss >> dribbling;
					ss >> crossing; ss >> shortPass; ss >> longPass; ss >> heading; ss >> shotPower; ss >> longShot; ss >> penalties; ss >> finishing; ss >> GKpositioning;
					ss >> GKDiving; ss >> GKHandling; ss >> GKkicking; ss >> GKReflex;
					//std::string* pos, float* acceleration, float* stamina, float* strength, float* sprintSpeed, float* vision, float* slideTackle, float* standTackle, float* ballControll,float* dribbling, float* crossing, float* shortPass, float* longPass,float* heading, float* shotPower, float* longShot, float* penalties,float* finishing, float* GKPosstioning, float* GKDiving, float* GKHandling, float* GKKicking, float* Reflexes
					CPosition* stats = new CPosition(&position, &acceleration, &stamina, &strength, &sprintSpeed, &vision, &slideTackle, &standTackle, &ballControll, &dribbling, &crossing, &shortPass,
						&longPass, &heading, &shotPower, &longShot, &penalties, &finishing, &GKpositioning, &GKDiving, &GKHandling, &GKkicking, &GKReflex);
					//CPlayer: std::string firstName, std::string lastName, std::string possition, unsigned short age, CPosition& positionStats
					CPlayer* player = new CPlayer(&firstName, &lastName, &position, &age, *&stats);
					team->addPlayer(*player);
				}
				teams.push_back(team);
			}
		}
	}
}

void printTeam(const std::vector<CTeam*>& teams)
{
	for (int i = 0; i < teams.size(); i++)
	{
		std::cout << *teams[i] << std::endl;
		//teams[i]->printPlayers();
	}
}

void startMatch(std::vector<CTeam*>& teams)
{
	CStartMatch* startMatch = new CStartMatch(*teams[0], *teams[1]);
}
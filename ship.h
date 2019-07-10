#pragma once
#include <string>
#include <vector>
#include "node.h"

using namespace std;

class ship{
	public:

	ship(int n, string na);

	void genNode(int a[4], bool l, string n);
	
	void damagenode(int nod, int amnt);
	void damagenodes(int dam, vector<int> nnodes);
	void repairNode(int nod, int amnt);

	void inputFightResults(int i);

	//var getters
	int getThrustspeed(){return thrustspeed; }
	int getweapons(){return weaponspower; }
	int getTotalweight(){return totalweight;}
	
	int getFightsWon(){return fightswon; }
	int getFightsLost(){return fightslost; }
	int getWinStreak(){return wstreak; }
	int getLossStreak(){return lstreak; }
	
	bool isAlive(){return alive; }
	bool isBreach(){return breached; }
	int getOxygen(){return oxegen;}
	int getTeam(){return team;}
	string getName(){return name;}
	
	int numLivingForms(){return life;}
	
	double getEfficency();
	
	void moveLifeForms(int from, int to, amnt);
	
	void update();
	
	private:

	string name;
	int fightswon;
	int fightslost;
	int wstreak;
	int lstreak;
	int currentstreak;
	int lastfight;
	
	int totalweight;
	int weaponspower;
	int thrustspeed;

	bool breached;
	int oxegen;
	bool gravity;
	int life;
	bool alive;
	int sectionsnum;
	vector<node> sections;

	int team;

};

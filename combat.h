#pragma once
#include <string>
#include <vector>
#include <queue>

//#include "maptile.h"
#include "ship.h"
#include "fight.h"



using namespace std;


class arena {
public:

	arena(int snumber, int fnumber);
	arena(int snumber, int fnumber, vector<ship*>& f);
	~arena();

	void genShips(int i);

	void clearAreana();
	void createFight(vector<int> f);
	void removeFights(vector<int> f);

	void printQue();
	void swapFights();

	ship runsim();

	ship mostWins();
	ship mostLosses();

private:
	

	//queue<fight> fightque;
	bool running;
	bool finished;

	int shipnumber;
	int numOfFights;

	//arenatile*** map;

	
};



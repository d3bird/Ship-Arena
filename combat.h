#pragma once
#include <string>
#include <vector>


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
	ship* createShip();

	void clearAreana();
	void createFight(vector<int> f);
	void removeFights(vector<int> f);

	//void printQue();
	void swapFights();

	ship runsim();

	ship mostWins();
	ship mostLosses();


	//debug output getter functions
	void printMap();

	bool isRunning() { return running; }
	bool isFinished() { return finished; }
	
	int getShipnumber() { return shipnumber; }
	int getNumberOfFights() { return numOfFights; }
	vector<fight> getFightlist() { return fightque;  }
	ship* getWinner() { return winner; }
private:
	
	int levels;
	int ywidth;
	int xwidth;

	vector<fight> fightque;
	bool running;
	bool finished;

	int shipnumber;
	int numOfFights;

	arenatile*** map;

	ship * winner;
	
};



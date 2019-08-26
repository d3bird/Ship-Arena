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
	arena(int snumber, int fnumber, vector<int>& size, vector<ship*>& f);
	~arena();

	ship* createShip(std::string name);
	ship* createShip(std::string name, int dim[3]);

	void clearAreanaMap();
	void clearAreanaFights();
	void createFight(vector<int>& size, vector<ship*>& ships);
	void removeFight(int i);

	//void printQue();
	void swapFights(int f, int s);

	ship* runsim();

	ship* mostWins();
	ship* mostLosses();

	//debug output getter functions
	void printMap();

	bool isRunning() { return running; }
	bool isFinished() { return finished; }

	int getShipnumber() { return shipnumber; }
	int getNumberOfFights() { return numOfFights; }
	vector<fight*> getFightlist() { return fightque; }
	ship* getWinner() { return winner; }

private:

	int levels;
	int ywidth;
	int xwidth;

	vector<fight*> fightque;
	vector<ship*> shipsInFights;
	bool running;
	bool finished;

	int shipnumber;
	int numOfFights;

	arenatile*** map;

	ship* winner;

};



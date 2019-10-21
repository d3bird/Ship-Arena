//******************************************************************
//                                                                  
//  Class: arena
//                                                                  
//  Purpose:  ...
//            
//  Functions:
//           Constructors
//				...
//           setters
//				...
//           getters
//				...
//  
//******************************************************************

#pragma once
#include <string>
#include <vector>


//#include "maptile.h"
#include "ship.h"
#include "fight.h"
#include "arenatile.h"

using namespace std;


class arena {
public:

	arena(int snumber, int fnumber, int dim[3]);
	arena(int snumber, int fnumber, int dim[3], vector<int>& size, vector<ship*>& f);
	~arena();

	ship* createShip(std::string name);
	ship* createShip(std::string name, int dim[3]);
	void createMap();
	void clearAreanaMap();
	void clearAreanaFights();
	void createFight(vector<int>& size, vector<ship*>& ships);
	void removeFight(int i);

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

	void setup(vector<int>& size);

	int levels;
	int xwidth;
	int ywidth;

	vector<fight*> fightque;
	vector<ship*> shipsInFights;
	bool running;
	bool finished;

	int shipnumber;
	int numOfFights;

	arenatile*** map;

	ship* winner;

};



#pragma once
#include <string>
#include <vector>
#include <queue>

#include "ship.h"

using namespace std;



class fight{
	public:
	
	fight(bool ovo, vector<ship> f);

	bool FIGHT();

	void removeship(int i);
	void addShip(ship i);
	
	ship getvictor();
	private:

	
	vector<ship> fighters;
	bool compleate;
	bool oneVone;
	ship victor;
	
};

class areana{
	public:

	void genShips(int i);
	void clearAreana();
	void createFight(vector<int> f);
	void removeFights(vector<int> f);
	
	void printQue();
	void swapFights();
	
	ship runsim();

	private:
		
	ship mostWins();
	ship mostLosses();

	queue<fight> fightque;
	bool ruuning;
	vector<ship> fighters;
	

};


#pragma once

#include <string>
#include <vector>

#include "node.h"
#include "Shiptile.h"
#include "maptile.h"

class ship {

public:

	ship(int n, std::string na, int dim[3]);
	ship(int n, std::string na, int dim[3], std::vector<node*>& r);
	~ship();

	void genNode(int a[4], bool l, std::string n);// not currently in use

	void damagenode(int nod, int amnt);
	void damagenodes(int dam, std::vector<int> nnodes);
	void repairNode(int nod, int amnt);

	void inputFightResults(int i);

	void generateArenaMap();
	arenatile*** getArenaMap();

	//var getters
	int getThrustspeed() { return thrustspeed; }
	int getweapons() { return weaponspower; }
	int getTotalweight() { return totalweight; }

	int getFightsWon() { return fightswon; }
	int getFightsLost() { return fightslost; }
	int getWinStreak() { return wstreak; }
	int getLossStreak() { return lstreak; }

	bool isAlive() { return alive; }
	bool isBreach() { return breached; }
	int getOxygen() { return oxegen; }
	int getTeam() { return team; }
	std::string getName() { return name; }

	int getRfuel() { return rfuel; }
	int getRpower() { return rpower; }
	int getRweapons() { return rweapons; }
	int numLivingForms() { return life; }
	double getEfficency();

	int getRoomsProw() { return roomsProw; }
	int getRoomsPcol() { return roomsPcol; }
	int getRoomNumber() { return numrooms; }
	int getBlankRoomNumber() { return blankrooms; }
	void moveLifeForms(int from, int to, int amnt);

	void update();

	//dealing with ship layout generation

	void genMap(int n);
	void genRooms();
	void genRooms(int num);
	void addRoomTomap(int index);
	void printmap();
	void prinArenaMap();

	std::vector<node*>& getRooms() { return sections; }

private:

	void convertToGrid(int rx, int ry);
	void genblankmap();
	void setMapStats();
	int xwidth;
	int ywidth;
	int floors;

	shiptile*** map;

	int xAwidth;
	int yAwidth;
	int Afloors;
	arenatile*** Amap;

	std::string name;
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

	int team;

	//everything to do with rooms
	bool roomsatend;
	int roomsProw;
	int roomsPcol;
	int numrooms;
	int blankrooms;
	std::vector<node*> sections;

	//ratios
	int rfuel;
	int rpower;
	int rweapons;

};

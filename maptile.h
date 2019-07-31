#pragma once

#include <string>

#include "ship.h"

/*
* This class that handles what information is stored in each map tile
* More varribles can be added latter to preform more complex equations 
* when dealing with how much damage each tile recives from events
*/
class maptile {
public:

	std::string getobj() { return obj; }
	void setObj(std::string i) { obj = i; }

	bool operator =(std::string other) { setObj(other); return true; }
	bool operator ==(std::string o){ return getobj() == o ? true : false; }
	
private:
	std::string obj;
};

class shiptile : public maptile {
public:

	bool operator =(std::string other) { setObj(other); return true; }
	bool operator ==(std::string o) { return getobj() == o ? true : false; }

	void setVars(bool b[4], int i[2], double d){
		 breakingthreshold =d;
		 hitpoints =i[0];
		 maxhitpoints=i[1];
		 passible= b[0];
		 interactible= b[1];
		 broken= b[2];
		 inuse= b[3];
	}

	double getBreakingthreshold() { return breakingthreshold; }
	int getHitpoints() { return hitpoints; }
	int getMaxhitpoints() { return maxhitpoints; }
	bool isPassible() { return passible; }
	bool isInteractible() { return interactible; }
	bool isBroken() { return broken; }
	bool isInuse() { return inuse; }

private:

	double breakingthreshold;
	int hitpoints;
	int maxhitpoints;
	bool passible;
	bool interactible;
	bool broken;
	bool inuse;

};

class arenatile : public maptile {
public:

private:

};

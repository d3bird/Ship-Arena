#pragma once
#include <string>


class shiptile {
public:
	std::string getobj() { return obj; }
	void setObj(std::string i) { obj = i; }

	bool operator =(std::string other) { setObj(other); return true; }
	bool operator ==(std::string o) { return getobj() == o ? true : false; }

	void setVars(bool b[4], int i[2], double d) {
		breakingthreshold = d;
		hitpoints = i[0];
		maxhitpoints = i[1];
		passible = b[0];
		interactible = b[1];
		broken = b[2];
		inuse = b[3];
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

	std::string obj;

};
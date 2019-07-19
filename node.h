#pragma once

#include <string>

using namespace std;

class node {

public:

	node(int a[12], bool l, string n);

	int getWeight() { return weight; }
	int getWeapons();//{return weapons;
	int getThrust();//{return engines;

	bool reqLifeforms() { return reqLife; }//does it need life
	int getReqForms() { return reqforms; }// how many life forms are needed
	int getLifeForms() { return lifeforms; }// the number of current lifeforms in node
	void removeLife(int i) { lifeforms -= i; }
	void addLife(int i) { lifeforms += i; }

	bool isonline() { return online; }

	string getName() { return name; }

	bool isbreached() { return breached; }
	int getBreachSize() { return breachsize; }

	bool isUnderstaffed() { return understaffed; }
	bool isDamaged() { return damaged; }
	bool isDestoried() { return destoried; }

	void damage(int i);
	void repair(int i);

	int getfloor() { return f; }
	int getX() { return x; }
	int getY() { return y; }
	int getXsize() { return xsize; }
	int getYsize() { return ysize; }

	int getDx() { return dx; }
	int getDy() { return dy; }
	int getDf() { return df; }

private:
	//location on the ship
	int x;
	int y;
	int f;

	int xsize;
	int ysize;
	// location to the door to the room
	int dx;
	int dy;
	int df;

	bool breached;
	int breachsize;

	int weight;
	int maxWeight;
	int weapons;
	int engines;

	bool reqLife;//does it need life
	int reqforms;// how many life forms are needed
	int lifeforms;// the number of current lifeforms in node
	bool online;
	bool damaged;
	bool destoried;

	bool understaffed;

	string name;

};


#pragma once

#include "Shiptile.h"
#include <string>

using namespace std;

class node {

public:

	node(int a[13], bool l, string n);
	~node();
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


	int* getloc() { return loc; }
	int* getDloc() { return dloc; }
	
	void setloc(int* i) { loc = i; }
	void setDloc(int* i) { dloc = i; }

	void setRoomType(int i);

	bool isBlank() { return blank; }
	bool isEngroom() { return engroom; }
	bool ispowerRoom() { return powerRoom; }
	bool isweaponsRoom() {return weaponsRoom; }
	bool ismiscRoom() { return miscRoom; }
	int getRoomvarient() { return  roomvarient; }

	//should change based on room inheritance

	void designateRoom(int i);
	shiptile** getMap() { return map; }
	int getRatio() { return 1; }// amount that the ratios are increase (changes for room)

	int getXinside() { return xinsideSize; }
	int getYinside() { return yinsideSize; }

	void setSize(int x, int y);
	int* getsize();

private:
	//location on the ship
	int *loc;

	int xinsideSize;
	int yinsideSize;

	int xsize;
	int ysize;

	int* size;
	// location to the door to the room
	int* dloc;

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

	shiptile** map;

	bool blank;
	bool engroom;
	bool powerRoom;
	bool weaponsRoom;
	bool miscRoom;

	int roomvarient;

};


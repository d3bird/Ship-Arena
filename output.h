#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include "node.h"
#include "ship.h"
#include "combat.h"

using namespace std;

class console {
public:

	console(){}



void testprint(string i);
void endprint();

void print(node *test);
void print(vector<node*> &input);
void print(ship & test);
void nline();

int testNode();
int testShip();


};






void console::testprint(string i) {
	cout << "----------------" << i << "----------------" << endl;
}

void console::endprint() {
	cout << "----------------" << "----------------------" << endl;
}


void console::print(node * test) {

	testprint("node print");
	int* temp = test->getloc();
	cout << "name: " << test->getName() << endl;
	cout << "loc at (x,y,f) : " << temp[0]<<","<< temp[1] <<","<< temp[2] << endl;
	temp = test->getDloc();
	cout << "door loc at x,y,f) : " << temp[0] << "," << temp[1] << "," << temp[2] << endl;
	nline();
	cout << "weight: " << test->getWeight() << endl;
	cout << "weapons: " << test->getWeapons() << endl;
	cout << "thrust: " << test->getThrust() << endl;
	cout << "breached: " << test->isbreached() << endl;
	cout << "breached size: " << test->getBreachSize() << endl;
	cout << "reqs life: " << test->reqLifeforms() << endl;
	cout << "forms needed: " << test->getReqForms() << endl;
	cout << "forms present: " << test->getLifeForms() << endl;
	cout << "understaffed: " << test->isonline() << endl;
	cout << "online: " << test->isonline() << endl;

	nline();

	endprint();
	nline();
}

void console::print(ship &test) {

	testprint("ship print");

	test.printmap();

	cout << "name: " << test.getName() << endl;
	cout << "thrust: " << test.getThrustspeed() << endl;
	cout << "weapons: " << test.getweapons() << endl;
	cout << "weight: " << test.getTotalweight() << endl;
	cout << "fights won: " << test.getFightsWon() << endl;
	cout << "fights lost: " << test.getFightsLost() << endl;
	cout << "W streak: " << test.getWinStreak() << endl;
	cout << "L streak: " << test.getLossStreak() << endl;
	cout << "alive: " << test.isAlive() << endl;
	cout << "breached: " << test.isBreach() << endl;
	cout << "oxygen lvls: " << test.getOxygen() << endl;
	cout << "life forms: " << test.numLivingForms() << endl;
	cout << "efficency: " << test.getEfficency() << endl;
	nline();
	cout << "fuel ratio    1:" << test.getRfuel() << endl;
	cout << "weapons ratio 1:" << test.getRweapons() << endl;
	cout << "power ratio   1:" << test.getRpower() << endl;
	nline();
	cout << "rooms per col: " << test.getRoomsPcol() << endl;
	cout << "rooms per row: " << test.getRoomsProw() << endl;
	nline();
	cout << "number of rooms: " << test.getRoomNumber() << endl;
	cout << "number of blank rooms: " << test.getBlankRoomNumber() << endl;

	print(test.getRooms());

	endprint();
	cout << endl;

	endprint();
}


void console::print(vector<node*>& input) {

	for (int i = 0; i < input.size(); i++) {
		print(input[i]);
	}
}

void console::nline() {
	cout <<endl;
}

int console::testNode() {
	string name = "node_test";
	int thrust = 100;
	int weapons = 200;
	int weight = 400;
	int lf = 5;

	return 0;
}

int console::testShip() {
	int thrust = 100;
	int weapons = 200;
	int weight = 400;
	int lf = 5;

	int temp[] = { weight,weapons,thrust,lf };

	int x = 40;
	int y = 40;
	int f = 1;

	int mapsize[] = { x,y,f };

	ship test(0, "test_ship", mapsize);

	print(test);

	
	return 0;
}

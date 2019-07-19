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

template<class T>
void print(T i);

void testprint(string i);
void endprint();

void print(node & test);

void print(ship & test);


int testNode();
int testShip();


};



template<class T>
void console::print(T i) {
	cout << i << endl;
}


void console::testprint(string i) {
	cout << "----------------" << i << "----------------" << endl;
}

void console::endprint() {
	cout << "----------------" << "----------------------" << endl;
}


void console::print(node & test) {

	testprint("node print");

	cout << "name: " << test.getName() << endl;
	cout << "weight: " << test.getWeight() << endl;
	cout << "weapons: " << test.getWeapons() << endl;
	cout << "thrust: " << test.getThrust() << endl;
	cout << "breached: " << test.isbreached() << endl;
	cout << "breached size: " << test.getBreachSize() << endl;
	cout << "reqs life: " << test.reqLifeforms() << endl;
	cout << "forms needed: " << test.getReqForms() << endl;
	cout << "forms present: " << test.getLifeForms() << endl;
	cout << "understaffed: " << test.isonline() << endl;
	cout << "online: " << test.isonline() << endl;

	cout << endl;

	endprint();

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
	cout << "fuel ratio    1:" << test.getRfuel() << endl;
	cout << "weapons ratio 1:" << test.getRweapons() << endl;
	cout << "power ratio   1:" << test.getRpower() << endl;
	cout << "rooms per col: " << test.getRoomsPcol() << endl;
	cout << "life per row: " << test.getRoomsProw() << endl;
	endprint();
	cout << endl;

	endprint();
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
	int f = 2;

	int mapsize[] = { x,y,f };

	ship test(0, "test_ship", mapsize);

	print(test);

	print("done");
	return 0;
}

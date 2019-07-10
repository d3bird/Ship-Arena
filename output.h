#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include "node.h"
#include "ship.h"
#include "combat.h"

using namespace std;

template<class T>
void print(class T) {
	cout << T << endl;
}


void testprint(string i) {
	cout << "----------------" << i << "----------------" << endl;
}

void endprint() {
	cout << "----------------" << "----------------------" << endl;
}


void print(node test) {

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

void print(ship test) {

	testprint("ship print");

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

	endprint();
	cout << endl;

	endprint();
}


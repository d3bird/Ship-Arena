#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include "node.h"
#include "ship.h"
#include "combat.h"
#include "fight.h"

class console {
public:

	console(){}



void testprint(string i);
void endprint();

void print(node *test);
void print(std::vector<node*> &input);
void print(ship & test);
void nline();

void printFight(fight& f);
void printArena(arena& a);

int testNode();
int testShip();


};

void console::testprint(string i) {
	std::cout << "----------------" << i << "----------------" << std::endl;
}

void console::endprint() {
	std::cout << "----------------" << "----------------------" << std::endl;
}

void console::print(node * test) {

	testprint("node print");
	int* temp = test->getloc();
	std::cout << "name: " << test->getName() << std::endl;
	std::cout << "loc at (x,y,f) : " << temp[0]<<","<< temp[1] <<","<< temp[2] << std::endl;
	temp = test->getDloc();
	std::cout << "door loc at x,y,f) : " << temp[0] << "," << temp[1] << "," << temp[2] << std::endl;
	nline();
	std::cout << "weight: " << test->getWeight() << std::endl;
	std::cout << "weapons: " << test->getWeapons() << std::endl;
	std::cout << "thrust: " << test->getThrust() << std::endl;
	std::cout << "breached: " << test->isbreached() << std::endl;
	std::cout << "breached size: " << test->getBreachSize() << std::endl;
	std::cout << "reqs life: " << test->reqLifeforms() << std::endl;
	std::cout << "forms needed: " << test->getReqForms() << std::endl;
	std::cout << "forms present: " << test->getLifeForms() << std::endl;
	std::cout << "understaffed: " << test->isonline() << std::endl;
	std::cout << "online: " << test->isonline() << std::endl;

	nline();

	endprint();
	nline();
}

void console::print(ship &test) {

	testprint("ship print");
	
	test.printmap();
	
	std::cout << "name: " << test.getName() << std::endl;
	std::cout << "thrust: " << test.getThrustspeed() << std::endl;
	std::cout << "weapons: " << test.getweapons() << std::endl;
	std::cout << "weight: " << test.getTotalweight() << std::endl;
	std::cout << "fights won: " << test.getFightsWon() << std::endl;
	std::cout << "fights lost: " << test.getFightsLost() << std::endl;
	std::cout << "W streak: " << test.getWinStreak() << std::endl;
	std::cout << "L streak: " << test.getLossStreak() << std::endl;
	std::cout << "alive: " << test.isAlive() << std::endl;
	std::cout << "breached: " << test.isBreach() << std::endl;
	std::cout << "oxygen lvls: " << test.getOxygen() << std::endl;
	std::cout << "life forms: " << test.numLivingForms() << std::endl;
	std::cout << "efficency: " << test.getEfficency() << std::endl;
	nline();
	std::cout << "fuel ratio    1:" << test.getRfuel() << std::endl;
	std::cout << "weapons ratio 1:" << test.getRweapons() << std::endl;
	std::cout << "power ratio   1:" << test.getRpower() << std::endl;
	nline();
	std::cout << "rooms per col: " << test.getRoomsPcol() << std::endl;
	std::cout << "rooms per row: " << test.getRoomsProw() << std::endl;
	nline();
	std::cout << "number of rooms: " << test.getRoomNumber() << std::endl;
	std::cout << "number of blank rooms: " << test.getBlankRoomNumber() << std::endl;

	print(test.getRooms());

	endprint();
	std::cout << std::endl;

	endprint();
}


void console::print(vector<node*>& input) {

	for (int i = 0; i < input.size(); i++) {
		print(input[i]);
	}
}

void console::nline() {
	std::cout << std::endl;
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

	int roominputs[12];
	roominputs[0] = 10;//weight
	roominputs[1] = 0;//weapons
	roominputs[2] = 0;//engins
	roominputs[3] = 0;
	roominputs[4] = -1;
	roominputs[5] = -1;
	roominputs[6] = -1;
	roominputs[7] = -1;
	roominputs[8] = -1;
	roominputs[9] = -1;
	roominputs[10] = -1;
	roominputs[11] = -1;

	std::vector<node*> sections;

	node * tnode;

	roominputs[0] = 10;//weight
	roominputs[1] = 100;//weapons
	roominputs[2] = 0;//engins

	tnode = new node(roominputs, false, "Cannon Room");
	sections.push_back(tnode);

	roominputs[0] = 10;//weight
	roominputs[1] = 0;//weapons
	roominputs[2] = 100;//engins

	tnode = new node(roominputs, false, "engine");
	sections.push_back(tnode);

	roominputs[0] = 10;//weight
	roominputs[1] = 30;//weapons
	roominputs[2] = 30;//engins

	tnode= new node(roominputs, false, "mix");
	sections.push_back(tnode);


	ship test(0, "test_ship", mapsize, sections);

	print(test);

	return 0;
}

void console::printFight(fight& f) {

	std::cout << "printing fight" << std::endl;
	std::cout << "has the fight happened: " << f.isFinished() << std::endl;
	std::cout << "id the fight happened: " << f.isRunning() << std::endl;

	if (f.getfighters().size() > 0) {
		std::cout << "the current fighters are: ";

		for (int i = 0; i < f.getfighters().size(); i++) {
			std::cout << f.getfighters()[i]->getName() << " ";
		}

		std::cout << std::endl;
	}
	else {
		std::cout << "there are no current ship in this fight" << std::endl;
	}

	if (f.isFinished()) {
		std::cout << "The winner is " << f.getWinner()->getName() << std::endl;
	}
	else {
		std::cout << "there is no winner yet" << std::endl;
	}

}

void console::printArena(arena& a) {
	std::cout << "the curret map for the arean" << endl;
	a.printMap();

	std::cout << "the number of ships here: " << a.getShipnumber() << std::endl;
	std::cout << "the number of fights happening: " << a.getNumberOfFights() << std::endl;
	vector<fight> que = a.getFightlist();

	if (que.size() > 0) {
		std::cout << "the fights that are queued fot this arena" << endl;
		std::cout << "here are the queued up ship fights" << endl;
		for (int i = 0; i < que.size(); i++) {
			printFight(que[i]);
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "there has been no fights added to this areana" << std::endl;
	}

	if (a.isFinished()) {
		std::cout << "all fights have been procced" << std::endl;
		std::cout << "the winner is: " << a.getWinner()->getName()<< std::endl;
	}
	else if (a.isRunning()) {
		std::cout << "the fights are currently in progress" << std::endl;
	}
	else {
		std::cout << "the sim has not started yet" << std::endl;
	}

}


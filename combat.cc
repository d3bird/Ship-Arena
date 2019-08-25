#include "combat.h"
#include <iostream>

arena::arena(int snumber, int fnumber) {
	shipnumber = snumber;
	numOfFights = fnumber;
}

arena::arena(int snumber, int fnumber, vector<ship*>& f) {
	shipnumber = snumber;
	numOfFights = fnumber;
}

arena::~arena() {
	for (int f = 0; f < levels; f++) {
		for (int y = 0; y < ywidth; y++) {
			delete[] map[f][y];
		}
		delete[] map[f];
	}

	delete[] map;

}

void arena::printMap() {
	for (int f = 0; f < levels; f++) {
		std::cout << std::endl;
		std::cout << "----------levels number: " << f << "-------------" << std::endl;
		std::cout << std::endl;
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {

				std::cout << map[f][y][x].getobj();

			}
			std::cout << std::endl;
		}
	}

}

void arena::genShips(int i) {

}

ship* arena::createShip() {

	return NULL;
}

void arena::clearAreana() {

}

void arena::createFight(vector<int> f) {

}

void arena::removeFights(vector<int> f) {

}

//void arena::printQue() {
//
//}

void arena::swapFights() {

}

ship arena::runsim() {

}

ship arena::mostWins() {

}

ship arena::mostLosses() {

}
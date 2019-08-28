#include "combat.h"
#include <iostream>
#include <string>

arena::arena(int snumber, int fnumber, int dim[3]) {
	shipnumber = snumber;
	numOfFights = fnumber;
	levels = dim[0];
	xwidth = dim[1];
	ywidth = dim[2];
	//setup();
}

// not currently implmented
arena::arena(int snumber, int fnumber, int dim[3], vector<int>& size, vector<ship*>& f) {
	shipnumber = snumber;
	numOfFights = fnumber;
	shipsInFights = f;
	levels = dim[0];
	xwidth = dim[1];
	ywidth = dim[2];
	setup(size);
}

arena::~arena() {
	if (map != NULL) {
		for (int f = 0; f < levels; f++) {
			for (int y = 0; y < ywidth; y++) {
				delete[] map[f][y];
			}
			delete[] map[f];
		}

		delete[] map;
	}
	clearAreanaFights();
}

void arena::setup(vector<int>& size) {
	createFight(size, shipsInFights);
	createMap();
}

void arena::printMap() {
	if (map != NULL) {
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
}


ship* arena::createShip(std::string name) {
	int n = 0;
	int dim[3] = { 2,40,40 };
	ship* output = new ship(n, name, dim);
	return output;
}

ship* arena::createShip(std::string name, int dim[3]) {

	if (dim[0] < 0 || dim[1] < 0 || dim[2] < 0) {
		std::cout << "wrong dims for ship construction" << std::endl;
		return NULL;
	}
	else {
		int n = 0;
		ship* output = new ship(n, name, dim);
		return output;
	}
}

void arena::clearAreanaMap() {
	if (map != NULL) {
		for (int f = 0; f < levels; f++) {
			for (int y = 0; y < ywidth; y++) {
				delete[] map[f][y];
			}
			delete[] map[f];
		}

		delete[] map;
	}
}

void arena::clearAreanaFights() {

	if (fightque.size() > 0) {
		for (int i = fightque.size() - 1; i > -1; i--) {
			fightque.pop_back();
		}
	}
}

void arena::createFight (std::vector<int>& size, std::vector<ship*>& ships) {
	fight* f;
	std::vector<ship*> combatants;
	int cursor = 0;
	bool out = false;
	for (int i = 0; i < numOfFights; i++) {

		for (; cursor < size[i]; cursor++) {
			if (cursor >= ships.size()) {
				out = true;
				break;
			}
			else {
				combatants.push_back(ships[cursor]);
			}
		}
		if (out) {
			std::cout << "ran out of ships for the requred number for this fight" << endl;
		}
		else {
			f = new fight(combatants);
			fightque.push_back(f);
			combatants.clear();
		}
	}
}

void arena::removeFight(int i) {
	numOfFights--;
	shipnumber -= fightque[i]->getNumOfFighters();
	fightque.erase(fightque.begin() + i);
}


void arena::createMap() {

	map = new arenatile * *[levels];

	for (int f = 0; f < levels; f++) {

		map[f] = new arenatile * [ywidth]; // generating the rows

		for (int i = 0; i < ywidth; i++) {// generating the collums
			map[f][i] = new arenatile[xwidth];
		}

	}
	for (int f = 0; f < levels; f++) {
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {


				map[f][y][x] = ".";

			}
		}
	}

}

void arena::swapFights(int f, int s) {
	std::swap(fightque[f], fightque[s]);
}

ship* arena::runsim() {


	return mostWins();
}

ship* arena::mostWins() {
	ship* output = NULL;

	if (shipsInFights.size() != 0) {
		int most = shipsInFights[0]->getFightsWon();
		output = shipsInFights[0];
		for (int i = 1; i < shipsInFights.size(); i++) {
			if (most < shipsInFights[i]->getFightsWon()) {
				most = shipsInFights[i]->getFightsWon();
				output = shipsInFights[i];
			}
		}
	}

	return output;
}

ship* arena::mostLosses() {
	ship* output = NULL;

	if (shipsInFights.size() != 0) {
		int loss = shipsInFights[0]->getFightsLost();
		output = shipsInFights[0];
		for (int i = 1; i < shipsInFights.size(); i++) {
			if (loss < shipsInFights[i]->getFightsLost()) {
				loss = shipsInFights[i]->getFightsLost();
				output = shipsInFights[i];
			}
		}
	}

	return output;
}
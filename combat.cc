#include "combat.h"

arena::arena(int snumber, int fnumber) {
	shipnumber = snumber;
	numOfFights = fnumber;
}

arena::arena(int snumber, int fnumber, vector<ship*>& f) {
	shipnumber = snumber;
	numOfFights = fnumber;
}

arena::~arena() {
	

}

void arena::genShips(int i) {

}

void arena::clearAreana() {

}

void arena::createFight(vector<int> f) {

}

void arena::removeFights(vector<int> f) {

}

void arena::printQue() {

}

void arena::swapFights() {

}

ship arena::runsim() {

}

ship arena::mostWins() {

}

ship arena::mostLosses() {

}
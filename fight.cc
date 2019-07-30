#include "fight.h"


fight::fight(std::vector<ship*>& f) {

	for (int i = 0; i < f.size(); i++) {
		fighters.push_back(f[i]);
	}

	finished = false;
	running = false;
	winner = NULL;

}
#pragma once
#include <vector>

#include "ship.h"

class fight {
public:

	fight(std::vector<ship*>& f);
	~fight();

	std::vector<ship*>& getfighters() { return fighters; }
	ship* getWinner() { return winner; }

	bool isRunning() { return running; }
	bool isFinished() { return finished; }

	void completeFight() { finished = true; running = false; }
	void runningFight() { running = true; }
	void setWinner(int i) { winner = fighters[i]; }

private:

	bool finished;
	bool running;
	std::vector<ship*> fighters;
	ship* winner;

};


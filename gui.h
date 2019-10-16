#pragma once

#include <vector>
#include "ship.h"
#include "node.h"
#include "maptile.h"
#include "output.h"

class gui {
public:

	gui();
	gui(bool i);
	~gui();

	void createRoom();
	

	//getters and setters

	bool isterm() { return term; }
	bool setTerm(bool i) { term = i; }

	void setWrokingShip(ship *i) {}
	bool setWorkingRoom(int f, int y, int x);
	std::vector<int*> getOpenspots();


private:

	void printCMenu();
	void createRoomC();
	void choice(int i);

	bool term;
	console* con;

	node* room;
	ship* working;
	maptile*** shipmap;


};
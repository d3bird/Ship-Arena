//******************************************************************
//                                                                  
//  Class: output
//                                                                  
//  Purpose:  ...
//            
//  Functions:
//           Constructors
//				...
//           setters
//				...
//           getters
//				...
//  
//******************************************************************

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#include "node.h"
#include "ship.h"
#include "fight.h"
#include "combat.h"

class console {
public:

	console() {}

	void testprint(string i);
	void endprint();

	void print(node* test);
	void print(std::vector<node*>& input);
	void print(ship& test);
	void nline();
	void print(string i);

	void printFight(fight* f);
	void printArena(arena& a);

	void printShipMapTest(ship& test);

	int testNode();
	int testShip(bool map);


};


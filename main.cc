#include <iostream>
#include <string>
#include <vector>

#include "output.h"
#include "node.h"
#include "ship.h"
#include "combat.h"

static console con;

using namespace std;


int main(){
	console con;
	con.testShip();
	arena carn();
	//carn.genShips(2);

	cout << "finished program" << endl;
	return 0;
}

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
	con.testShip(true);

	//int snumber =2;
	//int fnumber= 1;
	//int dim[3] = { 1,100, 100 };
	//arena carn( snumber,  fnumber, dim);
	//carn.createMap();
	//carn.printMap();

	cout << "finished program" << endl;
	return 0;
}

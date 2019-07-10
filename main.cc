#include <iostream>
#include <string>
#include <vector>

#include "node.h"
#include "ship.h"
#include "output.h"


using namespace std;


int main(){

	
	string name ="node_test";
	int thrust =100;
	int weapons =200;
	int weight =400;	
	int lf =5;
	
	int temp[]={weight,weapons,thrust,lf};
	
	int x = 20;
	int y = 5;
	int f = 2;

	int map[] = { x,y,f };
	
	ship test(0, "test_ship",map);	

	//test.genNode(temp,true, "node1");
	////print(test);
	//test.genNode(temp,true, "node1");
	////print(test);
	//test.genNode(temp,true, "node1");
	////print(test);
	//print(test);
	//cout<<"damaging nodes"<<endl;
	//test.damagenode(0, 200);
	//print(test);
	//cout<<"repairing nodes"<<endl;
	
	test.printmap();

	
		cout << "done" << endl;
	return 0;
}

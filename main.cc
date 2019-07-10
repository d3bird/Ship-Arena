#include <iostream>
#include <string>
#include <vector>

#include "node.h"
#include "ship.h"

using namespace std;

void testprint(string i){
	cout<<"----------------"<<i<<"----------------"<<endl;
}

void endprint(){
	cout<<"----------------"<<"----------------------"<<endl;
}


void print(node test){
	
	testprint("node print");
	
	cout<<"name: "<<test.getName()<<endl;
	cout<<"weight: "<<test.getWeight()<<endl;
	cout<<"weapons: "<<test.getWeapons()<<endl;
	cout<<"thrust: "<<test.getThrust()<<endl;
	cout<<"breached: "<<test.isbreached()<<endl;
	cout<<"breached size: "<<test.getBreachSize()<<endl;
	cout<<"reqs life: "<<test.reqLifeforms()<<endl;
	cout<<"forms needed: "<<test.getReqForms()<<endl;
	cout<<"forms present: "<<test.getLifeForms()<<endl;
	cout<<"understaffed: "<<test.isonline()<<endl;
	cout<<"online: "<<test.isonline()<<endl;
	
	cout<<endl;
	
	endprint();
	
}

void print(ship test){
	
	testprint("ship print");
	
	cout<<"name: "<<test.getName()<<endl;
	cout<<"thrust: "<<test.getThrustspeed()<<endl;
	cout<<"weapons: "<<test.getweapons()<<endl;
	cout<<"weight: "<<test.getTotalweight()<<endl;
	cout<<"fights won: "<<test.getFightsWon()<<endl;
	cout<<"fights lost: "<<test.getFightsLost()<<endl;
	cout<<"W streak: "<<test.getWinStreak()<<endl;
	cout<<"L streak: "<<test.getLossStreak()<<endl;
	cout<<"alive: "<<test.isAlive()<<endl;
	cout<<"breached: "<<test.isBreach()<<endl;
	cout<<"oxygen lvls: "<<test.getOxygen()<<endl;
	cout<<"life forms: "<<test.numLivingForms()<<endl;
	cout<<"efficency: "<<test.getEfficency()<<endl;
	
	endprint();
	cout<<endl;
	
	endprint();
}

int main(){

	
	string name ="node_test";
	int thrust =100;
	int weapons =200;
	int weight =400;	
	int lf =5;
	
	int temp[]={weight,weapons,thrust,lf};
	
	
	ship test(0, "test_ship");	
	test.genNode(temp,true, "node1");
	//print(test);
	test.genNode(temp,true, "node1");
	//print(test);
	test.genNode(temp,true, "node1");
	//print(test);
	print(test);
	cout<<"damaging nodes"<<endl;
	test.damagenode(0, 200);
	print(test);
	cout<<"repairing nodes"<<endl;
	
	
	return 0;
}

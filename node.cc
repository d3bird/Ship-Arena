#include "node.h"

#include <string>
#include <iostream>

using namespace std;

node::node(int a[13], bool l, string n) {
	weight = a[0];
	maxWeight = weight;
	weapons = a[1];
	engines = a[2];
	reqforms = a[3];
	loc = new int[3];
	dloc = new int[3];

	//old code 
	//loc [0]= a[4];// x
	//loc[1] = a[5];// y
	//loc[2] = a[6];// f

	loc[0] = a[6];// f
	loc[1] = a[5];// y
	loc[2] = a[4];// x
	xsize = a[7];
	ysize = a[8];
	dloc[0] = a[9];// dx
	dloc[1] = a[10];// dy
	dloc[2] = a[11];// df
	//std::cout << a[12] << std::endl;
	designateRoom(a[12]);
	lifeforms = reqforms;
	map = NULL;
	name = n;
	reqLife = l;
	online = true;
	damaged = false;
	destoried = false;
	breached = false;
	breachsize = 0;
	/*understaffed = false;
	blank = true;
	engroom = false;
	powerRoom = false;
	weaponsRoom = false;
	miscRoom = false;*/
	xinsideSize = xsize - 2;
	yinsideSize = ysize - 2;
	//genRoomLayout();
}

node::~node() {
	delete[] loc;
	delete[] dloc;
}

int node::getWeapons(){
	if(destoried){
		return 0;
	}else if ( damaged || understaffed){
		if(damaged && understaffed){
				return (weapons/4);
		}else{
			return (weapons/2);
		}
	}
	return weapons;
}

int node::getThrust(){
	if(destoried){
		return 0;
	}else if (damaged || understaffed){
		if(damaged && understaffed){
		return (engines/4);
		}else{
		return (engines/2);
		}
	}else{
	return engines;
	}
}

void node::damage(int i){
	if ((weight/4)<i){
		breached =true;
		breachsize++;
		lifeforms--;
		if((reqforms/2)>lifeforms){
			understaffed =true;
		}
		if(lifeforms<0){
			lifeforms =0;
		}
	}
	weight -=i;
	
	if(weight<0){// removes negative numbers
		weight =0;
	}else{
	
		if (!damaged && (maxWeight/2)>=weight){
			damaged =true;
		}	
	
	 	if (damaged && (maxWeight/3)>=weight){
			destoried =true;
			cout<<"this node has been destoried"<<endl;
		}
	}
}

void node::repair(int i){
	if ((weight/4)<i){
		breachsize--;
		if(breachsize<=0){
			breachsize =0;
			breached =false;
		}
	}
	
	weight+=i;
	if(weight>maxWeight){
		weight = maxWeight;
	}
}

//for generaric room designation
void node::designateRoom(int i) {
	blank = false;
	engroom = false;
	powerRoom = false;
	weaponsRoom = false;
	miscRoom = false;

	switch (i){
	case 0:// engine room case
		engroom = true;
		break;
	case 1:// power room case
		powerRoom = true;
		break;
	case 2:// weapons room case
		weaponsRoom = true;
		break;
	case 3:// misc room case
		miscRoom = true;
		break;

	default:
		blank = true;
		//std::cout << "improper room state asinged, setting room to blank" << std::endl;
		break;
	}
}

void node::setRoomType(int i) {

	 blank = false;
	 engroom = false;
	 powerRoom = false;
	 weaponsRoom = false;
	 miscRoom = false;

	 switch (i) {
	 case 0:
		 engroom = true;
		 break;
	 case 1:
		 powerRoom = true;
		 break;
	 case 2:
		 weaponsRoom = true;
		 break;
	 case 3:
		 miscRoom = true;
		 break;

	 default:
		 blank = true;

	 }
}


void node::setSize(int x, int y) {
	xsize = x;
	ysize = y;

	xinsideSize = xsize - 2;
	yinsideSize = ysize - 2;
}
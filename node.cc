#include "node.h"
#include <string>
#include <iostream>

using namespace std;

node::node(int a[4],bool l, string n){
weight = a[0];
maxWeight = weight;
weapons =a[1];
engines =a[2];
reqforms=a[3];
lifeforms=reqforms;
name = n;
reqLife = l;
online = true;
damaged =false;
destoried =false;
breached =false;
breachsize =0;
understaffed = false;
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
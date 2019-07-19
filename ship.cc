#include "ship.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ship::ship(int n, string na, int dim[3]){
	totalweight =0;
	weaponspower =0;
	thrustspeed =0;
	sectionsnum =0;
	//genNode(n);
	name =na;
	fightswon =0;
	fightslost =0;
	wstreak =0;
	lstreak =0;
	alive =true;
	breached =false;
	gravity = true;
	oxegen =100;
	lastfight =0;
	currentstreak =1;
	life =0;
	team=0;
	xwidth = dim[0];
	ywidth = dim[1];
	floors = dim[2];
	genblankmap();
	convertToGrid(5,5);
	addDoors();
}

ship::~ship() {
	for (int f = 0; f < floors; f++) {
		for (int y = 0; y < ywidth; y++) {
			delete[] map[f][y];
		}
		delete[] map[f];
	}
	delete[] map;
}

//updates the ship stats after it takes damage
//needs to be optimised after it is working
void ship::update(){
	totalweight =0;
	weaponspower =0;
	thrustspeed =0;
	life =0;
	
	for(int i =0; i < sections.size();i++){
		totalweight += sections[i].getWeight();
		weaponspower += sections[i].getWeapons();
		thrustspeed += sections[i].getThrust();
		life +=sections[i].getLifeForms();
	}
	
	//preform calculation for thrust speed
	
}

	
void ship::genNode(int a[4], bool l, string n){
	node temp(a,l,n);
	sections.push_back(temp);
	update();
}


void ship::damagenode(int nod, int amnt){
	if(nod<sections.size()){
		sections[nod].damage(amnt);
		update();
	}
	
}

void ship::damagenodes(int dam, vector<int> nnodes){
	for(int i =0; i<nnodes.size();i++){
		sections[nnodes[i]].damage(dam);
	}
	update();
}

void ship::repairNode(int nod, int amnt){
	sections[nod].repair(amnt);
	
	update();
}


void ship::inputFightResults(int i){
	if(i < 0){//the fight was a loss
		fightslost++;
		if(lastfight<0){//same as the last fight
			currentstreak++;
		}else{//not the same as the last fight
			if(currentstreak>wstreak){
				wstreak = currentstreak;
				currentstreak =1;
			}
		}
		
	}else{//the fight was a victory 
		fightswon++;
		if(lastfight>0){//same as the last fight
			currentstreak++;
		}else{//not the same as the last fight
			if(currentstreak>lstreak){
				lstreak = currentstreak;
				currentstreak =1;
			}
		}
		
		lastfight = i;
	}
	
	
}


double ship::getEfficency(){
	double current =0;
	double max=0;
	double output =-1;
	
	for(int i =0; i< sections.size(); i++){
		if(!sections[i].isDestoried()){
			if(sections[i].isUnderstaffed() || sections[i].isDamaged() ){
				if(sections[i].isUnderstaffed() && sections[i].isDamaged()){
					current+=25;
				}else{
					current+=50;
				}
				max +=100;
			}else{
				current+=100;
				max +=100;
			}
		}
	}
	if(current == max){
		return 100;
	}else{
		output = current/max;
		//cout<<current<<" / "<<max<<endl;
		return output;
	}
}

void ship::moveLifeForms(int from, int to, int amnt){

	if((from<sections.size())&&(to<sections.size())){
		
	int moveamount =amnt;
	if(sections[from].getLifeForms()<amnt){
		moveamount = sections[from].getLifeForms();
	}
	sections[from].removeLife(moveamount);
	sections[to].addLife(moveamount);
		
	}else{
		cout<<"node inputs are out of bounds"<<endl;
		cout<<"node1: "<<from<<endl;
		cout<<"node2: "<<to<<endl;
	}
	
}

// when dealing with the map, y should always come before the 

void ship::genMap() {





}

void ship::addDoors() {
	cout << "adding doors to rooms" << endl;

	cout << "done" << endl;
}

void ship::convertToGrid(int rx, int ry) {
	cout << "converting the ship to a grid" << endl;
	//cursors for room generation
	int cx = 0;
	int cy = 0;
	int cf = 0;
	bool running = true;
	//going through the entire ship checking for 

	while (running) {

		if (cf < floors) {//checks to see if there are floors left to do

			if (cy + ry < ywidth) {// check to see if you need to move to the next collum

				if (cx + rx > xwidth) {
					cf++;
					cx = 0;
					cy = 0;
					if (cf >= floors) {
						running = false;
					}
				}
				else {

					for (int x = 0; x < rx; x++) {
						for (int y = 0; y < ry; y++) {
							if ((y == 0 && x == 0) || (y == ry - 1 && x == 0) || (y == 0 && x == rx - 1) || (y == ry - 1 && x == rx - 1)) {
								map[cf][cy + y][cx + x] = ",";
							}
							else if (y == 0 || y == ry - 1) {
								map[cf][cy + y][cx + x] = "_";
							}
							else if (x == 0 || x == rx - 1) {
								map[cf][cy + y][cx + x] = "|";
							}
							else {
								map[cf][cy + y][cx + x] = ".";
							}
						}
					}

					cy += ry;
					cy++;
				}
			}
			else {
				cy = 0;
				cx += rx;
				cx++;
				if (cx >= xwidth) {// if it runs out of rows then it will head to the next row
					cf++;
					cx = 0;
					cy = 0;
				}
			}

		}
		else {
			running = false;
		}
		
	}
	cout << "cleaning" << endl;
	genHallways();
	cout << "done" << endl;

}

void ship::genblankmap() {

	map = new string **[floors];
	
	for (int f = 0; f < floors; f++) {

		map[f] = new string *[ywidth]; // generating the rows

		for (int i = 0; i < ywidth; i++) {// generating the collums
			map[f][i] = new string[xwidth];
		}

	}
	for (int f = 0; f < floors; f++) {//defualtly puts hallways everywere
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {
				map[f][y][x] = " ";

			}
		}
	}
}

//generate hallways 
void ship::genHallways() {
	bool running = true;
	int cf = 0;

	while (running) {

		if (cf < floors) {
			for (int x = 0; x < xwidth; x++) {
				for (int y = 0; y < ywidth; y++) {
					


				}
			}
			cf++;
		}
		else {
			running = false;
		}

	}

}

void ship::printmap() {
	for (int f = 0; f < floors; f++) {
		cout << endl;
		cout << "----------floor number: " << f << "-------------" << endl;
		cout << endl;
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {

				cout << map[f][y][x];

			}
			cout << endl;
		}
	}
}

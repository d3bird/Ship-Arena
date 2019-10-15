#include <string>
#include <vector>
#include <iostream>

#include "ship.h"
#include <iostream>

//#include "output.h"
using namespace std;

ship::ship(int n, string na, int dim[3]) {
	totalweight = 0;
	weaponspower = 0;
	thrustspeed = 0;
	sectionsnum = 0;
	name = na;
	fightswon = 0;
	fightslost = 0;
	wstreak = 0;
	lstreak = 0;
	alive = true;
	breached = false;
	gravity = true;
	oxegen = 100;
	lastfight = 0;
	currentstreak = 1;
	life = 0;
	team = 0;
	xwidth = dim[0];
	ywidth = dim[1];
	floors = dim[2];
	//ratios
	rfuel = 1;
	rpower = 1;
	rweapons = 1;
	roomsProw = 0;
	roomsPcol = 0;
	roomsatend = true;
	numrooms = 0;
	blankrooms = 0;
	genMap(n);
}

ship::ship(int n, string na, int dim[3], std::vector<node*>& r) {
	totalweight = 0;
	weaponspower = 0;
	thrustspeed = 0;
	sectionsnum = 0;
	name = na;
	fightswon = 0;
	fightslost = 0;
	wstreak = 0;
	lstreak = 0;
	alive = true;
	breached = false;
	gravity = true;
	oxegen = 100;
	lastfight = 0;
	currentstreak = 1;
	life = 0;
	team = 0;
	xwidth = dim[0];
	ywidth = dim[1];
	floors = dim[2];
	//ratios
	rfuel = 1;
	rpower = 1;
	rweapons = 1;
	roomsProw = 0;
	roomsPcol = 0;
	roomsatend = false;
	sections = r;
	genMap(n);
}

ship::~ship() {
	//removing the map
	for (int f = 0; f < floors; f++) {
		for (int y = 0; y < ywidth; y++) {
			delete[] map[f][y];
		}
		delete[] map[f];
	}
	delete[] map;

	//removing the arena ship icons
	for (int f = 0; f < Afloors; f++) {
		for (int y = 0; y < yAwidth; y++) {
			delete[] Amap[f][y];
		}
		delete[] Amap[f];
	}
	delete[] Amap;

	//removing the rooms

	for (int i = sections.size()-1; i > -1; i--) {
		delete sections[i];
	}

}

//updates the ship stats after it takes damage
//needs to be optimised after it is working
void ship::update() {
	totalweight = 0;
	weaponspower = 0;
	thrustspeed = 0;
	life = 0;
	rfuel = 1;
	rpower = 1;
	rweapons = 1;

	for (int i = 0; i < sections.size(); i++) {
		totalweight += sections[i]->getWeight();
		weaponspower += sections[i]->getWeapons();
		thrustspeed += sections[i]->getThrust();
		life += sections[i]->getLifeForms();

		if (!sections[i]->isBlank()) {
			if (sections[i]->isEngroom()) {
				rfuel += sections[i]->getRatio();
			}
			else if (sections[i]->ispowerRoom()) {
				rpower += sections[i]->getRatio();
			}
			else if (sections[i]->isweaponsRoom()) {
				rweapons += sections[i]->getRatio();
			}
		}

	}

	//preform calculation for thrust speed

}

//not currently in use
void ship::genNode(int a[4], bool l, string n){
	/*node temp(a,l,n);
	sections.push_back(temp);
	update();*/
}

void ship::damagenode(int nod, int amnt){
	if(nod<sections.size()){
		sections[nod]->damage(amnt);
		update();
	}
	
}

void ship::damagenodes(int dam, vector<int> nnodes){
	for(int i =0; i<nnodes.size();i++){
		sections[nnodes[i]]->damage(dam);
	}
	update();
}

void ship::repairNode(int nod, int amnt){
	sections[nod]->repair(amnt);
	
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
		if(!sections[i]->isDestoried()){
			if(sections[i]->isUnderstaffed() || sections[i]->isDamaged() ){
				if(sections[i]->isUnderstaffed() && sections[i]->isDamaged()){
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
	if(sections[from]->getLifeForms()<amnt){
		moveamount = sections[from]->getLifeForms();
	}
	sections[from]->removeLife(moveamount);
	sections[to]->addLife(moveamount);
		
	}else{
		cout<<"node inputs are out of bounds"<<endl;
		cout<<"node1: "<<from<<endl;
		cout<<"node2: "<<to<<endl;
	}
	
}

// when dealing with the map, the vars should be f y x (floor, y axis, x axis)
void ship::genMap(int n) {
	genblankmap();
	convertToGrid(5, 5);
	setMapStats();
	genRooms();
	update();
}

void ship::convertToGrid(int rx, int ry) {
	cout << "converting the ship to a grid" << endl;
	//cursors for room generation
	int cx = 0;
	int cy = 0;
	int cf = 0;
	int cdf = -1;
	int cdx = -1;
	int cdy = -1;
	int roomcusor = 0;
	node* tempRoom;
	int roominputs[13];
	int * roominputs2;
	bool roomswitch = true;
	bool running = true;
	bool roomsleft = true;
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

								if (x == rx - 1 && cx + x + 1 < xwidth && (cy!=0 || y!=0 )) {
									map[cf][cy + y][cx + x + 1] = "H";// places them in the corrners
								}

							}
							else if (y == 0 || y == ry - 1) {
								map[cf][cy + y][cx + x] = "_";
							}
							else if (x == 0 || x == rx - 1) {
								map[cf][cy + y][cx + x] = "|";

								if (x == rx - 1 && cx + x + 1 < xwidth) {
									map[cf][cy + y][cx + x+1] = "H";// places them besides the rooms
								}

								
								//places doors 
								if (roomswitch) {
									if (x == rx - 1 && y == ry / 2) {
										map[cf][cy + y][cx + x] = "D";
										cdf = cf;
										cdx = cx + x;
										cdy = cy + y;
										//cout << cdx << "," << cy + y << endl;
									}

								}
								else {
									if (x == 0 && y == ry / 2) {
										map[cf][cy + y][cx + x] = "D";
										cdf = cf;
										cdx = cx + x;
										cdy = cy + y;
									}
								}
							

							}
							else {
								map[cf][cy + y][cx + x] = ".";
							}
						}
					}

					//adds the room to the list of rooms
					if (roomcusor >= sections.size()) {
						roomsleft = false;

					}

					if (!roomsatend&&roomsleft) {

							cout << "adding room to room" << endl;
							roominputs2 = new int[3];
							roominputs2[0] = cx;
							roominputs2[1] = cy;
							roominputs2[2] = cf;
							sections[roomcusor]->setloc(roominputs2);
							roominputs2 = new int[3];
							roominputs2[0] = cdx;
							roominputs2[1] = cdy;
							roominputs2[2] = cdf;
							sections[roomcusor]->setDloc(roominputs2);
							sections[roomcusor]->setSize(rx, ry);
							roomcusor++;
						
					}
					else {
						//cout << " making a blank room" << endl;
						roominputs[0] = 10;//weight
						roominputs[1] = 0;//weapons
						roominputs[2] = 0;//engins
						roominputs[3] = 0;
						roominputs[4] = cx;
						roominputs[5] = cy;
						roominputs[6] = cf;
						roominputs[7] = rx;
						roominputs[8] = ry;
						roominputs[9] = cdx;
						roominputs[10] = cdy;
						roominputs[11] = cdf;
						roominputs[12] = -1;
						tempRoom = new node(roominputs, false, "blankroom");
						sections.push_back(tempRoom);

						blankrooms++;

					}


					numrooms++;
					
				

					cy += ry;
					if (cy < ywidth && cx < xwidth) {// places hallways under the rooms
						for (int x = 0; x < rx; x++) {
							map[cf][cy][cx + x] = "H";
						}

						if (cx + rx < ywidth) {// places hallways at intersections
							map[cf][cy][cx + rx] = "H";
						}
					
					}
					cy++;
					
				}
			}
			else {
				cy = 0;
				cx += rx;
				cx++;
				roomsProw++;

				if (roomswitch) {
					roomswitch = false;
				}
				else {
					roomswitch = true;
				}

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
	
	roomsPcol = numrooms / roomsProw;

	cout << "done" << endl;

}

void ship::genblankmap() {

	map = new shiptile **[floors];
	
	for (int f = 0; f < floors; f++) {

		map[f] = new shiptile *[ywidth]; // generating the rows

		for (int i = 0; i < ywidth; i++) {// generating the collums
			map[f][i] = new shiptile[xwidth];
		}

	}
	for (int f = 0; f < floors; f++) {
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {
				map[f][y][x] = " ";

			}
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

				cout << map[f][y][x].getobj();

			}
			cout << endl;
		}
	}
}

void ship::setMapStats() {

	bool b[4] = { false,false,false,false };
	int i[2] = { 0,0 };
	double d = 0;

	for (int f = 0; f < floors; f++) {
		for (int y = 0; y < ywidth; y++) {
			for (int x = 0; x < xwidth; x++) {

				if (map[f][y][x].getobj() == "|" || map[f][y][x].getobj() == "_" || map[f][y][x].getobj() == ",") {
					b[0] = true;
					b[1] = true;
					b[2] = false;
					b[3] = false;
					i[0] = 20;
					i[1] = 20;
					d = 10;
				}
				else {
					b[0] = false;
					b[1] = false;
					b[2] = false;
					b[3] = false;
					i[0] = 0;
					i[1] = 0;
					d = 0;
				}
				
				map[f][y][x].setVars(b, i, d);
			}
			//cout << endl;
		}
	}

}

void ship::generateArenaMap() {

	if (map != NULL) {

		xAwidth = xwidth / 6;
		yAwidth = ywidth / 6;
		Afloors = floors;

		//std::cout << xAwidth << endl;
		//std::cout << yAwidth << endl;
		//std::cout << Afloors << endl;
		Amap = new arenatile * *[Afloors];

		for (int f = 0; f < Afloors; f++) {

			Amap[f] = new arenatile * [yAwidth]; // generating the rows

			for (int i = 0; i < yAwidth; i++) {// generating the collums
				Amap[f][i] = new arenatile[xAwidth];
			}

		}


		int amount = 0;

		int xc = 0;// for the small map
		int yc = 0;

		int x = 0;//for the big map
		int y = 0;//

		bool running = true;

		for (int f = 0; f < Afloors; f++) {
			running = true;
			y = 0;
			x = 0;
			yc = 0;
			xc = 0;
			while (running) {

				for (int i = 0; i < 6; i++) {
					for (int ix = 0; ix < 6; ix++) {
						if (map[f][y + i][x + ix].getobj() != " ") {
							amount++;
						}

					}

				}
				//std::cout << amount << std::endl;
				if (amount >= 30) {
					Amap[f][yc][xc] = "X";
				}
				else if (amount >= 10) {
					Amap[f][yc][xc] = "/";
				}
				else {
					Amap[f][yc][xc] = "O";
				}
				amount = 0;
				yc++;
				//std::cout << yc << " " << yAwidth << std::endl;
				if (yc >= yAwidth) {
					yc = 0;
					xc++;
					if (xc >= xAwidth) {
						running = false;
					}
				}
			}
		}
	}
	else {
		cout << "the map has not been defined yet" << endl;
	}
}

arenatile*** ship::getArenaMap() {
	if (Amap == NULL) {
		generateArenaMap();
	}
	
	return Amap;
}

void ship::prinArenaMap() {

	cout << "printing ship map icon" << endl;

	for (int f = 0; f < floors; f++) {
		cout << endl;
		cout << "---------level number: " << f << "-------------" << endl;
		cout << endl;
		for (int y = 0; y < yAwidth; y++) {
			for (int x = 0; x < xAwidth; x++) {

				cout << Amap[f][y][x].getobj();

			}
			cout << endl;
		}
	}

}

void ship::genRooms() {
	//std::cout << sections.size() << std::endl;
	for (int i = 0; i < sections.size(); i++) {
		addRoomTomap(i);
	}
}

int ship::getdoorside(int* d, int* l, int* size) {
	int output = -1;

	if (d[2] == l[2]) {// left half
		output = 0;
	}
	else if (d[2] == l[2] + size[0]) {// right half
		output = 1;
	}
	else if (d[1] == l[1]) {// top half
		output = 2;
	}
	else if (d[1] == l[1] + size[1]) {// bottom half
		output = 3;
	}

	return output;
}

//this function rewrites a room to the map
void ship::addRoomTomap(int index) {
	int xi = sections[index]->getXinside();
	int yi = sections[index]->getYinside();
	int* loc = sections[index]->getloc();
	int* dloc = sections[index]->getDloc();
	int side = getdoorside(dloc, loc, sections[index]->getsize());
	//std::cout << "redrawling room at: " << loc[0] << " " << loc[1] << " " << loc[2] << std::endl;

	if (sections[index]->isEngroom()) {
		//std::cout << "making a engine room" << std::endl;
		for (int i = 0; i < yi; i++) {
			for (int q = 0; q < xi; q++) {
				if ((i == 0 && q == 0) ||  (i == yi - 1 && q == xi - 1)) {// the corners of the room
					map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "O";
				}
				else if (i == yi - 1 && q == 0) {
					map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "C";
				}
				else {
					map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = ".";
				}
			}
		}
	}
	else if (sections[index]->ispowerRoom()) {
		//std::cout << "making a power room" << std::endl;
		for (int i = 0; i < yi; i++) {
			for (int q = 0; q < xi; q++) {
				map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "p";
			}
		}
	}
	else if (sections[index]->isweaponsRoom()) {
		//std::cout << "making a weapons room" << std::endl;
		for (int i = 0; i < yi; i++) {
			for (int q = 0; q < xi; q++) {

				switch (side) {
				case 0:
				case 1:
					if (i == 0) {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "=";
					}
					else if (i == yi - 1 && q == 0) {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "C";
					}
					else {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = ".";
					}
					break;
				case 2:
				case 3:

					if (q == 0) {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "=";
					}
					else if (i == 0 && q == xi-1) {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "C";
					}
					else {
						map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = ".";
					}

					break;
				default:
					map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = ".";

				}

				
			}
		}
	}
	else if (sections[index]->ismiscRoom()) {// for special rooms
		//std::cout << "making a misc room" << std::endl;
		for (int i = 0; i < yi; i++) {
			for (int q = 0; q < xi; q++) {
				map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = "m";
			}
		}
	}
	else {
		//std::cout << "making a blank room" << std::endl;
		for (int i = 0; i < yi; i++) {
			for (int q = 0; q < xi; q++) {
				map[loc[0]][loc[1] + 1 + i][loc[2] + 1 + q] = ".";
			}
		}
	}

}


void ship::genRooms(int num) {


}
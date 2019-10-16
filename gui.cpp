#include "gui.h"


gui::gui() {
	term = false;
}

gui::gui(bool i) {
	term = i;
}
gui::~gui() {

}

void gui::createRoom() {
	if (term) {
		createRoomC();
	}
}


bool gui::setWorkingRoom(int f, int y, int x) {
	std::vector<node*> shiprooms = working->getRooms();
	int* temp;
	for (int i = 0; i < shiprooms.size(); i++) {
		temp = shiprooms[i]->getloc();
		if (temp[0] == f && temp[1] == y && temp[2] == x) {
			room = shiprooms[i];
			return true;
		}
	}
	return false;
}


 std::vector<int*> gui::getOpenspots() {
	std::vector<node*> shiprooms = working->getRooms();
	int* temp;
	std::vector<int*> output;

	for (int i = 0; i < shiprooms.size(); i++) {
		if (shiprooms[i]->isBlank()) {
			temp = shiprooms[i]->getloc();
			output.push_back(temp);
		}
	}

	return output;
}

void gui::printCMenu() {


}

void gui::choice(int i){
	

}

void gui::createRoomC() {




}
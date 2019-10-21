#include "gui.h"


gui::gui() {
	term = false;
	room = NULL;
	working = NULL;
	con = new console();
}

gui::gui(bool i) {
	term = i;
	room = NULL;
	working = NULL;
}
gui::~gui() {
	delete room;
	delete working;
}



void gui::run() {
	if (term) {// for the command line interface
		bool running = true;
		int input;
		std::string sinput;

		while (running) {
			printCMenu();
			std::cin.clear();
			std::cin >> input;
			//std::cout << input << endl;
			//running = choice(input);

				bool news = false;
			switch (input) {
			case 0:

				std::cout << "menu choice 0" << std::endl;
				if (working != NULL) {
					std::cout << "There is already a ship here. Are you sure you want to create a new one (input yes or no)" << std::endl;
					std::cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::getline(std::cin, sinput);
					if (sinput == "yes") {
						delete working;
						news = true;
					}
					else {
						std::cout << "returning to menu" << std::endl;
					}
				}
				else {
					news = true;
				}

				if (news) {
					std::cout << "creating new ship" << std::endl;
					int* dim = new int[3];
					std::cout << "input x width" << std::endl;
					std::cin.clear();
					std::cin >> input;
					dim[0] = input;
					std::cout << "input y width" << std::endl;
					std::cin.clear();
					std::cin >> input;
					dim[1] = input;
					std::cout << "input # of floors" << std::endl;
					std::cin.clear();
					std::cin >> input;
					dim[2] = input;
					std::cout << "input shipt name" << std::endl;
					std::cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::getline(std::cin, sinput);
					if (cin.fail()) {
						sinput = "new ship";
					}

					std::cout << std::endl;
					std::cout << "ship name: " << sinput << std::endl;
					std::cout << "x width: " << dim[0] << std::endl;
					std::cout << "y width: " << dim[1] << std::endl;
					std::cout << "# of floors " << dim[2] << std::endl;
					std::cout << std::endl;

					working = new ship(-1, sinput, dim);
				}

				break;
			case 1:
				std::cout << "create new room" << std::endl;
				break;
			case 2:
				std::cout << "list all current rooms" << std::endl;
				break;
			case 3:
				std::cout << "load/modify a room" << std::endl;
				break;
			case 4:
				std::cout << "display ship map" << std::endl;
				if (working != NULL) {
					con->print(working);
				}
				else {
					std::cout << "there is no current ship in storage" << std::endl;
				}
				
				break;
			case 5:
				std::cout << "menu choice 5" << std::endl;
				break;
			case 6:
				std::cout << "exit editor" << std::endl;
				running = false;
				break;
			default:
			
				std::cout << "not a choice, try again." << std::endl;
				break;
			}

		}

	}
	else {// for the 3d interface


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

	std::cout << std::endl;
	std::cout << "Enter number for menue choice" << std::endl;
	std::cout << "0: create new ship" << std::endl;
	std::cout << "1: create new room" << std::endl;
	std::cout << "2: list all current rooms" << std::endl;
	std::cout << "3: load/modify room" << std::endl;
	std::cout << "4: display ship map" << std::endl;
	std::cout << "5: " << std::endl;
	std::cout << "6: exit editer" << std::endl;
	std::cout << std::endl;

}


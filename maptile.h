#pragma once

#include <string>

/*
* This class that handles what information is stored in each map tile
* More varribles can be added latter to preform more complex equations 
* when dealing with how much damage each tile recives from events
*/
class maptile {
public:

	std::string getobj() { return obj; }

	bool operator =(std::string other) {
		obj = other;
		return true;
	}

	bool operator ==(std::string o) {
		if (obj == o) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	std::string obj;
};

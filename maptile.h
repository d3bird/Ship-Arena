
#include <string>

#include "ship.h"


#ifndef MAPINGTILE
#define MAPINGTILE

/*
* This class that handles what information is stored in each map tile
* More varribles can be added latter to preform more complex equations 
* when dealing with how much damage each tile recives from events
*/
class maptile {
public:

	std::string getobj() { return obj; }
	void setObj(std::string i) { obj = i; }

	bool operator =(std::string other) { setObj(other); return true; }
	bool operator ==(std::string o){ return getobj() == o ? true : false; }
	
private:
	std::string obj;
};

#endif



#ifndef FIGHTINGTILE
#define FIGHTINGTILE

class arenatile {
public:
	std::string getobj() { return obj; }
	void setObj(std::string i) { obj = i; }

	bool operator =(std::string other) { setObj(other); return true; }
	bool operator ==(std::string o) { return getobj() == o ? true : false; }

private:
	std::string obj;
};

#endif
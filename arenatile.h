#pragma once

#include <string>

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


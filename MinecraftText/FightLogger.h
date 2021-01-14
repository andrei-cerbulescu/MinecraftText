#pragma once
#include <vector>
#include <string>

class FightLogger
{
private:
	static FightLogger* instance;
	std::vector<std::string> log;
	FightLogger();
public:
	static FightLogger* getInstance() {
		if (!instance)
			instance = new FightLogger();
		return instance;
	}

	void addLogEntry(std::string toBeAdded) {
		this->log.push_back(toBeAdded);
	}

	std::vector<std::string> getLog() {
		return(this->log);
	}

};


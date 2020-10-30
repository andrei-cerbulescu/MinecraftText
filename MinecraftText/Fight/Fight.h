#pragma once
#include "../Player.h"
#include "../Mobs.h"
#include <iostream>
#include <vector>

static std::vector<Mobs*> mobTypesList;

class Fight {
private:

	std::vector<Mobs*> fightMobsVector;
	

	void generateMobs() {

	}

public:
	Fight(Player *player1);

	void fightFunction(Player* player1) {



	}

};
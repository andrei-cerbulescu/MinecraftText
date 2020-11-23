#include "Fight.h"

Fight::Fight(Player *player1) {
	this->fightPlayer = player1;
	generateMobs();
	fightFunction();
}
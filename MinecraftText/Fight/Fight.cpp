#include "Fight.h"

Fight::Fight(Player *player1) {
	generateMobs();
	fightFunction(player1);
}
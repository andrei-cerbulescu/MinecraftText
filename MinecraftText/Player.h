#pragma once
#include "Inventory.h"
#include<iostream>
#include <vector>

class Player
{
private:
	int hp;
	std::vector<InventorySlot*> playerInventory;

public:
	Player();
	bool isInventoryFull () {
		for (int i = 0; i < 20; i++) {
			if (this->playerInventory.at(i)->isEmpty() == true) return(false);
		}
		return(true);
	}

	bool isDead() {
		if (this->hp <= 0) return(true);
		return(false);
	}
};


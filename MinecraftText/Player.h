#pragma once
#include "Inventory.h"
#include<iostream>
#include <vector>

class Player
{
private:
	int hp;

public:
	Inventory *inventorySpace;

	Player();

	bool isDead() {
		if (this->hp <= 0) return(true);
		return(false);
	}
};


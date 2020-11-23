#pragma once
#include "Inventory.h"
#include<iostream>
#include <vector>

class Player
{
private:
	int hp;
	int baseDamage;
	int damageModifier;

public:
	Inventory *inventorySpace;

	Player();

	bool isDead() {
		if (this->hp <= 0) return(true);
		return(false);
	}

	void endGame() {
		this->inventorySpace->freeEverything();
		delete this->inventorySpace;
		delete this;
	}

	int getDamage() {
		return(this->baseDamage + this->damageModifier);
	}
};


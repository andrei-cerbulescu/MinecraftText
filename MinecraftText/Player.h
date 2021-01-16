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

	int getHP() {
		return(this->hp);
	}

	bool isDead() {
		if (this->hp <= 0) return(true);
		return(false);
	}

	void endGame() {
		this->inventorySpace->freeEverything();
		delete this->inventorySpace;
	}

	int getDamage() {
		return(this->baseDamage + this->damageModifier);
	}

	void takeDamage(int damage) {
		this->hp = this->hp - damage;
	}
};


#pragma once
#include "Inventory.h"
#include "InventorySlot.h"
#include <string>
#include <iostream>
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

	void healPlayer(int toBeAdded) {
		this->hp += toBeAdded;
	}

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

	void updateModifiers() {

		int maxModifier = 0;

		for (int i = 0; i < this->inventorySpace->getInventory().size(); i++) {
			if (this->inventorySpace->getInventory().at(i)->getItemName().find("Sword") != std::string::npos) {
				
				if (this->inventorySpace->getInventory().at(i)->getCurentItem()->getBonusDamage() > maxModifier) {
					maxModifier = this->inventorySpace->getInventory().at(i)->getCurentItem()->getBonusDamage();
				}

			}
		}

		this->damageModifier = maxModifier;

	}
};


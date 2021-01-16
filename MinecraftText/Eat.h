#include <iostream>
#include "Player.h"
#include <vector>

void eatFunction(Player *curentPlayer) {

	int foodCounter = 0;

	for (int i = 0; i < curentPlayer->inventorySpace->getInventorySize(); i++) {

		if (curentPlayer->inventorySpace->getInventory().at(i)->isEdible()) {

			std::cout << i + 1 << "." << curentPlayer->inventorySpace->getInventory().at(i)->getItemName() << " " << curentPlayer->inventorySpace->getInventory().at(i)->getQuantity() << "\n";
			foodCounter++;

		}

	}

	while (true) {

		std::cout << "What would you like to eat? Insert 0 if nothing.\n";

		int decission;
		std::cin >> decission;

		decission = decission - 1;

		if (decission == 0) {
			break;
		}

		if (curentPlayer->inventorySpace->getInventory().at(decission)->isEdible()) {
			curentPlayer->healPlayer(curentPlayer->inventorySpace->getInventory().at(decission)->getSaturation());
			curentPlayer->inventorySpace->getInventory().at(decission)->removeQuantity(1);
			break;
		}

		if (foodCounter == 0) {
			break;
		}

	}


	std::cout << "What would you like to eat?\n";


}
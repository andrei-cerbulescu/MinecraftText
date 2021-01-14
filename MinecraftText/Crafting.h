#pragma once
#include "./Player.h"

void CraftFunction(Player* curentPlayer) {

	std::cout << "1.Craft Sword - 1 wood, 3 stone\n";

	int decission;
	std::cin >> decission;

	if (decission == 1) {
		int countWood = curentPlayer->inventorySpace->countSpecificItem("Wood");
		int countStone = curentPlayer->inventorySpace->countSpecificItem("Stone");

		if (countWood >= 1 && countStone >= 3) {
			curentPlayer->inventorySpace->removeSpecific("Wood", 1);
			curentPlayer->inventorySpace->removeSpecific("Stone", 3);

			InventorySlot* tempSword = new InventorySlot();
			tempSword->emptyQuantity();
			tempSword->setItemType(new Sword());
			tempSword->setQuantity(1);

			curentPlayer->inventorySpace->addItemsToExisting(tempSword);

		}
	}


}
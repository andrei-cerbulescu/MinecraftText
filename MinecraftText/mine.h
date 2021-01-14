#pragma once
#include "Player.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "InventorySlot.h"
#include "Items.h"

void mineFunction(Player* player1) {

	int stoneMined, ironMined, woodFound;

	stoneMined = rand() % 32 + 1;
	ironMined = rand() % 8 + 1;
	woodFound = rand() % 6 + 1;

	InventorySlot *curentSlot = player1->inventorySpace->getFirstEmptySlot();

	InventorySlot *tempStone = new InventorySlot();
	tempStone->emptyQuantity();
	tempStone->setItemType(new Stone());
	tempStone->addQuantity(stoneMined);

	player1->inventorySpace->addItemsToExisting(tempStone);

	InventorySlot* tempIron = new InventorySlot();
	tempIron->emptyQuantity();
	tempIron->setItemType(new Iron());
	tempIron->addQuantity(ironMined);

	player1->inventorySpace->addItemsToExisting(tempIron);

	InventorySlot* tempWood = new InventorySlot();
	tempWood->emptyQuantity();
	tempWood->setItemType(new Wood());
	tempWood->addQuantity(woodFound);

	player1->inventorySpace->addItemsToExisting(tempWood);

}
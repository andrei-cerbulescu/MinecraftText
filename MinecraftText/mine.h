#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "InventorySlot.h"
#include "Items.h"

void mineFunction(Player* player1) {

	srand(time(NULL));

	int stoneMined, ironMined;

	stoneMined = rand() % 32 + 1;
	ironMined = rand() % 8 + 1;

	InventorySlot *curentSlot = player1->inventorySpace->getFirstEmptySlot();
	
	curentSlot->setItemType(new Stone());
	curentSlot->emptyQuantity();
	curentSlot->addQuantity(stoneMined);


}
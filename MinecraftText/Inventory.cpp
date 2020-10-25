#include "Inventory.h"
#include "Items.h"

Inventory::Inventory() {

	for (int i = 0; i < 20; i++) {

		InventorySpace.push_back(new InventorySlot());
		InventorySpace.at(i)->setItemType(new Nothing());

	}

}
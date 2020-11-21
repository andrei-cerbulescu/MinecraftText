#include "Inventory.h"
#include "Items.h"

Inventory::Inventory() {

	

	for (int i = 0; i < this->getInventorySize(); i++) {

		inventorySpace.push_back(new InventorySlot());
		inventorySpace.at(i)->setItemType(new Nothing());

	}

}
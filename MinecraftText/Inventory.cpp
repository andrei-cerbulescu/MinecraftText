#include "Inventory.h"

Inventory::Inventory() {

	for (int i = 0; i < 20; i++) {

		InventorySpace.push_back(new InventorySlot());

	}

}
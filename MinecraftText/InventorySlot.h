#pragma once
#include "Items.h"

class InventorySlot : Item
{
private:
	int quantity;

public:
	bool isEmpty() {
		if (this->quantity == 0) return(true);
		return(false);
	}
};


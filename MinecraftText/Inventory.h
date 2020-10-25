#pragma once
#include "InventorySlot.h"
#include <iostream>
#include <vector>

class Inventory
{
protected:
	
		std::vector<InventorySlot*> InventorySpace;
	

public:

	Inventory();

	bool isFull() {

		for (int i = 0; i < 20; i++) {
			if (InventorySpace.at(i)->isEmpty() == true) return(false);
		}
		
		return(true);
	}

};


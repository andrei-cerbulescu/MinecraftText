#pragma once
#include "InventorySlot.h"
#include <iostream>
#include <vector>
#include <string.h>

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

	InventorySlot *getFirstEmptySlot() {

		if (this->isFull()) {
			std::cout << "Inventory is full!\n";
			return(nullptr);
		}


		for (int i = 0; i < 20; i++) {
			if (InventorySpace.at(i)->isEmpty() == true) {
				return(InventorySpace.at(i));
			}
		}

	}

	InventorySlot *findItemByName(char itemName[50]) {

		for (int i = 0; i < 20; i++) {
			if (strcmp(itemName, InventorySpace.at(i)->getItemName())==0) {
				return(InventorySpace.at(i));
			}
		}

		return(nullptr);

	}

	void displayInventory() {

		std::cout << "You are currently carrying:\n";

		for (int i = 0; i < 20; i++) {
			InventorySpace.at(i)->stdPrintThisData();
		}

	}



};


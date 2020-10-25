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
			if (this->InventorySpace.at(i)->isEmpty() == true) return(false);
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
			if (strcmp(itemName, this->InventorySpace.at(i)->getItemName())==0) {
				return(this->InventorySpace.at(i));
			}
		}

		return(nullptr);

	}

	void addItemsToExisting(InventorySlot* toBeAdded) {

		for (int i = 0; i < 20; i++) {

			if (strcmp(this->InventorySpace.at(i)->getItemName(), toBeAdded->getCurentItem()->getItemName()) == 0) {
				if (this->InventorySpace.at(i)->getQuantity() < this->InventorySpace.at(i)->getStackSize()) {

					int maxAdded = toBeAdded->getCurentItem()->getStackSize() - this->InventorySpace.at(i)->getQuantity();

					if (maxAdded+ toBeAdded->getQuantity() > toBeAdded->getCurentItem()->getStackSize())  {
						this->InventorySpace.at(i)->addQuantity(maxAdded);
						toBeAdded->removeQuantity(maxAdded);
						this->addItemsToNewSlot(toBeAdded);
						return;
					}

					this->InventorySpace.at(i)->addQuantity(toBeAdded->getQuantity());
					delete toBeAdded;
					return;

				}
			}

		}

		this->setFirstEmptySlot(toBeAdded);

	}

	void setFirstEmptySlot(InventorySlot* toBeAdded) {

		for (int i = 0; i < 20; i++) {

			if (this->InventorySpace.at(i)->isEmpty()) {
				this->InventorySpace.at(i) = toBeAdded;
				return;
			}

		}

	}

	void addItemsToNewSlot(InventorySlot* toBeAdded) {

		//InventorySlot* firstEmpty = this->getFirstEmptySlot();
		//firstEmpty = toBeAdded;

		//this->getFirstEmptySlot() = toBeAdded;

	}

	void displayInventory() {

		std::cout << "You are currently carrying:\n";

		for (int i = 0; i < 20; i++) {
			this->InventorySpace.at(i)->stdPrintThisData();
		}

	}



};


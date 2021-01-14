#pragma once
#include "InventorySlot.h"
#include <iostream>
#include <vector>
#include <string.h>

class Inventory
{
protected:
	
		std::vector<InventorySlot*> inventorySpace;
		const int inventorySize = 20;

public:

	Inventory();

	int getInventorySize() {
		return(this->inventorySize);
	}

	bool isFull() {

		for (int i = 0; i < this->inventorySize; i++) {
			if (this->inventorySpace.at(i)->isEmpty() == true) return(false);
		}
		
		return(true);
	}

	InventorySlot *getFirstEmptySlot() {

		if (this->isFull()) {
			std::cout << "Inventory is full!\n";
			return(nullptr);
		}


		for (int i = 0; i < this->getInventorySize(); i++) {
			if (inventorySpace.at(i)->isEmpty() == true) {
				return(inventorySpace.at(i));
			}
		}

		return nullptr;

	}

	InventorySlot *findItemByName(std::string itemName) {

		for (int i = 0; i < this->getInventorySize(); i++) {
			if (this->inventorySpace.at(i)->getItemName().compare(itemName)==0) {
				return(this->inventorySpace.at(i));
			}
		}

		return(nullptr);

	}

	void addItemsToExisting(InventorySlot* toBeAdded) {

		for (int i = 0; i < this->getInventorySize(); i++) {

			if (this->inventorySpace.at(i)->getItemName().compare(toBeAdded->getCurentItem()->getItemName())== 0) {
				if (this->inventorySpace.at(i)->getQuantity() < this->inventorySpace.at(i)->getStackSize()) {

					int maxAdded = toBeAdded->getCurentItem()->getStackSize() - this->inventorySpace.at(i)->getQuantity();

					if (toBeAdded->getQuantity() +this->inventorySpace.at(i)->getQuantity() > toBeAdded->getCurentItem()->getStackSize()) {
						this->inventorySpace.at(i)->addQuantity(maxAdded);
						toBeAdded->removeQuantity(maxAdded);
						this->setFirstEmptySlot(toBeAdded);
						return;
					}

					this->inventorySpace.at(i)->addQuantity(toBeAdded->getQuantity());
					delete toBeAdded;
					return;

				}
			}

		}

		this->setFirstEmptySlot(toBeAdded);

	}

	void setFirstEmptySlot(InventorySlot* toBeAdded) {

		for (int i = 0; i < this->getInventorySize(); i++) {

			if (this->inventorySpace.at(i)->isEmpty()) {
				delete this->inventorySpace.at(i);
				this->inventorySpace.at(i) = toBeAdded;
				return;
			}

		}

	}

	void displayInventory() {

		std::cout << "You are currently carrying:\n";

		for (int i = 0; i < this->getInventorySize(); i++) {
			std::cout<<this->inventorySpace.at(i)<<"\n";
		}

	}

	void freeEverything() {

		for (int i = 0; i < this->getInventorySize(); i++) {

			delete this->inventorySpace.at(i);

		}

	}

	int countSpecificItem(std::string toBeFound) {
		int counter = 0;
		for (int i = 0; i < this->getInventorySize(); i++) {
			if (this->inventorySpace.at(i)->getCurentItem()->getItemName() == toBeFound) {

				counter += this->inventorySpace.at(i)->getQuantity();

			}
		}

		return counter;

	}

	void removeSpecific(std::string toBeFound, int quantity) {

		for (int i = this->getInventorySize()-1; i >= 0; i--) {

			if (quantity == 0) {
				break;
			}

			if (this->inventorySpace.at(i)->getCurentItem()->getItemName() == toBeFound) {

				if(quantity <= this->inventorySpace.at(i)->getQuantity()){
				
					this->inventorySpace.at(i)->removeQuantity(quantity);
					break;
				
				}

				if (quantity > this->inventorySpace.at(i)->getQuantity()) {
					
					quantity = quantity - this->inventorySpace.at(i)->getQuantity();
					this->inventorySpace.at(i)->emptyQuantity();

				}

			}

		}

	}

};


#pragma once
#include "Items.h"
#include <iostream>
#include <vector>

class InventorySlot
{
private:
	int quantity;
	Item *curentItem;


public:

	~InventorySlot();
	
	Item* getCurentItem() {
		return(this->curentItem);
	}

	bool isEmpty() {
		if (this->quantity == 0) return(true);
		return(false);
	}

	std::string getItemName(){

		return(this->curentItem->getItemName());

	}

	void addQuantity(int addedQuantity) {

		this->quantity = this->quantity + addedQuantity;

	}

	void removeQuantity(int removedQuantity) {
		this->quantity = this->quantity - removedQuantity;
	}

	void setItemType(Item *itemType) {

		delete this->curentItem;
		this->curentItem = itemType;

	}

	void emptyQuantity() {
		this->quantity = 0;
	}

	int getQuantity() {
		return(this->quantity);
	}

	int getStackSize() {
		return(this->curentItem->getStackSize());
	}

	void stdPrintThisData() {

		std::cout << this->quantity << " " << this->curentItem->getItemName() <<"\n";

	}

};


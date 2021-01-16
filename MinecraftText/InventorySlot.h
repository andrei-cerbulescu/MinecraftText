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

	friend std::ostream &operator<<(std::ostream& curentOstream, InventorySlot* curentObject) {	
		curentOstream << curentObject->quantity<<" "<< curentObject->getItemName();

		return curentOstream;
	}
	
	Item* getCurentItem() {
		return(this->curentItem);
	}

	int getSaturation() {
		return(this->curentItem->getSaturation());
	}

	bool isEdible() {
		return this->curentItem->getIsEdible();
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

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}

};


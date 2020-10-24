#pragma once
class InventorySlot
{
private:
	int quantity;

public:
	bool isEmpty() {
		if (this->quantity == 0) return(true);
		return(false);
	}
};


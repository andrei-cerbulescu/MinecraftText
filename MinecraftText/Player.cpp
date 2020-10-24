#include "Player.h"

Player::Player() {
	for (int i = 0; i < 20; i++) {

		this->playerInventory.push_back(new InventorySlot());

	}

	this->hp = 20;
}

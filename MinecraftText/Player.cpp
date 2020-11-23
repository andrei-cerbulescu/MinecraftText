#include "Player.h"

Player::Player() {
	this->baseDamage = 4;
	this->damageModifier = 0;
	this->hp = 20;
	this->inventorySpace = new Inventory();

}

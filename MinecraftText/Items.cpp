#include "Items.h"

Item::Item() {

	this->stackSize = 0;
	strcpy_s(this->name, "Nothing");
	this->isBreakable = false;
	this->durability = -1;
	this->isEdible = false;
	this->saturation = 0;

}

Nothing::Nothing() {

	this->stackSize = 0;
	strcpy_s(this->name, "Nothing");
	this->isBreakable = false;
	this->durability = -1;

}

Stone::Stone() {
	this->stackSize = 64;
	strcpy_s(this->name, "Stone");
	this->isBreakable = false;
	this->durability = -1;
}

Sword::Sword() {

	this->stackSize = 1;
	strcpy_s(this->name, "Sword");
	this->isBreakable = true;
	this->durability = -1;

}
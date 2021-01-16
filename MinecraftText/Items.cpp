#include "Items.h"

Item::Item() {

	this->stackSize = 0;
	this->name = "Nothing";
	this->isBreakable = false;
	this->durability = -1;
	this->isEdible = false;
	this->saturation = 0;
	this->bonusDamage = 0;

}

Nothing::Nothing() {

	this->name = "Nothing";

}

Stone::Stone() {
	this->stackSize = 64;
	name = "Stone";

}

Sword::Sword() {

	this->stackSize = 1;
	this->name = "Sword";
	this->isBreakable = true;
	this->durability = 128;
	this->bonusDamage = 6;

}

Iron::Iron() {

	this->stackSize = 64;
	this->name = "Iron";

}

Wood::Wood() {
	this->stackSize = 64;
	this->name = "Wood";
}

Apple::Apple() {

	this->isEdible = true;
	this->saturation = 6;
	this->name = "Apple";
	this->stackSize = 64;

}
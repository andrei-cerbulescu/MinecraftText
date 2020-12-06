#include "Mobs.h"

Mobs::Mobs() {
	this->hp = 0;
	this->damage = 0;
	this->diesOnAttack = false;
	this->isRanged = false;
	this->name = "Nothing";
}

Mobs::Mobs(const Mobs& toBeCopied) {

	this->damage = toBeCopied.damage;
	this->hp = toBeCopied.hp;
	this->diesOnAttack = toBeCopied.diesOnAttack;
	this->isRanged = toBeCopied.isRanged;
	this->name = toBeCopied.name;

}

Zombie::Zombie() {

	this->hp = 20;
	this->damage = 4;
	this->name = "Zombie";

}

Creeper::Creeper() {

	this->hp = 20;
	this->damage = 15;
	this->diesOnAttack = true;
	this->name = "Creeper";

}
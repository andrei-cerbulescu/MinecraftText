#include "Mobs.h"

Zombie::Zombie() {

	this->hp = 20;
	this->damage = 4;

}

Mobs::Mobs() {
	this->hp = 0;
	this->damage = 0;
}

Mobs::Mobs(const Mobs &toBeCopied) {

	this->damage = toBeCopied.damage;
	this->hp = toBeCopied.hp;
	this->diesOnAttack = toBeCopied.diesOnAttack;

}
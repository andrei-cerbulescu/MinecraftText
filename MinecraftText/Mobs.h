#pragma once
#include <string>
#include <iostream>
#include "./Player.h"

class Mobs
{
protected:
	int hp, damage;
	bool diesOnAttack, isRanged;
	std::string name;

public:

	Mobs();

	Mobs(const Mobs& toBeCopied);

	virtual void attack(Player* curentPlayer) {

	}

	int getDamage() {
		return this->damage;
	}

	Mobs& operator=(const Mobs& mob) {

		hp = mob.hp;
		damage = mob.damage;
		diesOnAttack = mob.diesOnAttack;
		isRanged = mob.isRanged;
		name = mob.name;
		return *this;

	}

	bool isDead() {
		if (hp <= 0) return true;
		return false;
	}

	int getHealth() {
		return this->hp;
	}

	std::string getName() {
		return this->name;
	}

	void takeDamage(int damage) {

			this->hp = this->hp - damage;

	}

	void run() {
		if (this->hp <= 5) {

		}
	}

};

class Zombie : public Mobs {

public:

	void attack(Player* curentPlayer) {

		curentPlayer->takeDamage(this->damage);

	}

	Zombie();

};

class Creeper : public Mobs {

public:

	void attack(Player* curentPlayer) {

		curentPlayer->takeDamage(this->damage);
		this->takeDamage(this->hp);
	}

	Creeper();

};
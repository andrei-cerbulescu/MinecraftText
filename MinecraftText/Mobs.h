#pragma once
#include <string>

class Mobs
{
protected:
	int hp, damage;
	bool diesOnAttack = false, isRanged = false;
	std::string name = "Nothing";

public:

	Mobs();

	Mobs(const Mobs& toBeCopied);

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

	void run() {
		if (this->hp <= 5) {

		}
	}

};

class Zombie : public Mobs {

public:

	Zombie();

};

class Creeper : public Mobs {

public:

	Creeper();

};
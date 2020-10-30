#pragma once
class Mobs
{
protected:
	int hp, damage;
	bool diesOnAttack = false;

public:

	Mobs();

	Mobs(const Mobs& toBeCopied);

	bool isDead() {
		if (hp <= 0) return true;
		return false;
	}

	void run() {
		if (this->hp <= 5) {

		}
	}

};

class Zombie : Mobs {

public:

	Zombie();



};
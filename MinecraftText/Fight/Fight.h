#pragma once
#include "../Player.h"
#include "../Mobs.h"
#include <iostream>
#include <vector>
#include "../Player.h"

static std::vector<Mobs*> mobTypesList;

class Fight {
private:

	std::vector<Mobs*> fightMobsVector;
	Player* fightPlayer;

	void generateMobs() {

		int numberOfMobs = rand() % 3 + 1;

		for (int i = 0; i < numberOfMobs; i++) {

			Zombie* temp = new Zombie();

			fightMobsVector.push_back(temp);

		}

	}

public:
	Fight(Player *player1);

	void printMobsWithHP() {
		for (unsigned int i = 0; i < this->fightMobsVector.size(); i++) {

			std::cout << i + 1 << "." << this->fightMobsVector.at(i)->getName() << " has " << this->fightMobsVector.at(i)->getHealth() << "HP\n";

		}
	}

	void fightFunction() {

		this->printMobsWithHP();

		while (!fightMobsVector.empty()) {

			this->awaitPlayerInput();

		}

	}

	void awaitPlayerInput() {

		std::cout << "1.Hit\n2.Eat\n3.Run\n";
		int decission;
		std::cin >> decission;

		try {

			if (fightPlayer->isDead() == true) {
				throw 21;
			}

			switch (decission) {
			case 1:
				this->hitFunction();
				break;

			case 2:
				this->eatFunction();
				break;

			case 3:
				this->runFunction();
				break;

			default:
				std::cout << "Invalid Input";
				break;

			}
		}
			
		catch (int excep) {
			
			std::cout << "Oh no! You tried to do something but ran into exception " << excep << '\n';

		}

		}

	void hitFunction() {

		std::cout << "Which mob do you want to hit?\n";

		unsigned int numberOfMob;

		while (true) {

			this->printMobsWithHP();
			std::cin >> numberOfMob;

			if (this->fightMobsVector.size() >= numberOfMob && numberOfMob >= 1) {
				
				break;

			}
			
			std::cout << "Invalid input!\n";

		}

		this->fightMobsVector.at(numberOfMob - 1)->takeDamage(this->fightPlayer->getDamage());
		if (this->fightMobsVector.at(numberOfMob - 1)->getHealth() <= 0) {
			delete this->fightMobsVector.at(numberOfMob - 1);
			this->fightMobsVector.erase(this->fightMobsVector.begin() + numberOfMob - 1);
		}

	}

	void eatFunction() {

	}

	void runFunction() {

	}

};
#pragma once
#include "../Player.h"
#include "../Mobs.h"
#include <iostream>
#include <vector>
#include <string>
#include "../Player.h"
#include "../FightLogger.h"

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


		std::cout << "1.Hit\n2.Eat\n3.Run\n4.Print all combat log\n";

		
		int printedHearts = fightPlayer->getHP() / 2;

		bool hasHalfHeart = fightPlayer->getHP() % 2;

		for (int i = 0; i < printedHearts; i++) {

			std::cout << "<3 ";
		}

		if (hasHalfHeart) {
			std::cout << "<";
		}

		std::cout << "\n";

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

			case 4:
				std::cout << "\n";
				for (int i = 0; i < FightLogger::getInstance()->getLog().size(); i++) {

					std::cout << FightLogger::getInstance()->getLog().at(i) << "\n";

				}
				std::cout << "\n";
				break;

			default:
				std::cout << "Invalid Input";
				break;

			}

			
		}
			
		catch (int excep) {
			
			std::cout << "Oh no! You tried to do something but ran into exception " << excep << '\n';

		}

		getAttacked();

		}

	void getAttacked() {
	
		for (int i = 0; i < fightMobsVector.size(); i++) {

			fightPlayer->takeDamage(fightMobsVector.at(i)->getDamage());

			FightLogger::getInstance()->addLogEntry("A " + fightMobsVector.at(i)->getName() + " hit you for " + std::to_string(fightMobsVector.at(i)->getDamage())+" damage!");

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

		FightLogger::getInstance()->addLogEntry("You've hit a " + this->fightMobsVector.at(numberOfMob - 1)->getName() + " for " + std::to_string(this->fightPlayer->getDamage()) + " damage!");
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
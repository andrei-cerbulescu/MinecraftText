#pragma once
#include <string>
#include <iostream>


class Item {

protected:
	int stackSize;
	int bonusDamage;
	bool isBreakable;
	int durability;
	bool isEdible;
	int saturation;
	std::string name;

public:
	Item();
	
	bool isDepleted() {

		if (isBreakable == true && durability <= 0) {
			return(true);
		}

		else {
			return(false);
		}

	}

	int getSaturation() {
		return this->saturation;
	}

	int getBonusDamage() {
		return bonusDamage;
	}

	std::string getItemName(){
		return(this->name);
	}

	int getStackSize() {
		return(this->stackSize);
	}

	bool getIsEdible() {
		return(this->isEdible);
	}

};

class Nothing : public Item {

private:

public:

	Nothing();

};

class Stone : public Item {

private:

public:
	Stone();

};

class Iron : public Item {
private:

public:
	Iron();

};

class Sword : public Item {

private:

public:
	Sword();
};


class Wood : public Item {
private:

public:
	Wood();
};

class Apple : public Item {
private:

public:
	Apple();
};
#pragma once
#include <string>
#include <iostream>


class Item {

protected:
	int stackSize;
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

	std::string getItemName(){
		return(this->name);
	}

	int getStackSize() {
		return(this->stackSize);
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
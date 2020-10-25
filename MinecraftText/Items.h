#include <string.h>
#include <iostream>

class Item {

protected:
	int stackSize;
	char name[50];
	bool isBreakable;
	int durability;

public:
	bool isDepleted() {

		if (isBreakable == true && durability <= 0) {
			return(true);
		}

		else {
			return(false);
		}

	}

};

class Stone : Item {

private:

public:
	Stone() {

		this->stackSize = 64;
		strcpy_s(this->name, "Stone");
		this->isBreakable = false;
		this->durability = -1;

	}

};

class Sword : Item {

private:

public:
	Sword() {

		this->stackSize = 1;
		strcpy_s(this->name, "Sword");
		this->isBreakable = true;
		this->durability = -1;

	}
};
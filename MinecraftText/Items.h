#include <string.h>
#include <iostream>

#ifndef AAA_HEADER
#define AAA_HEADER
//^Inteleg de ce dar totusi simt nevoia sa intreb: de ce??

class Item {

protected:
	int stackSize;
	bool isBreakable;
	int durability;
	bool isEdible;
	int saturation;

public:
	Item();
	char name[50];

	bool isDepleted() {

		if (isBreakable == true && durability <= 0) {
			return(true);
		}

		else {
			return(false);
		}

	}

	char *getItemName(){
		return(this->name);
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

class Sword : public Item {

private:

public:
	Sword();
};

#endif
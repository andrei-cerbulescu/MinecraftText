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
	char name[50];

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

	char *getItemName(){
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

#endif
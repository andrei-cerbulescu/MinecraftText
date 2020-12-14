#include <iostream>
#include "./Player.h"
#include "decision.h"

int main()
{
    srand((unsigned int)time(NULL));

    Player *player1 = new Player();
    decisionFunction(player1);
    delete player1;

    return 0;
}


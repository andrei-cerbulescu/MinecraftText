#include <iostream>
#include "./Player.h"
#include "decision.h"
#include "FightLogger.h"

int main()
{
    srand((unsigned int)time(NULL));

    Player *player1 = new Player();
    decisionFunction(player1);
    delete player1;
    delete FightLogger::getInstance();

    return 0;
}


#ifndef GAME_H
#define GAME_H

#include "code.h"

class Game {
private:
    Code secret;
    int maxTries;

public:
    Game(int tries = 10);
    void run();
};

#endif

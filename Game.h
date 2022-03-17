#pragma once
#include "Util.h"

class Game
{
public:
    array<array<uc, WIDTH>, WIDTH> state;
    string path;
    char dir;
    int depth;
    pair<uc, uc> blank_position;
    Game(array<array<uc, WIDTH>, WIDTH> state, char dir, int depth, string path, pair<uc, uc> blank_position);
};
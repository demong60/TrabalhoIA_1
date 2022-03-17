#pragma once
#include <bits/stdc++.h>
#include "Util.h"
using namespace std;

class Game
{
public:
    array<array<uc, WIDTH>, WIDTH> mat;
    string path;
    char dir;
    int depth;
    pair<uc, uc> blank_pos;

    Game(array<array<uc, WIDTH>, WIDTH> mat, char dir, int depth, string path, pair<uc, uc> blank_pos);
};
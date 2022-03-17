#include "Util.h"
#include "Game.h"

array<array<uc, 4>, 4> mat;
static vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
pair<uc, uc> blankPosition;

Game::Game(array<array<uc, 4>, 4> mat, char dir, int depth, string path, pair<uc, uc> blank_pos)
{
    this->mat = mat;
    this->dir = dir;
    this->depth = depth;
    this->path = path;
    this->blank_pos = blank_pos;
}
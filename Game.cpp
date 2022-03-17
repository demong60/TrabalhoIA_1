#include "Util.h"
#include "Game.h"

array<array<uc, 4>, 4> state;
pair<uc, uc> blankPosition;

Game::Game(array<array<uc, 4>, 4> state, char dir, int depth, string path, pair<uc, uc> blank_position)
{
    this->state = state;
    this->dir = dir;
    this->depth = depth;
    this->path = path;
    this->blank_position = blank_position;
}
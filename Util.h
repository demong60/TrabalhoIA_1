#pragma once
#include <bits/stdc++.h>

using namespace std;
#define WIDTH 4
#define uc unsigned char

#include "Game.h"

namespace Util
{
    /**
     * @brief Returns a hash uniquely corresponding to the given config.
     * @param config
     * @return long long
     */
    long long Hash(array<array<uc, 4>, 4> &config);

    /**
     * @brief Returns a char corresponding to the direction of the move given.
     *
     * @param move
     * @return char
     */
    char Dir(pair<uc, uc> &move);

    /**
     * @brief Creates all the children of current_game and inserts it in out_children
     *
     * @param current_game
     * @param out_children
     */
    void CreateChildren(Game &current_game, vector<Game> &out_children);

    /**
     * @brief Reads a game state from standard input, and inserts it in mat
     *
     * @param out_mat
     */
    void Read(array<array<uc, WIDTH>, WIDTH> &out_mat);

    /**
     * @brief Prints out a game in a very beautyfull way :3
     *
     * @param game
     */
    void Print(array<array<uc, WIDTH>, WIDTH> &game);

    /**
     * @brief Given the initial game, and the path taken to the solution, prints the solution to the game.
     *
     * @param initial
     * @param path
     */
    void PrintDirections(Game &initial, string &path);

    /**
     * @brief When a branch is no longer needed, this function updates the game matrix and removes the needed
     * moves from the path
     *
     * @param mat
     * @param wrong_path
     * @param blank_pos
     */
    void RemoveBranch(array<array<uc, WIDTH>, WIDTH> &mat, string &wrong_path, pair<uc, uc> &blank_pos);

    /**
     * @brief Updates the game matrix to represent every new move made
     *
     * @param mat
     * @param direction
     * @param blank_pos
     */
    void UpdatePath(array<array<uc, WIDTH>, 4> &mat, char direction, pair<uc, uc> &blank_pos);

}

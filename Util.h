#pragma once
#include <bits/stdc++.h>

using namespace std;
#define WIDTH 4
#define uc unsigned char

#include "Game.h"
#include "Algorithms.h"

namespace Util
{
    /**
     * @brief Returns a hash uniquely corresponding to the given config.
     * @param config
     * @return long long
     */
    long long Hash(array<array<uc, WIDTH>, WIDTH> &config);

    /**
     * @brief Converts a given move, to the corresponding direction.
     *
     * @param move
     * @return char
     */
    char MoveToDirection(pair<int, int> &move);

    /**
     * @brief Creates all the children of current_game and inserts it in out_children
     *
     * @param current_game
     * @param out_children
     */
    void CreateChildren(Game &current_game, vector<Game> &out_children);

    /**
     * @brief Reads a game state from standard input, and inserts it in state
     *
     * @param out_state
     */
    array<array<uc, WIDTH>, WIDTH> Read();

    /**
     * @brief Prints out a game in a very beautiful way <3
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
    void PrintDirections(Game &initial, string &path, set<long long> &visited);

    /**
     * @brief When a branch is no longer needed, this function updates the game state and removes the needed
     * moves from the path
     *
     * @param state
     * @param wrong_path
     * @param blank_pos
     */
    void RemoveBranch(array<array<uc, WIDTH>, WIDTH> &state, string &wrong_path, pair<uc, uc> &blank_positon, set<long long> &visited);

    /**
     * @brief Updates the game state to represent every new move made
     *
     * @param state
     * @param direction
     * @param blank_pos
     */
    void UpdatePath(array<array<uc, WIDTH>, WIDTH> &state, char direction, pair<uc, uc> &blank_positon, set<long long> &visited);

    /**
     * @brief
     *
     */
    void UpdateState(Game &game, string &directions, array<array<uc, WIDTH>, WIDTH> &current_state, pair<uc, uc> &blank_position, set<long long> &visited);

    /**
     * @brief Get the Blank Position object
     *
     * @param state
     * @return pair<uc, uc>
     */
    pair<uc, uc> GetBlankPosition(array<array<uc, WIDTH>, WIDTH> &state);

    /**
     * @brief
     *
     * @param pos1
     * @param pos2
     * @return int
     */
    int ManhattanDistance(pair<int, int> &pos1, pair<int, int> &pos2);

    /**
     * @brief Create a Map object
     *
     * @param map
     * @param game
     */
    void CreateMap(map<int, pair<int, int>> &out_map, Game &game);

    /**
     * @brief
     *
     * @param game1
     * @param game2
     * @return int
     */
    int CalculateManhattanDistance(Game &game1, Game &game2);

    /**
     * @brief
     *
     * @param game1
     * @param game2
     * @return int
     */
    int CalculateMisplaced(Game &game1, Game &game2);

    /**
     * @brief
     *
     */
    int CountInversions(Game &game);

    /**
     * @brief
     *
     */
    bool CheckSolvability(Game &initial_game, Game &final_game);
}

#pragma once
#include "Util.h"

namespace Algorithms
{
    /**
     * @brief
     *
     * @param initial
     * @param depth
     * @return true
     * @return false
     */
    bool DFS(Game &initial_game, Game &final_game, int depth);

    /**
     * @brief
     *
     * @param initial
     */
    void IDFS(Game &initial_game, Game &final_game);

    /**
     * @brief
     *
     * @param initial_game
     * @param final_game
     */
    void BFS(Game &initial_game, Game &final_game);

    /**
     * @brief
     *
     * @param initial_game
     * @param final_game
     * @param heuristicFunction
     */
    void AStar(Game &initial_game, Game &final_game, int (*heuristicFunction)(Game &initial_game, Game &final_game));

    /**
     * @brief
     *
     */
    void Greedy(Game &initial_game, Game &final_game, int (*heuristicFunction)(Game &initial_game, Game &final_game));
}

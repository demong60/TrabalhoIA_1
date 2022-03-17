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
}

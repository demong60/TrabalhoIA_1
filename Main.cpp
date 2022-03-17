#include "Util.h"
#include <bits/stdc++.h>

int main()
{
    array<array<uc, WIDTH>, WIDTH> initial_state = Util::Read();
    Game initial_game(initial_state, ' ', 0, "", Util::GetBlankPosition(initial_state));

    array<array<uc, WIDTH>, WIDTH> final_state = Util::Read();
    Game final_game(final_state, ' ', -1, "", Util::GetBlankPosition(final_state));

    Algorithms::IDFS(initial_game, final_game);

    return 0;
}
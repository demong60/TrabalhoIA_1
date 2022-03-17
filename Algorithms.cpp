#include "Util.h"

bool Algorithms::DFS(Game &initial_game, Game &final_game, int depth)
{
    stack<Game> stack;
    stack.push(initial_game);
    string directions = "";
    pair<uc, uc> blank_position = initial_game.blank_position;

    array<array<uc, WIDTH>, WIDTH> current_state;
    current_state = initial_game.state;

    set<long long> visited;

    while (!stack.empty())
    {
        Game current_game = stack.top();
        stack.pop();

        Util::UpdateState(current_game, directions, current_state, blank_position, visited);

        if (Util::Hash(current_state) == Util::Hash(final_game.state))
        {
            Util::PrintDirections(initial_game, directions, visited);
            return true;
        }
        vector<Game> children;
        // if (current_game.depth == depth + 1)
        //     return false;
        if (current_game.depth < depth)
            Util::CreateChildren(current_game, children);

        for (Game child : children)
        {
            if (visited.find(Util::Hash(child.state)) == visited.end())
            {
                child.path.clear();
                stack.push(child);
            }
        }
    }
    return false;
}

void Algorithms::IDFS(Game &initial, Game &final)
{
    int i = 0;
    cout << "Currently exploring depth 0\n";
    while (!DFS(initial, final, i))
    {
        cout << "Currently exploring depth " << (++i) << '\n';
    }
}
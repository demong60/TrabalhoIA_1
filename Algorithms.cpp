#include "Util.h"

struct Comparator
{ // comparator for min-heap (A star)
    constexpr bool operator()(pair<Game, int> &game1, pair<Game, int> &game2)
        const noexcept
    {
        return (game1.second > game2.second);
    }
};

bool Algorithms::LDFS(Game &initial_game, Game &final_game, int depth)
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
        visited.insert(Util::Hash(current_game.state));

        if (Util::Hash(current_state) == Util::Hash(final_game.state))
        {
            directions.erase(0, 1);
            Util::PrintDirections(initial_game, directions, visited);
            return true;
        }
        vector<Game> children;
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
    while (!LDFS(initial, final, i))
    {
        cout << "Currently exploring depth " << (++i) << '\n';
    }
}

void Algorithms::BFS(Game &initial_game, Game &final_game)
{
    queue<Game> queue;
    set<long long> visited;
    queue.push(initial_game);
    int count = 0;
    while (queue.size())
    {
        Game current_game = queue.front();
        queue.pop();
        ++count;

        visited.insert(Util::Hash(current_game.state));

        if (Util::Hash(current_game.state) == Util::Hash(final_game.state))
        {
            Util::PrintDirections(initial_game, current_game.path, visited);
            return;
        }
        vector<Game> children;
        Util::CreateChildren(current_game, children);
        for (auto child : children)
        {
            if (visited.find(Util::Hash(child.state)) == visited.end())
            {
                // Game hasn't been visited before
                queue.push(child);
            }
        }
    }
}

void Algorithms::AStar(Game &initial_game, Game &final_game, int (*heuristicFunction)(Game &, Game &))
{
    // Min-heap
    priority_queue<pair<Game, int>, vector<pair<Game, int>>, Comparator> heap;
    set<long long> visited;

    heap.push(make_pair(initial_game, heuristicFunction(initial_game, final_game))); // Depth 0
    visited.insert(Util::Hash(initial_game.state));

    while (!heap.empty())
    {
        pair<Game, int> current_game = heap.top();
        heap.pop();

        visited.insert(Util::Hash(current_game.first.state));

        if (Util::Hash(current_game.first.state) == Util::Hash(final_game.state))
        {
            Util::PrintDirections(initial_game, current_game.first.path, visited);
            return;
        }

        vector<Game> children;
        Util::CreateChildren(current_game.first, children);
        for (Game child : children)
        {
            if (visited.find(Util::Hash(child.state)) == visited.end())
            {
                int heuristic = heuristicFunction(child, final_game);
                heap.push(make_pair(child, heuristic + child.depth));
            }
        }
    }
}

void Algorithms::Greedy(Game &initial_game, Game &final_game, int (*heuristicFunction)(Game &, Game &))
{
    // Min-heap
    priority_queue<pair<Game, int>, vector<pair<Game, int>>, Comparator> heap;
    set<long long> visited;

    heap.push(make_pair(initial_game, heuristicFunction(initial_game, final_game))); // Depth 0
    visited.insert(Util::Hash(initial_game.state));

    while (!heap.empty())
    {
        pair<Game, int> current_game = heap.top();
        heap.pop();

        visited.insert(Util::Hash(current_game.first.state));

        if (Util::Hash(current_game.first.state) == Util::Hash(final_game.state))
        {
            Util::PrintDirections(initial_game, current_game.first.path, visited);
            return;
        }

        vector<Game> children;
        Util::CreateChildren(current_game.first, children);
        for (Game child : children)
        {
            if (visited.find(Util::Hash(child.state)) == visited.end())
            {
                int heuristic = heuristicFunction(child, final_game);
                heap.push(make_pair(child, heuristic));
            }
        }
    }
}
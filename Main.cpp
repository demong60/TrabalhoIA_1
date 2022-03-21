#include "Util.h"
#include <bits/stdc++.h>
bool Run(Game &initial_game, Game &final_game)
{
    system("clear");

    cout << "Please choose algorithm to use: \n";
    cout << "\t1: DFS\n";
    cout << "\t2: BFS\n";
    cout << "\t3: IDFS\n";
    cout << "\t4: Greedy - Misplaced Tiles Heuristic\n";
    cout << "\t5: Greedy - Manhattan Distance Heuristic\n";
    cout << "\t6: A* - Misplaced Tiles Heuristic\n";
    cout << "\t7: A* - Manhattan Distance Heuristic\n";
    int alg;
    cin >> alg;

    switch (alg)
    {
    case 1:
        Algorithms::BFS(initial_game, final_game);
        break;
    case 2:
        Algorithms::BFS(initial_game, final_game);
        break;
    case 3:
        Algorithms::IDFS(initial_game, final_game);
        break;
    case 4:
        Algorithms::Greedy(initial_game, final_game, Util::CalculateMisplaced);
        break;
    case 5:
        Algorithms::Greedy(initial_game, final_game, Util::CalculateManhattanDistance);
        break;
    case 6:
        Algorithms::AStar(initial_game, final_game, Util::CalculateMisplaced);
        break;
    case 7:
        Algorithms::AStar(initial_game, final_game, Util::CalculateManhattanDistance);
        break;
    }

    cout << "\n\n\n\n============\n\nDo you want to run another algorithm?\n";
    cout << "0: No\n";
    cout << "1: Yes\n";
    int ans;
    cin >> ans;
    return ans;
}

int main(int argc, char **argv)
{
    array<array<uc, WIDTH>, WIDTH> initial_state = Util::Read();
    Game initial_game(initial_state, ' ', 0, "", Util::GetBlankPosition(initial_state));

    array<array<uc, WIDTH>, WIDTH> final_state = Util::Read();
    Game final_game(final_state, ' ', -1, "", Util::GetBlankPosition(final_state));

    // Redirecionar o stdin de volta para o terminal
    FILE *tty = freopen("/dev/tty", "r", stdin);
    if (tty == NULL)
    {
        perror("Unable to open terminal for reading");
        exit(1);
    }

    if (!Util::CheckSolvability(initial_game, final_game))
    {
        cout << "Impossible configurations.\n";
        return -1;
    }

    while (Run(initial_game, final_game))
        ;

    system("clear");
    cout << "Thank you :)\n";
    cout << "Created by: \n";
    cout << "\tMarco Gonçalves\n";
    cout << "\tKlara Varga\n";
    cout << "\tHugo Cardante\n";

    return 0;
}

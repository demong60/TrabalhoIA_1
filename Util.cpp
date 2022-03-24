#include "Util.h"

static vector<pair<int, int>> moves = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

long long Util::Hash(array<array<uc, WIDTH>, WIDTH> &config)
{
    long long hash = 0, multiplier = 1;
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            hash += multiplier * (long long)config[i][j];
            multiplier *= 10;
        }
    }
    return hash;
}

char Util::MoveToDirection(pair<int, int> &move)
{
    if (move.first == -1)
        return 'U';
    else if (move.first == 1)
        return 'D';
    else if (move.second == -1)
        return 'L';
    else
        return 'R';
}

void Util::CreateChildren(Game &current_game, vector<Game> &out_children)
{
    for (pair<int, int> move : moves)
    {
        int new_y = move.first + current_game.blank_position.first;
        int new_x = move.second + current_game.blank_position.second;
        if (new_x > 3 || new_x < 0 || new_y > 3 || new_y < 0)
            continue;

        swap(current_game.state[new_y][new_x], current_game.state[current_game.blank_position.first][current_game.blank_position.second]);

        Game child(current_game.state, MoveToDirection(move), current_game.depth + 1, current_game.path + MoveToDirection(move), make_pair(new_y, new_x));
        out_children.push_back(child);

        // Undo the move
        swap(current_game.state[new_y][new_x], current_game.state[current_game.blank_position.first][current_game.blank_position.second]);
    }
}

array<array<uc, WIDTH>, WIDTH> Util::Read()
{
    array<array<uc, WIDTH>, WIDTH> state;
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            int n = scanf("%hhu", &state[row][col]);
        }
    }
    return state;
}

void Util::Print(array<array<uc, WIDTH>, WIDTH> &game)
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (game[row][col] < 10)
                cout << ' ';
            cout << static_cast<int>(game[row][col]) << ' ';
        }
        cout << '\n';
    }
    cout << "============\n";
}

void Util::PrintDirections(Game &initial, string &path, int explored, int max_depth)
{
    int size = (int)path.size();
    pair<int, int> blank_position = initial.blank_position;

    array<array<uc, WIDTH>, WIDTH> current_config = initial.state;
    Print(current_config);

    int y = blank_position.first, x = blank_position.second;
    for (int i = 0; i < size; ++i)
    {
        switch (path[i])
        {
        case ' ':
            continue;
            break;
        case 'U':
            swap(current_config[y][x], current_config[y - 1][x]);
            y--;
            break;
        case 'D':
            swap(current_config[y][x], current_config[y + 1][x]);
            y++;
            break;
        case 'L':
            swap(current_config[y][x], current_config[y][x - 1]);
            x--;
            break;
        default:
            swap(current_config[y][x], current_config[y][x + 1]);
            x++;
            break;
        }

        Print(current_config);
    }

    cout << "Solution found:  " << '\n'
         << "\tDepth: " << size << '\n'
         << "\tTotal explored states: " << explored << '\n'
         << "\tMax reached depth: " << max_depth << '\n';
}

void Util::RemoveBranch(array<array<uc, WIDTH>, WIDTH> &state, string &wrong_path, pair<uc, uc> &blank_position, set<long long> &visited)
{
    int size = (int)wrong_path.length();
    for (int i = 0; i < size; ++i)
    {
        // to remove from hash_set
        visited.erase(Hash(state));
        int y = blank_position.first;
        int x = blank_position.second;

        switch (wrong_path[i])
        {
        case ' ':
            continue;
            break;
        case 'D':
            swap(state[y][x], state[y - 1][x]);
            blank_position.first--;
            break;
        case 'U':
            swap(state[y][x], state[y + 1][x]);
            blank_position.first++;
            break;
        case 'R':
            swap(state[y][x], state[y][x - 1]);
            blank_position.second--;
            break;
        default:
            swap(state[y][x], state[y][x + 1]);
            blank_position.second++;
            break;
        }
    }
}

void Util::UpdatePath(array<array<uc, WIDTH>, WIDTH> &state, char direction, pair<uc, uc> &blank_positon, set<long long> &visited)
{
    int y = blank_positon.first, x = blank_positon.second;

    switch (direction)
    {
    case ' ':
        break;
    case 'U':
        swap(state[y][x], state[y - 1][x]);
        blank_positon.first--;
        break;
    case 'D':
        swap(state[y][x], state[y + 1][x]);
        blank_positon.first++;
        break;
    case 'L':
        swap(state[y][x], state[y][x - 1]);
        blank_positon.second--;
        break;
    default:
        swap(state[y][x], state[y][x + 1]);
        blank_positon.second++;
        break;
    }
}

void Util::UpdateState(Game &game, string &directions, array<array<uc, WIDTH>, WIDTH> &current_state, pair<uc, uc> &blank_position, set<long long> &visited)
{
    string wrong_path = directions.substr(game.depth, directions.size());
    reverse(wrong_path.begin(), wrong_path.end());

    RemoveBranch(current_state, wrong_path, blank_position, visited);
    UpdatePath(current_state, game.dir, blank_position, visited);

    // Delete the wrong path from the string - if applicable
    directions.erase(directions.begin() + game.depth, directions.end());

    // Adds the current direction
    directions += game.dir;
}

pair<uc, uc> Util::GetBlankPosition(array<array<uc, WIDTH>, WIDTH> &state)
{
    pair<uc, uc> blank_position;
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (state[row][col] == 0)
            {
                blank_position.first = row;
                blank_position.second = col;
                return blank_position;
            }
        }
    }
    return blank_position;
}

int Util::ManhattanDistance(pair<int, int> &pos1, pair<int, int> &pos2)
{
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

void Util::CreateMap(map<int, pair<int, int>> &out_map, Game &game)
{
    for (int row = 0; row < WIDTH; ++row)
    {
        for (int col = 0; col < WIDTH; ++col)
        {
            out_map[game.state[row][col]] = make_pair(row, col);
        }
    }
}

int Util::CalculateManhattanDistance(Game &game1, Game &game2)
{
    map<int, pair<int, int>> map1, map2;
    // criar os mapas
    CreateMap(map1, game1);
    CreateMap(map2, game2);

    int distance = 0;
    for (int row = 0; row < WIDTH; ++row)
    {
        for (int col = 0; col < WIDTH; ++col)
        {
            distance += ManhattanDistance(map1[game1.state[row][col]], map2[game1.state[row][col]]);
        }
    }
    return distance;
}

int Util::CalculateMisplaced(Game &game1, Game &game2)
{
    int misplaced = 0;
    for (int row = 0; row < WIDTH; ++row)
    {
        for (int col = 0; col < WIDTH; ++col)
        {
            misplaced += (game1.state[row][col] != game2.state[row][col]);
        }
    }
    return misplaced;
}

int Util::CountInversions(Game &game)
{
    vector<unsigned char> arr;
    // Convert to a vector for easier readability
    for (int row = 0; row < WIDTH; row++)
        for (int col = 0; col < WIDTH; col++)
            arr.push_back(game.state[row][col]);

    int inversions = 0;
    for (int i = 0; i < WIDTH * WIDTH; i++)
    {
        for (int j = i + 1; j < WIDTH * WIDTH; j++)
        {
            if (arr[i] > arr[j] && arr[j] != 0)
                inversions++;
        }
    }

    return inversions;
}

bool Util::CheckSolvability(Game &initial_game, Game &final_game)
{
    int inv_i = CountInversions(initial_game);
    int inv_f = CountInversions(final_game);

    bool cond_i = ((inv_i % 2 == 0) == (initial_game.blank_position.first % 2 == 1));
    bool cond_f = ((inv_f % 2 == 0) == (final_game.blank_position.first % 2 == 1));

    return (cond_i == cond_f);
}
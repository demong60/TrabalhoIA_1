#include "Util.h"
#include <bits/stdc++.h>

int main()
{
    array<array<uc, 4>, 4> mat = {{'1', '2', '3', '4'}};
    pair<int, int> blankPos = make_pair(1, 1);
    Game g(mat, ' ', 0, "", blankPos);

    cout << "o23la\n";
    return 0;
}
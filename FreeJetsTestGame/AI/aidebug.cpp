#include "ai.h"

using namespace ai;
using namespace std;

void aidebug::DebugPlane (int mi, int mj, const char in[], const char log[]) {
    ReadMatrix(in);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            TryPlane (i, j, 0, 1, mi, mj, log);
            TryPlane (i, j, 0, 1, mi, mj, log);
            TryPlane (i, j, 1, 1, mi, mj, log);
            TryPlane (i, j, 1, 1, mi, mj, log);
        }
}

void aidebug::TryPlane (int i, int j, int ok, int m, int mi, int mj, const char s[]) {
    vector<pair<int, int> > positions;
    bool possible = true, log = false;
    for(int k = 0; k < 10; k++) {
        int x = i + p1[ok][k] * m;
        int y = j + p1[!ok][k] * m;

        if (1 <= x && x <= 10 && 1 <= y && y <= 10) {
            if (x == mi && y == mj)
                log = true;
            positions.push_back(make_pair (x, y));
            if (v[x][y] == 1 || (v[i][j] == 3 && k != 6) )
                possible = false;
        }
        else
            possible = false;
    }

    if (!possible)
        positions.clear ();

    #ifdef __AILOG
    if (log && !positions.empty () )
        ailog::log (positions, s);
    #endif
}

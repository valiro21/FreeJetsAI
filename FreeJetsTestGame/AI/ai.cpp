#include "ai.h"

using namespace std;
using namespace ai;

int ai::P;
int ai::p[11][11], ai::v[11][11];
int ai::p1[2][10] = {0, 0, 0, 0, 0,-1, 1, 2, 2, 2, -2, -1, 0, 1, 2, 0, 0, 0, -1, 1};

void ai::clear (const char s[]) {
    ofstream fout (s);
    fout.close ();
}

bool ai::PlacePlane (int i, int j, int ok, int m, int val) {
    bool possible = true;
    for(int k = 0; k < 10; k++) {
        int x = i + p1[ok][k] * m;
        int y = j + p1[!ok][k] * m;

        if (1 <= x && x <= 10 && 1 <= y && y <= 10) {
            p[x][y]+=val;
            if (v[x][y] == 1 || (v[i][j] == 3 && k != 6) )
                possible = false;
        }
        else
            possible = false;
    }

    if (!possible)
        for(int k = 0; k < 10; k++) {
            int x = i + p1[ok][k] * m;
            int y = j + p1[!ok][k] * m;

            if (1 <= x && x <= 10 && 1 <= y && y <= 10)
                p[x][y]-=val;
        }

    return possible;
}

void ai::ReadMatrix (const char s[]) {
    ifstream fin (s);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            fin >> v[i][j];
    fin.close ();
}

void ai::Probability () {
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            P += PlacePlane (i, j, 0, -1, 1);
            P += PlacePlane (i, j, 0, 1, 1);
            P += PlacePlane (i, j, 1, -1, 1);
            P += PlacePlane (i, j, 1, 1, 1);
        }
}


int ai::solve (const char in[], const char out[], const char log[]) {
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            p[i][j] = 0;

    ReadMatrix(in);

    Probability();

    int maxx = 0;
    vector<pair<int, int> > psb;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            if (v[i][j] == 0 && p[i][j] > maxx)
                maxx = p[i][j],
                //cout << maxx << ' ',
                psb.clear (),
                psb.push_back (make_pair (i, j));
            else if (v[i][j] == 0 && p[i][j] == maxx)
                psb.push_back (make_pair (i, j));
        }
    #ifdef __AILOG
    ailog::PrintLogMatrix (log);
    #endif // __AILOG

    srand (time(NULL));
    int x = rand () % psb.size ();


    #ifdef __AILOG
    ailog::log (psb[x], log);
    #endif
    fstream fout;
    fout.open (out,std::fstream::out);
    fout << psb[x].first << ' ' << psb[x].second << '\n';
    fout.close ();

    return 0;
}

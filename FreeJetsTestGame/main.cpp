#include <fstream>
#include <iostream>
#include <assert.h>
#include <windows.h>
#include "AI/ai.h"

using namespace std;

int v[11][11], p[11][11], head = 3, frames, hits;

void ReadMatrix () {
    ifstream fin ("player.in");
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            fin >> v[i][j];
    fin.close ();
}

void WriteMatrix () {
    ofstream fout ("AI/ai.in");
    for (int i = 1; i <= 10; i++, fout << '\n')
        for (int j = 1; j <= 10; j++)
            fout << (p[i][j] == 1 ? v[i][j]+1 : 0) << ' ';
    fout.close ();
}

bool GetHit () {
    int x, y;
    ifstream fin ("AI/ai.out");
    fin >> x >> y;
    fin.close ();

    assert (1 <= x && x <= 10);
    assert (1 <= y && y <= 10);
    assert (p[x][y] == 0);

    p[x][y] = 1;
    if (v[x][y] == 2)
        head--;

    return v[x][y];
}

void Turn () {
    bool hit = true;
    while (hit) {
        WriteMatrix ();
        ai::clear ("ai.out");
        ai::solve("AI/ai.in", "AI/ai.out", "AI/debug.log");
        hit = GetHit ();
        if (hit)
            ailog::log ("hit!", "AI/debug.log");
        hits++;
    }
}


int main()
{
    ReadMatrix();
    while (head > 0) {
        frames++;
        Turn ();
    }

    cout << frames << ' ' << hits << '\n';

    return 0;
}

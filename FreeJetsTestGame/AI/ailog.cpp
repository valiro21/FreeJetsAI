#include "ai.h"

using namespace std;

void ailog::log (vector<pair<int, int> > &v, const char s[]) {
    fstream fout;
    fout.open (s,std::fstream::out | std::fstream::app);
    for (int i = 0; i < v.size (); i++)
        fout << '(' << v[i].first << ',' << v[i].second <<')' << ' ';
    fout << '\n';
    fout.close ();
}

void ailog::log (pair<int, int> v, const char s[]) {
    fstream fout;
    fout.open (s,std::fstream::out | std::fstream::app);
    fout << '(' << v.first << ',' << v.second <<')' << '\n';
    fout.close ();
}

void ailog::log (std::string c, const char s[]) {
    fstream fout;
    fout.open (s,std::fstream::out | std::fstream::app);
    fout << c << '\n';
    fout.close ();
}

void ailog::PrintLogMatrix (const char s[]) {
    fstream fout;
    fout.open (s,std::fstream::out | std::fstream::app);
    for (int i = 1; i <= 10; i++, fout << '\n')
        for (int j = 1; j <= 10; j++) {
            if (ai::p[i][j] < 10)
                fout << ' ';
            fout << ai::p[i][j] << ' ';
        }
    fout << '\n';
    fout.close ();
}

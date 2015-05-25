#ifndef __AI.H
#define __AI.H
//#define __AILOG
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <string>


namespace ailog {
    extern void PrintLogMatrix (const char s[]); //log

    extern void log (std::vector<std::pair<int, int> > &v, const char s[]);

    extern void log (std::pair<int, int> v, const char s[]);

    extern void log (std::string c, const char s[]);
}

namespace ai {
    extern int P;
    extern int p[11][11], v[11][11];
    extern int p1[2][10];

    extern bool PlacePlane (int i, int j, int ok, int m, int val); //test a plane based on rotation

    extern void ReadMatrix (const char s[]);//read configuration

    extern void Probability (); //precalculate statistics

    extern void clear (const char s[]); //clear the screen

    extern int getAvgProbability (int x, int y);

    extern int solve (const char in[], const char out[], const char log[]); //main
}

namespace aidebug {
    extern void DebugPlane(int mi, int mj, const char in[], const char log[]);

    extern void TryPlane(int i, int j, int ok, int m, int mi, int mj, const char s[]);
}

#endif // __AI


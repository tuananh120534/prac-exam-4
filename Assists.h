#ifndef ASSISTS_H
#define ASSISTS_H
#include <tuple>
#include "math.h"
using namespace std;
class Assists{
    public:
    static std::tuple<int, int> createRandomLoc(int matrixWidth, int matrixHeight){
        int x = rand() % (matrixWidth);
        int y = rand() % (matrixHeight);
        tuple<int, int> a = make_tuple(x, y);
        return a;
    }
    static double evaluateDistance(std::tuple<int, int> loc1, std::tuple<int, int> loc2) {
        int disX = get<0>(loc1) - get<0>(loc2);
        int disY = get<1>(loc1) - get<1>(loc2);
        return sqrt(disX*disX + disY*disY);
    }
};
#endif
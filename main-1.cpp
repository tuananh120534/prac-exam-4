#include "Assists.h"
#include <tuple>
#include <iostream>
#include "Influence.h"
#include "Spot.h"
using namespace std;
int main(){
    tuple <int, int> a = Assists::createRandomLoc(3, 2);
    tuple <int, int> b = Assists::createRandomLoc(3, 3);
    int dis = Assists::evaluateDistance(a, b);
    std::cout << dis << std::endl;
}
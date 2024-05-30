#ifndef PERSONA_H
#define PERSONA_H
#include "Spot.h"
using namespace std;
class Persona: public Spot{
    public:
    Persona(int x, int y): Spot(x, y, 'P'){};
    void shift(int dx, int dy){
        this->location = make_tuple (get<0>(location)+dx, get<1>(location) +dy);
    }
};
#endif
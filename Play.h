#ifndef PLAY_H
#define PLAY_H
#include "Snare.h"
#include "Persona.h"
#include "Assists.h"
#include <vector>
class Play{
    private: 
    int _gridWidth;
    int _gridHeight;
    std::vector<Spot*> matrix;
    public: 
    std::vector<Spot*>& getMatrix() {
        return this->matrix;
    }
    void initPlay(int numPersonas, int numSnares, int matrixWidth, int matrixHeight){
        _gridHeight = matrixHeight;
        _gridWidth = matrixWidth;
        for (int i = 0; i < numPersonas; i++){
            tuple<int, int> loc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            Spot *a = new Persona(get<0>(loc), get<1>(loc));
            this->matrix.push_back(a);
        }
        for (int i = 0; i < numSnares; i++){
            tuple<int, int> loc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            Spot *a = new Snare(get<0>(loc), get<1>(loc));
            this->matrix.push_back(a);
        }
    }
    void playCycle(int maxCycles, double snareTriggerDistance){
        bool is_win = false;
        for (int i = 0; i < maxCycles; i++) { 
            for (int k = 0; k < this->matrix.size(); k++){
                if (matrix[k]->getCategory() == 'P'){
                    Persona *persona = static_cast<Persona*>(matrix[k]);
                    persona->shift(1, 0);
                }
            }

            for(int k = 0; k < this->matrix.size(); k++){
                for (int l = 0; l < this->matrix.size(); l++){
                    if (matrix[k]->getCategory() == 'S' && matrix[l]->getCategory() == 'P'){
                        Persona *persona = static_cast<Persona*>(matrix[l]);  
                        Snare *snare = static_cast<Snare*>(matrix[k]); 
                        double dis = Assists::evaluateDistance(persona->getLoc(), snare->getLoc());
                        if (dis <= snareTriggerDistance){
                            snare->implement(*matrix[l]);
                        }
                    }
                }
            } 
            for (int j = 0; j < matrix.size(); j++){
                if (matrix[j]->getCategory() == 'P'){
                    Persona *persona = static_cast<Persona*>(matrix[j]);
                    tuple<int, int> pos = persona->getLoc();
                    if (get<0>(pos) > _gridWidth) {
                        cout << "Persona has won the game!" << endl;
                        is_win = true;
                    }
                }
            }
            if (is_win == true) break;
        }
        if (is_win == false) cout << "Maximum number of cycles reached. Game over." << endl;
    }

};
 
#endif
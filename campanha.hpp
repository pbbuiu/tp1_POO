#ifndef CAMPANHA_H
#define CAMPANHA_H
#include "batalha.hpp"
#include <vector>

using namespace std;

class Campanha{
    vector <Batalha> batalhas;
public:
    void simularBatalhas();
    void gerarTabelasDePosicoes();
    void mostrarUnidadeMaisDestrutiva();
};

#endif //CAMPANHA_H
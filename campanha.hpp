#ifndef CAMPANHA_HPP
#define CAMPANHA_HPP
#include <iostream>
#include <vector>
#include "batalha.hpp"

class Campanha{
    std::vector <Batalha*> batalhas;
public:
    Campanha();
    ~Campanha();
    void simularBatalhas();
    void gerarTabelaPosicoes(std::ostream& out = std::cout);
    void mostrarUnidadeMaisDestrutiva();
    void adicionarBatalha(Batalha* batalha);
};

#endif //CAMPANHA_HPP
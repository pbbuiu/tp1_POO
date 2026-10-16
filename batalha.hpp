#ifndef BATALHA_H
#define BATALHA_H
#include "campanha.hpp"
#include "date.hpp"
#include "exercito.hpp"

class Batalha : public Campanha{
    Data data;
    Exercito *exercitoA;
    Exercito *exercitoB;
    int resultadoA;
    int resultadoB;
public:
    void ataqueExercitoA();
    void ataqueExercitoB();
    string getResultado();
};

#endif //BATALHA_H
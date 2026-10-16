#ifndef UNIDADE_HPP
#define UNIDADE_HPP
#include "exercito.hpp"

class Unidade : public Exercito{
    int poderAtaque;
    int destruicoes;
public:
    virtual int getPoderAtaque() const;
    int somaDestruicao() const;
};

#endif //UNIDADE_HPP
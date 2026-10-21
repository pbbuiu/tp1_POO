#ifndef BATALHA_HPP
#define BATALHA_HPP

#include "exercito.hpp"
#include "date.hpp"

class Batalha{
    Date data;
    Exercito *exercitoA;
    Exercito *exercitoB;
    int resultadoA;
    int resultadoB;
    int placarA;
    int placarB;
public:

    Batalha(Date d, Exercito *a, Exercito *b);
    ~Batalha();

    void ataqueExercitoA();
    void ataqueExercitoB();
    void determinaVencedor();

    std::string getResultado() const;
    Unidade* maiorDestruicaoExercitoA() const;
    Unidade* maiorDestruicaoExercitoB() const;

    Exercito* getExercitoA() const;
    Exercito* getExercitoB() const;
};

#endif //BATALHA_HPP
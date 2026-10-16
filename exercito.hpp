#ifndef EXERCITO_HPP
#define EXERCITO_HPP

#include <iostream>
#include <vector>
#include "unidade.hpp"
#include "batalha.hpp"

using namespace std;

class Exercito : public Batalha{
    string nome;
    vector <Unidade> unidades;
    int vitorias;
    int derrotas;
    int empates;
public:
    void adicionarUnidade(Unidade &u);
    string getResultados();
    void imprimeUnidades();
};

#endif //EXERCITO_HPP
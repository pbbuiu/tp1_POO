#include "unidade.hpp"
#include <iostream>

using namespace std;

Unidade::Unidade(): destruicoes(0), poderAtaque(0){}

void Unidade::somaDestruicao(){
    destruicoes++;
}

int Unidade::getDestruicao() const{
    return destruicoes;
}

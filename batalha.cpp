#include "batalha.hpp"
#include <iostream>

using namespace std;

Batalha::Batalha(Date data, Exercito *exerA, Exercito *exerB): data(data), exercitoA(exerA), exercitoB(exerB), resultadoA(-1), resultadoB(-1), placarA(0), placarB(0){}

Batalha::~Batalha(){}

void Batalha::ataqueExercitoA(){
    exercitoA->randomizarAtributos();
    resultadoA = exercitoA->getPoderAtaqueTotal();
    exercitoA->calcularDestruicoes(*exercitoB);
}

void Batalha::ataqueExercitoB(){
    exercitoB->randomizarAtributos();
    resultadoB = exercitoB->getPoderAtaqueTotal();
    exercitoB->calcularDestruicoes(*exercitoA);
}

string Batalha::getResultado() const{
    return exercitoA->getNome() + " " + to_string(placarA) + " x " + to_string(placarB) + " " + exercitoB->getNome();
}

void Batalha::determinaVencedor(){
    if (resultadoA == -1 || resultadoB == -1){
        cout << "Eh preciso que haja ataques de ambos os lados para determinar vencedores\n";
        return;
    }
    if (resultadoA > resultadoB){
        placarA++;
        exercitoA->somaVitoria();
        exercitoB->somaDerrota();
    }
    else if (resultadoB > resultadoA){
        placarB++;
        exercitoB->somaVitoria();
        exercitoA->somaDerrota();
    }
    else{
        exercitoA->somaEmpate();
        exercitoB->somaEmpate();
    }
    this->getResultado();
}

Unidade* Batalha::maiorDestruicaoExercitoA() const{
    return exercitoA->getMaiorDestruicao();
}
Unidade* Batalha::maiorDestruicaoExercitoB() const{
    return exercitoB->getMaiorDestruicao();
}

Exercito* Batalha::getExercitoA() const{
    return exercitoA;
}

Exercito* Batalha::getExercitoB() const{
    return exercitoB;
}

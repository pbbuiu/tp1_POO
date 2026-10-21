#include "campanha.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Campanha::Campanha(){}

Campanha::~Campanha() {
    for (auto batalha : batalhas)
        delete batalha;
    batalhas.clear();
}

void Campanha::simularBatalhas(){
    if (!batalhas.empty())
        for (auto& batalha : batalhas){
            batalha->ataqueExercitoA();
            batalha->ataqueExercitoB();
            batalha->determinaVencedor();
        }
}

void Campanha::gerarTabelaPosicoes(ostream& out){
    vector <Exercito*> exercitos;
    for (const auto& batalha : batalhas){
        if (find(exercitos.begin(), exercitos.end(), batalha->getExercitoA()) == exercitos.end())
            exercitos.push_back(batalha->getExercitoA());
        if (find(exercitos.begin(), exercitos.end(), batalha->getExercitoB()) == exercitos.end())
            exercitos.push_back(batalha->getExercitoB());
    }
    sort(exercitos.begin(), exercitos.end(), [](const Exercito* a, const Exercito* b){ return a->getVitoria() > b->getVitoria();});
    for (const auto& exercito : exercitos)
        out << exercito->getNome() << " " << exercito->getResultados() << endl;
}

void Campanha::mostrarUnidadeMaisDestrutiva(){
    if (batalhas.empty()){
        cout << "Não existe nenhuma batalha" << endl;
        return;
    }
    //Inicializo com uma das unidades do exercitoA
    //da primeira batalha para não correr o risco de acessar um endereço inválido
    Unidade* unidadeMaisDestrutiva = batalhas[0]->maiorDestruicaoExercitoA();
    //Olha todos os exercitos A e B de todas as batalhas e os compara 
    for (const auto& batalha : batalhas){
            if(batalha->maiorDestruicaoExercitoA()->getDestruicao() > unidadeMaisDestrutiva->getDestruicao())
                unidadeMaisDestrutiva = batalha->maiorDestruicaoExercitoA();
            if (batalha->maiorDestruicaoExercitoB()->getDestruicao() > unidadeMaisDestrutiva->getDestruicao())
                unidadeMaisDestrutiva = batalha->maiorDestruicaoExercitoB();
    }
    unidadeMaisDestrutiva->imprimiUnidade();
}

void Campanha::adicionarBatalha(Batalha* batalha){
    batalhas.push_back(batalha);
}

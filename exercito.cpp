#include "exercito.hpp"
#include <iostream>

using namespace std;

Exercito::Exercito(string n): nome(n), vitorias(0), derrotas(0), empates(0){}

//Desaloca toda a memória usada para armazenar as unidades
Exercito::~Exercito(){
    for (auto it : unidades)
        delete it; 
    unidades.clear(); //Esvazia o vetor
}

//Adiciona ao final do vetor de unidades
void Exercito::adicionarUnidade(Unidade* u){
    this->unidades.push_back(u); 
}

//Imprimirá o histórico de batalhas do exército
string Exercito::getResultados() const{
    return "Vitorias: " + to_string(vitorias) + " Derrotas: " + to_string(derrotas) + " Empates: " + to_string(empates);
}

//Imprimirá as unidades que o exército é composto
void Exercito::imprimeUnidades(){
    for (Unidade* it : unidades)
        it->imprimiUnidade();
}   

int Exercito::getPoderAtaqueTotal() const{
    int poderAtaqueTotal = 0;
    for (Unidade* it : unidades)
        poderAtaqueTotal = it->getPoderAtaque();
    return poderAtaqueTotal;
}

void Exercito::calcularDestruicoes(Exercito& outroExercito){
    for (int i=0; i<5; i++){
        //As destruições são calculadas competindo Unidade contra Unidade respectivamente
        if (unidades[i]->getPoderAtaque() > outroExercito.unidades[i]->getPoderAtaque())
            unidades[i]->somaDestruicao();
    }
}

std::string Exercito::getNome(){
    return nome;
}

void Exercito::somaVitoria(){
    vitorias++;
}

void Exercito::somaDerrota(){
    derrotas++;
}

void Exercito::somaEmpate(){
    empates++;
}

Unidade* Exercito::getMaiorDestruicao() const{
    int maiorDestruicao = 0;
    for (int i=0; i<5; i++)
        if (unidades[i]->getDestruicao() > unidades[maiorDestruicao]->getDestruicao())
            maiorDestruicao = i;
    return unidades[maiorDestruicao];
}

void Exercito::mostrarUnidadeMaisDestrutiva() const{
    int maisDestrutiva = 0;
    for (int i=0; i<5; i++)
        if (unidades[i]->getDestruicao() > unidades[maisDestrutiva]->getDestruicao())
            maisDestrutiva = i;
    unidades[maisDestrutiva]->imprimiUnidade();
}

int Exercito::getVitoria() const{
    return vitorias;
}

void Exercito::randomizarAtributos(){
    for (auto& unidade : unidades)
        unidade->gerarAtributos();
}
#include "infantaria.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Infantaria::Infantaria(): Unidade(), forca(0), velocidade(0){}

Infantaria::~Infantaria(){}

void Infantaria::gerarAtributos(){
    poderAtaque = 30 + rand() % 31;
    forca = 20 + rand() % 31;
    velocidade = 10 + rand() % 31;
}

int Infantaria::getPoderAtaque() const{
    return (poderAtaque*5 + forca*3 + velocidade*2) / 10;
}

void Infantaria::imprimiUnidade() const{
    cout << "== Infantaria (" << getPoderAtaque() << ")" << endl;
    cout << "- Poder de ataque: " << poderAtaque << endl;
    cout << "- Forca: " << forca << endl;
    cout << "- Velocidade: " << velocidade << endl;
}
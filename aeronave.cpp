#include "aeronave.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Aeronave::Aeronave(): Unidade(), manobrabilidade(0), alcance(0){}

Aeronave::~Aeronave(){}

void Aeronave::gerarAtributos() {
    poderAtaque = 50 + rand() % 41;
    manobrabilidade = 30 + rand() % 41;
    alcance = 20 + rand() % 31;
}

int Aeronave::getPoderAtaque() const{
    return (poderAtaque*5 + manobrabilidade*3 + alcance*2) / 10;
}

void Aeronave::imprimiUnidade() const{
    cout << "== Aeronave (" << getPoderAtaque() << ")" << endl;
    cout << "- Poder de ataque: " << poderAtaque << endl;
    cout << "- Manobrabilidade: " << manobrabilidade << endl;
    cout << "- Alcance: " << alcance << endl;
}

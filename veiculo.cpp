#include "veiculo.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Veiculo::Veiculo(): Unidade(), blindagem(0), potenciaDeFogo(0){}

Veiculo::~Veiculo(){}

void Veiculo::gerarAtributos(){
    poderAtaque = 40 + rand() % 41;
    blindagem = 30 + rand() % 41;
    potenciaDeFogo = 20 + rand() % 31;
}

int Veiculo::getPoderAtaque() const{
    return (poderAtaque*5 + blindagem*4 + potenciaDeFogo*1)/10;
}

void Veiculo::imprimiUnidade() const{
    cout << "== Veiculo (" << getPoderAtaque() << ")" << endl;
    cout << "- Poder de ataque: " << poderAtaque << endl;
    cout << "- Potencia de Fogo: " << potenciaDeFogo << endl;
    cout << "- Blindagem: " << blindagem << endl;
}

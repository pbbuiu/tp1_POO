#ifndef VEICULO_HPP
#define VEICULO_HPP

#include "unidade.hpp"

class Veiculo : public Unidade{
    int blindagem;
    int potenciaDeFogo;
public:
    Veiculo();
    ~Veiculo() override;
    int getPoderAtaque() const override;
    void imprimiUnidade() const override;
    void gerarAtributos() override;
};  

#endif //VEICULO_HPP
#ifndef VEICULO_HPP
#define VEICULO_HPP

#include "unidade.hpp"


class Veiculo : Unidade{
    int blindagem;
    int potenciaDeFogo;
public:
    int getPoderAtaque() const override;
};

#endif // VEICULO_HPP
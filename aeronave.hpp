#ifndef AERONAVE_HPP
#define AERONAVE_HPP

#include "unidade.hpp"

class Aeronave : Unidade{
    int manobrabrilidade;
    int alcanse;
public:
    int getPoderAtaque() const override;
};

#endif //AERONAVE_HPP
#ifndef AERONAVE_HPP
#define AERONAVE_HPP

#include "unidade.hpp"

class Aeronave : public Unidade{
    int manobrabilidade;
    int alcance;
public:
    Aeronave();
    ~Aeronave() override;
    int getPoderAtaque() const override;
    void imprimiUnidade() const override;
    void gerarAtributos() override;
};

#endif //AERONAVE_HPP
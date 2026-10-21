#ifndef INFANTARIA_HPP
#define INFANTARIA_HPP

#include "unidade.hpp"

class Infantaria : public Unidade{
    int forca;
    int velocidade;
public:
    Infantaria();
    ~Infantaria() override;
    int getPoderAtaque() const override;
    void imprimiUnidade() const override;
    void gerarAtributos() override;
};

#endif //INFANTARIA_HPP
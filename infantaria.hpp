#ifndef INFANTARIA_HPP
#define INFANTARIA_HPP
#include <unidade.hpp>


class Infantaria : public Unidade{
    int forca;
    int velocidade;
public:
    int getPoderAtaque() const override;
};

#endif //INFANTARIA_HPP
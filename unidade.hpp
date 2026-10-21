#ifndef UNIDADE_HPP
#define UNIDADE_HPP

#include <string>

class Unidade{
private:
    int destruicoes;
protected:
    int poderAtaque;
public:
    Unidade();
    virtual ~Unidade() = default;

    int getDestruicao() const;
    
    void somaDestruicao();
    virtual int getPoderAtaque() const = 0;
    virtual void gerarAtributos() = 0;

    virtual void imprimiUnidade() const = 0;
};

#endif //UNIDADE_HPP
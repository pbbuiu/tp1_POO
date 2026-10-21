#ifndef EXERCITO_HPP
#define EXERCITO_HPP
#include "unidade.hpp"
#include <string>
#include <vector>
class Exercito{
    std::string nome;
    std::vector <Unidade*> unidades;
    int vitorias;
    int derrotas;
    int empates;
public:
    Exercito(std::string n="Os_zome");
    ~Exercito();
    std::string getNome();

    void imprimeUnidades();
    std::string getResultados() const;
    void somaVitoria();
    int getVitoria() const;
    void somaDerrota();
    void somaEmpate();

    void adicionarUnidade(Unidade* u);
    int getPoderAtaqueTotal() const;
    
    void calcularDestruicoes(Exercito& outroExercito);
    Unidade* getMaiorDestruicao() const;
    void mostrarUnidadeMaisDestrutiva() const;

    void randomizarAtributos();
};

#endif //EXERCITO_HPP
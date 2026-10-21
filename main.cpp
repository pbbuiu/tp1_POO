#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "campanha.hpp"
#include "exercito.hpp"
#include "batalha.hpp"
#include "date.hpp"
#include "veiculo.hpp"
#include "infantaria.hpp"
#include "aeronave.hpp"

using namespace std;

// função auxiliar para reaproveitar exércitos com o mesmo nome
Exercito* buscarOuCriarExercito(vector<Exercito*>& exercitosExistentes, const string& nome) {
    for (auto ex : exercitosExistentes) {
        if (ex->getNome() == nome) {
            return ex; //Retorna o ponteiro do exército se já existir
        }
    }
    
    // Se não encontrar cria um novo e gera 5 unidades aleatórias para ele
    Exercito* novoEx = new Exercito(nome);
    for (int i = 0; i < 5; i++) {
        int tipo = rand() % 3;
        Unidade* u = nullptr;
        if (tipo == 0)      u = new Infantaria();
        else if (tipo == 1) u = new Veiculo();
        else                u = new Aeronave();
        
        u->gerarAtributos();
        novoEx->adicionarUnidade(u);
    }
    
    exercitosExistentes.push_back(novoEx);
    return novoEx;
}

// opção de ler um arquivo que já foi salvo
void lerTabelaDoArquivo() {
    string nomeArquivo;
    cout << "\nDigite o nome do arquivo salvo (ex: posicoes.txt): ";
    cin >> nomeArquivo;

    ifstream arquivo(nomeArquivo); // Abre arquivo para leitura

    if (!arquivo.is_open()) {
        cout << "Erro: Nao foi possivel abrir o arquivo '" << nomeArquivo << "'.\n";
        return;
    }

    cout << "Conteudo do arquivo (" << nomeArquivo << ")" << endl;
    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl; // Imprime lnha por linha no terminal
    }
    cout << "Fim do arquivo\n";

    arquivo.close();
}

int main() {
    srand(time(NULL)); // Semente para números aleatórios

    Campanha* campanhaAtual = nullptr;
    vector<Exercito*> exercitosCriados; // Guarda exércitos para evitar duplicação de ponteiros
    int opcaoPrincipal = 0;

    do {
        cout << "\n== MENU PRINCIPAL ==\n";
        cout << "1. Criar Campanha\n";
        cout << "2. Ver tabela de uma campanha salva (Arquivo)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaoPrincipal;

        if (opcaoPrincipal == 1) {
            if (campanhaAtual != nullptr) {
                delete campanhaAtual; // Limpa campanha anterior da memória
            }
            campanhaAtual = new Campanha();

            int opcaoCampanha = 0;
            do {
                cout << "\n== MENU DA CAMPANHA ==\n";
                cout << "1. Adicionar Batalha\n";
                cout << "2. Simular Batalhas\n";
                cout << "3. Gerar Tabela de Posicoes (Salvar em Arquivo)\n";
                cout << "4. Ver Unidade Mais Destrutiva\n";
                cout << "0. Abandonar campanha\n";
                cout << "Escolha: ";
                cin >> opcaoCampanha;

                if (opcaoCampanha == 1) {
                    int dia, mes, ano;
                    string nomeA, nomeB;

                    cout << "\nData da batalha (Dia Mes Ano): ";
                    cin >> dia >> mes >> ano;

                    cout << "Nome do Exercito A: ";
                    cin >> nomeA;
                    cout << "Nome do Exercito B: ";
                    cin >> nomeB;

                    Exercito* exA = buscarOuCriarExercito(exercitosCriados, nomeA);
                    Exercito* exB = buscarOuCriarExercito(exercitosCriados, nomeB);

                    Date dataBatalha(dia, mes, ano);
                    Batalha* novaBatalha = new Batalha(dataBatalha, exA, exB);

                    campanhaAtual->adicionarBatalha(novaBatalha);
                    cout << "Batalha adicionada com sucesso!\n";

                } else if (opcaoCampanha == 2) {
                    cout << "\nSimulando batalhas...\n";
                    campanhaAtual->simularBatalhas();
                    cout << "Batalhas simuladas!\n";

                } else if (opcaoCampanha == 3) {
                    string nomeArquivo;
                    cout << "\nDigite o nome do arquivo para salvar: ";
                    cin >> nomeArquivo;

                    ofstream arquivoSaida(nomeArquivo); // Abre arquivo para escrita
                    if (arquivoSaida.is_open()) {
                        campanhaAtual->gerarTabelaPosicoes(arquivoSaida);
                        arquivoSaida.close();
                        cout << "Tabela salva em: " << nomeArquivo << endl;
                    } else {
                        cout << "Erro ao criar o arquivo.\n";
                    }

                } else if (opcaoCampanha == 4) {
                    cout << "\n--- Unidade Mais Destrutiva ---\n";
                    campanhaAtual->mostrarUnidadeMaisDestrutiva();
                }

            } while (opcaoCampanha != 0);

        } else if (opcaoPrincipal == 2) {
            lerTabelaDoArquivo();
        }

    } while (opcaoPrincipal != 0);

    // Limpeza de memória ao sair do programa
    if (campanhaAtual != nullptr) delete campanhaAtual;
    for (auto ex : exercitosCriados) delete ex;

    cout << "\nPrograma encerrado!\n";
    return 0;
}

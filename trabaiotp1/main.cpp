/**
 * @file main.cpp
 * @brief Ponto de entrada do sistema.
 */

#include "ControladoraPessoa.hpp"
#include "ControladoraProjeto.hpp"
#include "ControladoraHistoria.hpp"
#include "ControladoraPlanoSprint.hpp"
#include "ServicoPessoa.hpp"
#include "ServicoProjeto.hpp"
#include "ServicoHistoria.hpp"
#include "ServicoPlanoSprint.hpp"
#include "ContainerPessoa.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerHistoria.hpp"
#include "ContainerPlanoSprint.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Contêineres
    ContainerPessoa containerPessoa;
    ContainerProjeto containerProjeto;
    ContainerHistoria containerHistoria;
    ContainerPlanoSprint containerPlanoSprint;

    // Serviços
    ServicoPessoa servicoPessoa(&containerPessoa);
    ServicoProjeto servicoProjeto(&containerProjeto, &containerPessoa);
    ServicoHistoria servicoHistoria(&containerHistoria, &containerProjeto, &containerPessoa);
    ServicoPlanoSprint servicoPlanoSprint(&containerPlanoSprint, &containerProjeto, &containerHistoria);

    // Controladoras
    ControladoraPessoa ctrlPessoa(&servicoPessoa);
    ControladoraProjeto ctrlProjeto(&servicoProjeto, &servicoPessoa);
    ControladoraHistoria ctrlHistoria(&servicoHistoria, &servicoProjeto, &servicoPessoa);
    ControladoraPlanoSprint ctrlPlano(&servicoPlanoSprint, &servicoProjeto, &servicoHistoria);

    int opcao;
    do {
        cout << "\n===== SISTEMA DE GESTAO SCRUM =====\n";
        cout << "1. Gerenciar Pessoas\n";
        cout << "2. Gerenciar Projetos\n";
        cout << "3. Gerenciar Historias de Usuario\n";
        cout << "4. Gerenciar Planos de Sprint\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1: ctrlPessoa.executarMenu(); break;
            case 2: ctrlProjeto.executarMenu(); break;
            case 3: ctrlHistoria.executarMenu(); break;
            case 4: ctrlPlano.executarMenu(); break;
            case 0: cout << "Encerrando...\n"; break;
            default: cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}

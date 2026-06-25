/**
 * @file ControladoraPlanoSprint.cpp
 * @brief Implementação da ControladoraPlanoSprint.
 */

#include "ControladoraPlanoSprint.hpp"
#include "plano_de_sprint.hpp"
#include "codigo.hpp"
#include "texto.hpp"
#include "tempo.hpp"
#include <iostream>
#include <limits>

ControladoraPlanoSprint::ControladoraPlanoSprint(IServicoPlanoSprint* sp, IServicoProjeto* sproj, IServicoHistoria* shist)
    : servicoPlano(sp), servicoProjeto(sproj), servicoHistoria(shist) {}

void ControladoraPlanoSprint::executarMenu() {
    int opcao;
    do {
        std::cout << "\n--- GERENCIAR PLANOS DE SPRINT ---\n";
        std::cout << "1. Cadastrar sprint\n";
        std::cout << "2. Listar todos\n";
        std::cout << "3. Consultar por codigo\n";
        std::cout << "4. Atualizar\n";
        std::cout << "5. Excluir\n";
        std::cout << "6. Listar sprints de um projeto\n";
        std::cout << "7. Adicionar historia ao sprint\n";
        std::cout << "8. Remover historia do sprint\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: consultar(); break;
            case 4: atualizar(); break;
            case 5: excluir(); break;
            case 6: listarPorProjeto(); break;
            case 7: adicionarHistoria(); break;
            case 8: removerHistoria(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void ControladoraPlanoSprint::cadastrar() {
    try {
        std::string codigo, objetivo, codProjeto;
        int capacidade;
        std::cout << "Codigo do sprint (2 letras + 3 digitos): ";
        std::getline(std::cin, codigo);
        std::cout << "Objetivo (max 40 caracteres): ";
        std::getline(std::cin, objetivo);
        std::cout << "Capacidade (dias, 1-365): ";
        std::cin >> capacidade;
        std::cin.ignore();
        std::cout << "Codigo do projeto: ";
        std::getline(std::cin, codProjeto);

        Codigo cod(codigo);
        Texto obj(objetivo);
        Tempo cap(capacidade);

        PlanoDeSprint plano(cod, obj, cap);
        servicoPlano->criar(plano, codProjeto);
        std::cout << "Plano de sprint cadastrado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::listar() {
    try {
        auto planos = servicoPlano->listarTodos();
        if (planos.empty()) {
            std::cout << "Nenhum plano de sprint cadastrado.\n";
            return;
        }
        std::cout << "--- PLANOS DE SPRINT ---\n";
        for (const auto& p : planos) {
            std::cout << p.getCodigo().getValor() << " | "
                      << p.getObjetivo().getValor() << " | "
                      << "Capacidade: " << p.getCapacidade().getValor() << " dias\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::consultar() {
    try {
        std::string codigo;
        std::cout << "Codigo do sprint: ";
        std::getline(std::cin, codigo);
        PlanoDeSprint p = servicoPlano->ler(codigo);
        std::cout << "--- DADOS DO SPRINT ---\n";
        std::cout << "Codigo: " << p.getCodigo().getValor() << "\n";
        std::cout << "Objetivo: " << p.getObjetivo().getValor() << "\n";
        std::cout << "Capacidade: " << p.getCapacidade().getValor() << " dias\n";
        std::cout << "Historias associadas: ";
        auto historias = p.getHistoriasAssociadas();
        if (historias.empty()) {
            std::cout << "nenhuma\n";
        } else {
            for (const auto& cod : historias) {
                std::cout << cod << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::atualizar() {
    try {
        std::string codigo, objetivo;
        int capacidade;
        std::cout << "Codigo do sprint a atualizar: ";
        std::getline(std::cin, codigo);
        PlanoDeSprint p = servicoPlano->ler(codigo);

        std::cout << "Novo objetivo (atual: " << p.getObjetivo().getValor() << "): ";
        std::getline(std::cin, objetivo);
        if (!objetivo.empty()) p.setObjetivo(Texto(objetivo));

        std::cout << "Nova capacidade (atual: " << p.getCapacidade().getValor() << "): ";
        std::cin >> capacidade;
        std::cin.ignore();
        if (capacidade > 0) p.setCapacidade(Tempo(capacidade));

        servicoPlano->atualizar(p);
        std::cout << "Plano de sprint atualizado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::excluir() {
    try {
        std::string codigo;
        std::cout << "Codigo do sprint a excluir: ";
        std::getline(std::cin, codigo);
        servicoPlano->excluir(codigo);
        std::cout << "Plano de sprint excluido com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::listarPorProjeto() {
    try {
        std::string codProjeto;
        std::cout << "Codigo do projeto: ";
        std::getline(std::cin, codProjeto);
        auto planos = servicoPlano->listarPorProjeto(codProjeto);
        if (planos.empty()) {
            std::cout << "Nenhum sprint associado a este projeto.\n";
            return;
        }
        std::cout << "--- SPRINTS DO PROJETO ---\n";
        for (const auto& p : planos) {
            std::cout << p.getCodigo().getValor() << " - " << p.getObjetivo().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::adicionarHistoria() {
    try {
        std::string codSprint, codHistoria;
        std::cout << "Codigo do sprint: ";
        std::getline(std::cin, codSprint);
        std::cout << "Codigo da historia: ";
        std::getline(std::cin, codHistoria);
        servicoPlano->adicionarHistoriaAoSprint(codSprint, codHistoria);
        std::cout << "Historia adicionada ao sprint com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPlanoSprint::removerHistoria() {
    try {
        std::string codSprint, codHistoria;
        std::cout << "Codigo do sprint: ";
        std::getline(std::cin, codSprint);
        std::cout << "Codigo da historia: ";
        std::getline(std::cin, codHistoria);
        servicoPlano->removerHistoriaDoSprint(codSprint, codHistoria);
        std::cout << "Historia removida do sprint com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

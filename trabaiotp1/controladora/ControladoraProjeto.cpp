/**
 * @file ControladoraProjeto.cpp
 * @brief Implementação da ControladoraProjeto.
 */

#include "ControladoraProjeto.hpp"
#include "Projeto.hpp"
#include "Codigo.hpp"
#include "Nome.hpp"
#include "Data.hpp"
#include <iostream>
#include <limits>

ControladoraProjeto::ControladoraProjeto(IServicoProjeto* sp, IServicoPessoa* spess)
    : servicoProjeto(sp), servicoPessoa(spess) {}

void ControladoraProjeto::executarMenu() {
    int opcao;
    do {
        std::cout << "\n--- GERENCIAR PROJETOS ---\n";
        std::cout << "1. Cadastrar projeto\n";
        std::cout << "2. Listar todos\n";
        std::cout << "3. Consultar por código\n";
        std::cout << "4. Atualizar\n";
        std::cout << "5. Excluir\n";
        std::cout << "6. Listar projetos por pessoa\n";
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
            case 6: listarPorPessoa(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void ControladoraProjeto::cadastrar() {
    try {
        std::string codigo, nome, inicio, termino, emailSM;
        std::cout << "Código (2 letras + 3 dígitos): ";
        std::getline(std::cin, codigo);
        std::cout << "Nome (max 10 caracteres): ";
        std::getline(std::cin, nome);
        std::cout << "Data de início (DD/MM/AAAA): ";
        std::getline(std::cin, inicio);
        std::cout << "Data de término (DD/MM/AAAA): ";
        std::getline(std::cin, termino);
        std::cout << "Email do Scrum Master: ";
        std::getline(std::cin, emailSM);

        servicoPessoa->ler(emailSM);

        Codigo cod(codigo);
        Nome nom(nome);
        Data ini(inicio);
        Data fim(termino);

        Projeto projeto(cod, nom, ini, fim);
        servicoProjeto->criar(projeto, emailSM);
        std::cout << "Projeto cadastrado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraProjeto::listar() {
    try {
        auto projetos = servicoProjeto->listarTodos();
        if (projetos.empty()) {
            std::cout << "Nenhum projeto cadastrado.\n";
            return;
        }
        std::cout << "--- PROJETOS CADASTRADOS ---\n";
        for (const auto& p : projetos) {
            std::cout << p.getCodigo().getValor() << " | "
                      << p.getNome().getValor() << " | "
                      << p.getInicio().getValor() << " a "
                      << p.getTermino().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraProjeto::consultar() {
    try {
        std::string codigo;
        std::cout << "Código do projeto: ";
        std::getline(std::cin, codigo);
        Projeto p = servicoProjeto->ler(codigo);
        std::cout << "--- DADOS DO PROJETO ---\n";
        std::cout << "Código: " << p.getCodigo().getValor() << "\n";
        std::cout << "Nome: " << p.getNome().getValor() << "\n";
        std::cout << "Início: " << p.getInicio().getValor() << "\n";
        std::cout << "Término: " << p.getTermino().getValor() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraProjeto::atualizar() {
    try {
        std::string codigo, nome, inicio, termino;
        std::cout << "Código do projeto a atualizar: ";
        std::getline(std::cin, codigo);
        Projeto p = servicoProjeto->ler(codigo);

        std::cout << "Novo nome (atual: " << p.getNome().getValor() << "): ";
        std::getline(std::cin, nome);
        if (!nome.empty()) p.setNome(Nome(nome));

        std::cout << "Nova data de início (atual: " << p.getInicio().getValor() << "): ";
        std::getline(std::cin, inicio);
        if (!inicio.empty()) p.setInicio(Data(inicio));

        std::cout << "Nova data de término (atual: " << p.getTermino().getValor() << "): ";
        std::getline(std::cin, termino);
        if (!termino.empty()) p.setTermino(Data(termino));

        servicoProjeto->atualizar(p);
        std::cout << "Projeto atualizado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraProjeto::excluir() {
    try {
        std::string codigo;
        std::cout << "Código do projeto a excluir: ";
        std::getline(std::cin, codigo);
        servicoProjeto->excluir(codigo);
        std::cout << "Projeto excluído com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraProjeto::listarPorPessoa() {
    try {
        std::string email;
        std::cout << "Email da pessoa: ";
        std::getline(std::cin, email);
        auto projetos = servicoProjeto->listarProjetosPorPessoa(email);
        if (projetos.empty()) {
            std::cout << "Nenhum projeto associado a essa pessoa.\n";
            return;
        }
        std::cout << "--- PROJETOS ASSOCIADOS ---\n";
        for (const auto& p : projetos) {
            std::cout << p.getCodigo().getValor() << " - " << p.getNome().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

/**
 * @file ControladoraPessoa.cpp
 * @brief Implementação da ControladoraPessoa.
 */

#include "ControladoraPessoa.hpp"
#include "Pessoa.hpp"
#include "Email.hpp"
#include "Nome.hpp"
#include "Senha.hpp"
#include "Papel.hpp"
#include <iostream>
#include <limits>

ControladoraPessoa::ControladoraPessoa(IServicoPessoa* srv) : servico(srv) {}

void ControladoraPessoa::executarMenu() {
    int opcao;
    do {
        std::cout << "\n--- GERENCIAR PESSOAS ---\n";
        std::cout << "1. Cadastrar\n";
        std::cout << "2. Listar todos\n";
        std::cout << "3. Consultar por email\n";
        std::cout << "4. Atualizar\n";
        std::cout << "5. Excluir\n";
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
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void ControladoraPessoa::cadastrar() {
    try {
        std::string email, nome, senha, papelStr;
        std::cout << "Email: ";
        std::getline(std::cin, email);
        std::cout << "Nome (max 10 caracteres): ";
        std::getline(std::cin, nome);
        std::cout << "Senha (6 caracteres, com maiúscula, minúscula e dígito): ";
        std::getline(std::cin, senha);
        std::cout << "Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO): ";
        std::getline(std::cin, papelStr);

        Email emailObj(email);
        Nome nomeObj(nome);
        Senha senhaObj(senha);
        Papel papelObj(papelStr);

        Pessoa pessoa(emailObj, nomeObj, senhaObj, papelObj);
        servico->criar(pessoa);
        std::cout << "Pessoa cadastrada com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPessoa::listar() {
    try {
        auto pessoas = servico->listarTodos();
        if (pessoas.empty()) {
            std::cout << "Nenhuma pessoa cadastrada.\n";
            return;
        }
        std::cout << "--- PESSOAS CADASTRADAS ---\n";
        for (const auto& p : pessoas) {
            std::cout << p.getEmail().getValor() << " | "
                      << p.getNome().getValor() << " | "
                      << p.getPapel().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPessoa::consultar() {
    try {
        std::string email;
        std::cout << "Email da pessoa: ";
        std::getline(std::cin, email);
        Pessoa p = servico->ler(email);
        std::cout << "--- DADOS ---\n";
        std::cout << "Email: " << p.getEmail().getValor() << "\n";
        std::cout << "Nome: " << p.getNome().getValor() << "\n";
        std::cout << "Papel: " << p.getPapel().getValor() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPessoa::atualizar() {
    try {
        std::string email, nome, senha, papelStr;
        std::cout << "Email da pessoa a atualizar: ";
        std::getline(std::cin, email);
        Pessoa p = servico->ler(email);

        std::cout << "Novo nome (atual: " << p.getNome().getValor() << "): ";
        std::getline(std::cin, nome);
        if (!nome.empty()) p.setNome(Nome(nome));

        std::cout << "Nova senha (atual: " << p.getSenha().getValor() << ") - deixe em branco para manter: ";
        std::getline(std::cin, senha);
        if (!senha.empty()) p.setSenha(Senha(senha));

        std::cout << "Novo papel (atual: " << p.getPapel().getValor() << "): ";
        std::getline(std::cin, papelStr);
        if (!papelStr.empty()) p.setPapel(Papel(papelStr));

        servico->atualizar(p);
        std::cout << "Dados atualizados com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraPessoa::excluir() {
    try {
        std::string email;
        std::cout << "Email da pessoa a excluir: ";
        std::getline(std::cin, email);
        servico->excluir(email);
        std::cout << "Pessoa excluída com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

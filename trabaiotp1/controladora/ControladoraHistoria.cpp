/**
 * @file ControladoraHistoria.cpp
 * @brief Implementação da ControladoraHistoria.
 */

#include "ControladoraHistoria.hpp"
#include "historia_de_usuario.hpp"
#include "codigo.hpp"
#include "texto.hpp"
#include "tempo.hpp"
#include "prioridade.hpp"
#include "estado.hpp"
#include <iostream>
#include <limits>

ControladoraHistoria::ControladoraHistoria(IServicoHistoria* sh, IServicoProjeto* sp, IServicoPessoa* spess)
    : servicoHistoria(sh), servicoProjeto(sp), servicoPessoa(spess) {}

void ControladoraHistoria::executarMenu() {
    int opcao;
    do {
        std::cout << "\n--- GERENCIAR HISTÓRIAS DE USUÁRIO ---\n";
        std::cout << "1. Cadastrar história\n";
        std::cout << "2. Listar todas\n";
        std::cout << "3. Consultar por código\n";
        std::cout << "4. Atualizar\n";
        std::cout << "5. Excluir\n";
        std::cout << "6. Listar por projeto\n";
        std::cout << "7. Associar desenvolvedor\n";
        std::cout << "8. Desassociar desenvolvedor\n";
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
            case 7: associarDesenvolvedor(); break;
            case 8: desassociarDesenvolvedor(); break;
            case 0: break;
            default: std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void ControladoraHistoria::cadastrar() {
    try {
        std::string codigo, titulo, papel, acao, valor, prioridade, codProjeto;
        int estimativa;
        std::cout << "Código (2 letras + 3 dígitos): ";
        std::getline(std::cin, codigo);
        std::cout << "Título (max 40 caracteres): ";
        std::getline(std::cin, titulo);
        std::cout << "Papel (como...): ";
        std::getline(std::cin, papel);
        std::cout << "Ação (eu quero...): ";
        std::getline(std::cin, acao);
        std::cout << "Valor (para...): ";
        std::getline(std::cin, valor);
        std::cout << "Estimativa (dias, 1-365): ";
        std::cin >> estimativa;
        std::cin.ignore();
        std::cout << "Prioridade (ALTA, MEDIA, BAIXA): ";
        std::getline(std::cin, prioridade);
        std::cout << "Código do projeto: ";
        std::getline(std::cin, codProjeto);

        Codigo cod(codigo);
        Texto tit(titulo), pap(papel), ac(acao), val(valor);
        Tempo est(estimativa);
        Prioridade pri(prioridade);
        Estado estado("A FAZER");

        HistoriaDeUsuario historia(cod, tit, pap, ac, val, est, pri, estado);
        servicoHistoria->criar(historia, codProjeto);
        std::cout << "História cadastrada com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::listar() {
    try {
        auto historias = servicoHistoria->listarTodos();
        if (historias.empty()) {
            std::cout << "Nenhuma história cadastrada.\n";
            return;
        }
        std::cout << "--- HISTÓRIAS CADASTRADAS ---\n";
        for (const auto& h : historias) {
            std::cout << h.getCodigo().getValor() << " | "
                      << h.getTitulo().getValor() << " | "
                      << h.getEstado().getValor() << " | "
                      << h.getPrioridade().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::consultar() {
    try {
        std::string codigo;
        std::cout << "Código da história: ";
        std::getline(std::cin, codigo);
        HistoriaDeUsuario h = servicoHistoria->ler(codigo);
        std::cout << "--- DADOS DA HISTÓRIA ---\n";
        std::cout << "Código: " << h.getCodigo().getValor() << "\n";
        std::cout << "Título: " << h.getTitulo().getValor() << "\n";
        std::cout << "Papel: " << h.getPapel().getValor() << "\n";
        std::cout << "Ação: " << h.getAcao().getValor() << "\n";
        std::cout << "Valor: " << h.getValor().getValor() << "\n";
        std::cout << "Estimativa: " << h.getEstimativa().getValor() << "\n";
        std::cout << "Prioridade: " << h.getPrioridade().getValor() << "\n";
        std::cout << "Estado: " << h.getEstado().getValor() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::atualizar() {
    try {
        std::string codigo, titulo, papel, acao, valor, prioridade, estado;
        int estimativa;
        std::cout << "Código da história a atualizar: ";
        std::getline(std::cin, codigo);
        HistoriaDeUsuario h = servicoHistoria->ler(codigo);

        std::cout << "Novo título (atual: " << h.getTitulo().getValor() << "): ";
        std::getline(std::cin, titulo);
        if (!titulo.empty()) h.setTitulo(Texto(titulo));

        std::cout << "Novo papel (atual: " << h.getPapel().getValor() << "): ";
        std::getline(std::cin, papel);
        if (!papel.empty()) h.setPapel(Texto(papel));

        std::cout << "Nova ação (atual: " << h.getAcao().getValor() << "): ";
        std::getline(std::cin, acao);
        if (!acao.empty()) h.setAcao(Texto(acao));

        std::cout << "Novo valor (atual: " << h.getValor().getValor() << "): ";
        std::getline(std::cin, valor);
        if (!valor.empty()) h.setValor(Texto(valor));

        std::cout << "Nova estimativa (atual: " << h.getEstimativa().getValor() << "): ";
        std::cin >> estimativa;
        std::cin.ignore();
        if (estimativa > 0) h.setEstimativa(Tempo(estimativa));

        std::cout << "Nova prioridade (atual: " << h.getPrioridade().getValor() << "): ";
        std::getline(std::cin, prioridade);
        if (!prioridade.empty()) h.setPrioridade(Prioridade(prioridade));

        std::cout << "Novo estado (atual: " << h.getEstado().getValor() << "): ";
        std::getline(std::cin, estado);
        if (!estado.empty()) h.setEstado(Estado(estado));

        servicoHistoria->atualizar(h);
        std::cout << "História atualizada com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::excluir() {
    try {
        std::string codigo;
        std::cout << "Código da história a excluir: ";
        std::getline(std::cin, codigo);
        servicoHistoria->excluir(codigo);
        std::cout << "História excluída com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::listarPorProjeto() {
    try {
        std::string codProjeto;
        std::cout << "Código do projeto: ";
        std::getline(std::cin, codProjeto);
        auto historias = servicoHistoria->listarPorProjeto(codProjeto);
        if (historias.empty()) {
            std::cout << "Nenhuma história associada a este projeto.\n";
            return;
        }
        std::cout << "--- HISTÓRIAS DO PROJETO ---\n";
        for (const auto& h : historias) {
            std::cout << h.getCodigo().getValor() << " - " << h.getTitulo().getValor() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::associarDesenvolvedor() {
    try {
        std::string codHistoria, emailDev;
        std::cout << "Código da história: ";
        std::getline(std::cin, codHistoria);
        std::cout << "Email do desenvolvedor: ";
        std::getline(std::cin, emailDev);
        servicoHistoria->associarDesenvolvedor(codHistoria, emailDev);
        std::cout << "Desenvolvedor associado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

void ControladoraHistoria::desassociarDesenvolvedor() {
    try {
        std::string codHistoria;
        std::cout << "Código da história: ";
        std::getline(std::cin, codHistoria);
        servicoHistoria->desassociarDesenvolvedor(codHistoria);
        std::cout << "Desenvolvedor desassociado com sucesso!\n";
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}

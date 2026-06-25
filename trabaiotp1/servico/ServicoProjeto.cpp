/**
 * @file ServicoProjeto.cpp
 * @brief Implementação dos métodos do serviço Projeto.
 */

#include "ServicoProjeto.hpp"
#include <stdexcept>

ServicoProjeto::ServicoProjeto(ContainerProjeto* cp, ContainerPessoa* cpes)
    : containerProjeto(cp), containerPessoa(cpes) {}

void ServicoProjeto::criar(const Projeto& projeto, const std::string& emailScrumMaster) {
    if (containerProjeto->existe(projeto.getCodigo().getValor()))
        throw std::invalid_argument("Codigo de projeto ja existe");
    if (!containerPessoa->existe(emailScrumMaster))
        throw std::invalid_argument("Scrum Master nao encontrado");

    Pessoa sm = containerPessoa->buscar(emailScrumMaster);
    if (sm.getPapel().getValor() != "MESTRE SCRUM")
        throw std::invalid_argument("Pessoa nao e Scrum Master");

    containerProjeto->inserir(projeto);
}

Projeto ServicoProjeto::ler(const std::string& codigo) const {
    return containerProjeto->buscar(codigo);
}

void ServicoProjeto::atualizar(const Projeto& projeto) {
    if (!containerProjeto->existe(projeto.getCodigo().getValor()))
        throw std::invalid_argument("Projeto nao encontrado");
    containerProjeto->atualizar(projeto);
}

void ServicoProjeto::excluir(const std::string& codigo) {
    if (!containerProjeto->existe(codigo))
        throw std::invalid_argument("Projeto nao encontrado");
    containerProjeto->remover(codigo);
}

std::vector<Projeto> ServicoProjeto::listarTodos() const {
    return containerProjeto->listar();
}

std::vector<Projeto> ServicoProjeto::listarProjetosPorPessoa(const std::string&) const {
    // Implementação simplificada – retorna todos
    return containerProjeto->listar();
}


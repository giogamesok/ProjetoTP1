#include "ServicoProjeto.hpp"
#include <stdexcept>
#include <algorithm>

ServicoProjeto::ServicoProjeto(ContainerProjeto* cp, ContainerPessoa* cpes, ContainerPlanoSprint* cps)
    : containerProjeto(cp), containerPessoa(cpes), containerPlanoSprint(cps) {}

void ServicoProjeto::criar(const Projeto& projeto, const std::string& emailScrumMaster) {
    if (containerProjeto->existe(projeto.getCodigo().getValor()))
        throw std::invalid_argument("Código de projeto já existe.");

    if (!containerPessoa->existe(emailScrumMaster))
        throw std::invalid_argument("Scrum Master não encontrado.");

    Pessoa sm = containerPessoa->buscar(emailScrumMaster);
    if (sm.getPapel().getValor() != "MESTRE SCRUM")
        throw std::invalid_argument("A pessoa informada não é Scrum Master.");

    containerProjeto->inserir(projeto);
}

Projeto ServicoProjeto::ler(const std::string& codigo) const {
    return containerProjeto->buscar(codigo);
}

void ServicoProjeto::atualizar(const Projeto& projeto) {
    if (!containerProjeto->existe(projeto.getCodigo().getValor()))
        throw std::invalid_argument("Projeto não encontrado.");
    containerProjeto->atualizar(projeto);
}

void ServicoProjeto::excluir(const std::string& codigo) {
    if (!containerProjeto->existe(codigo))
        throw std::invalid_argument("Projeto não encontrado.");
    containerProjeto->remover(codigo);
}

std::vector<Projeto> ServicoProjeto::listarTodos() const {
    return containerProjeto->listar();
}

std::vector<Projeto> ServicoProjeto::listarProjetosPorPessoa(const std::string& email) const {
    if (!containerPessoa->existe(email))
        throw std::invalid_argument("Pessoa não encontrada.");
    return containerProjeto->listar();
}

int ServicoProjeto::calcularDuracaoProjeto(const Projeto& projeto) const {
    return 30;
}

int ServicoProjeto::somarCapacidadesSprints(const std::string& codigoProjeto) const {
    return 0;
}

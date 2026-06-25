#include "ServicoPlanoSprint.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>

ServicoPlanoSprint::ServicoPlanoSprint(ContainerPlanoSprint* cs, ContainerProjeto* cp, ContainerHistoria* ch)
    : containerSprint(cs), containerProjeto(cp), containerHistoria(ch) {}

void ServicoPlanoSprint::criar(const PlanoDeSprint& plano, const std::string& codigoProjeto) {
    if (containerSprint->existe(plano.getCodigo().getValor()))
        throw std::invalid_argument("Código de sprint já existe.");

    if (!containerProjeto->existe(codigoProjeto))
        throw std::invalid_argument("Projeto não encontrado.");

    if (!verificarCapacidadeTotalProjeto(codigoProjeto)) {
        Projeto projeto = containerProjeto->buscar(codigoProjeto);
        int duracao = projeto.getTermino().getValor() - projeto.getInicio().getValor();
        int soma = 0;
        for (const auto& par : sprintProjeto) {
            if (par.second == codigoProjeto) {
                soma += containerSprint->buscar(par.first).getCapacidade().getValor();
            }
        }
        if (soma + plano.getCapacidade().getValor() > duracao)
            throw std::invalid_argument("Capacidade total dos sprints excede a duração do projeto.");
    }

    containerSprint->inserir(plano);
    sprintProjeto[plano.getCodigo().getValor()] = codigoProjeto;
}

PlanoDeSprint ServicoPlanoSprint::ler(const std::string& codigo) const {
    return containerSprint->buscar(codigo);
}

void ServicoPlanoSprint::atualizar(const PlanoDeSprint& plano) {
    if (!containerSprint->existe(plano.getCodigo().getValor()))
        throw std::invalid_argument("Sprint não encontrado.");
    std::string codigoProjeto = sprintProjeto[plano.getCodigo().getValor()];
    int soma = 0;
    for (const auto& par : sprintProjeto) {
        if (par.second == codigoProjeto) {
            if (par.first == plano.getCodigo().getValor()) {
                soma += plano.getCapacidade().getValor();
            } else {
                soma += containerSprint->buscar(par.first).getCapacidade().getValor();
            }
        }
    }
    Projeto projeto = containerProjeto->buscar(codigoProjeto);
    int duracao = projeto.getTermino().getValor() - projeto.getInicio().getValor();
    if (soma > duracao)
        throw std::invalid_argument("Capacidade total dos sprints excede a duração do projeto.");

    containerSprint->atualizar(plano);
}

void ServicoPlanoSprint::excluir(const std::string& codigo) {
    if (!containerSprint->existe(codigo))
        throw std::invalid_argument("Sprint não encontrado.");
    sprintProjeto.erase(codigo);
    containerSprint->remover(codigo);
}

std::vector<PlanoDeSprint> ServicoPlanoSprint::listarTodos() const {
    return containerSprint->listar();
}

std::vector<PlanoDeSprint> ServicoPlanoSprint::listarPorProjeto(const std::string& codigoProjeto) const {
    std::vector<PlanoDeSprint> resultado;
    for (const auto& par : sprintProjeto) {
        if (par.second == codigoProjeto) {
            resultado.push_back(containerSprint->buscar(par.first));
        }
    }
    return resultado;
}

void ServicoPlanoSprint::adicionarHistoriaAoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) {
    if (!containerSprint->existe(codigoSprint))
        throw std::invalid_argument("Sprint não encontrado.");
    if (!containerHistoria->existe(codigoHistoria))
        throw std::invalid_argument("História não encontrada.");
    std::string codigoProjetoSprint = sprintProjeto[codigoSprint];
    HistoriaDeUsuario historia = containerHistoria->buscar(codigoHistoria);
    int estimativa = historia.getEstimativa().getValor();
    PlanoDeSprint sprint = containerSprint->buscar(codigoSprint);
    sprint.adicionarHistoria(codigoHistoria, estimativa);
    containerSprint->atualizar(sprint);
}

void ServicoPlanoSprint::removerHistoriaDoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) {
    if (!containerSprint->existe(codigoSprint))
        throw std::invalid_argument("Sprint não encontrado.");
    PlanoDeSprint sprint = containerSprint->buscar(codigoSprint);
    sprint.removerHistoria(codigoHistoria);
    containerSprint->atualizar(sprint);
}

bool ServicoPlanoSprint::verificarCapacidadeTotalProjeto(const std::string& codigoProjeto) const {
    return true;
}

/**
 * @file ServicoPlanoSprint.cpp
 * @brief Implementação dos métodos do serviço PlanoDeSprint.
 */

#include "ServicoPlanoSprint.hpp"
#include <stdexcept>
#include <algorithm>
#include <cstdio>

/**
 * @brief Função auxiliar para calcular dias desde 01/01/2000 (aproximado).
 * @param dataStr Data no formato DD/MM/AAAA.
 * @return Número de dias (aproximado).
 */
static int diasDesde2000(const std::string& dataStr) {
    int dia, mes, ano;
    if (sscanf(dataStr.c_str(), "%d/%d/%d", &dia, &mes, &ano) != 3)
        return 0;
    return (ano - 2000) * 360 + (mes - 1) * 30 + dia;
}

ServicoPlanoSprint::ServicoPlanoSprint(ContainerPlanoSprint* cp,
                                       ContainerProjeto* cproj,
                                       ContainerHistoria* chist)
    : containerPlano(cp), containerProjeto(cproj), containerHistoria(chist) {}

void ServicoPlanoSprint::criar(const PlanoDeSprint& plano, const std::string& codigoProjeto) {
    if (containerPlano->existe(plano.getCodigo().getValor()))
        throw std::invalid_argument("Codigo de sprint ja existe");
    if (!containerProjeto->existe(codigoProjeto))
        throw std::invalid_argument("Projeto nao encontrado");
    // Validação de capacidade total (soma dos sprints) pode ser adicionada aqui
    containerPlano->inserir(plano);
}

PlanoDeSprint ServicoPlanoSprint::ler(const std::string& codigo) const {
    return containerPlano->buscar(codigo);
}

void ServicoPlanoSprint::atualizar(const PlanoDeSprint& plano) {
    if (!containerPlano->existe(plano.getCodigo().getValor()))
        throw std::invalid_argument("Plano nao encontrado");
    containerPlano->atualizar(plano);
}

void ServicoPlanoSprint::excluir(const std::string& codigo) {
    if (!containerPlano->existe(codigo))
        throw std::invalid_argument("Plano nao encontrado");
    containerPlano->remover(codigo);
}

std::vector<PlanoDeSprint> ServicoPlanoSprint::listarTodos() const {
    return containerPlano->listar();
}

std::vector<PlanoDeSprint> ServicoPlanoSprint::listarPorProjeto(const std::string&) const {
    // Em um sistema completo, filtraria por associação Projeto-Sprint
    return containerPlano->listar();
}

void ServicoPlanoSprint::adicionarHistoriaAoSprint(const std::string& codigoSprint,
                                                   const std::string& codigoHistoria) {
    if (!containerPlano->existe(codigoSprint))
        throw std::invalid_argument("Sprint nao encontrado");
    if (!containerHistoria->existe(codigoHistoria))
        throw std::invalid_argument("Historia nao encontrada");

    PlanoDeSprint sprint = containerPlano->buscar(codigoSprint);
    HistoriaDeUsuario hist = containerHistoria->buscar(codigoHistoria);

    int somaAtual = 0;
    for (const std::string& cod : sprint.getHistoriasAssociadas()) {
        HistoriaDeUsuario h = containerHistoria->buscar(cod);
        somaAtual += h.getEstimativa().getValor();
    }

    if (somaAtual + hist.getEstimativa().getValor() > sprint.getCapacidade().getValor())
        throw std::invalid_argument("Soma das estimativas excede a capacidade do sprint");

    sprint.adicionarHistoria(codigoHistoria, hist.getEstimativa().getValor());
    containerPlano->atualizar(sprint);
}

void ServicoPlanoSprint::removerHistoriaDoSprint(const std::string& codigoSprint,
                                                 const std::string& codigoHistoria) {
    if (!containerPlano->existe(codigoSprint))
        throw std::invalid_argument("Sprint nao encontrado");
    PlanoDeSprint sprint = containerPlano->buscar(codigoSprint);
    sprint.removerHistoria(codigoHistoria);
    containerPlano->atualizar(sprint);
}

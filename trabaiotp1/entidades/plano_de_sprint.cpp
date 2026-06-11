/**
 * @file PlanoDeSprint.cpp
 * @brief Implementação da classe PlanoDeSprint.
 */
#include "plano_de_sprint.hpp"
#include <algorithm>
#include <stdexcept>

PlanoDeSprint::PlanoDeSprint() {}

PlanoDeSprint::PlanoDeSprint(const Codigo& c, const Texto& o, const Tempo& cap)
    : codigo(c), objetivo(o), capacidade(cap) {}

Codigo PlanoDeSprint::getCodigo() const { return codigo; }
Texto PlanoDeSprint::getObjetivo() const { return objetivo; }
Tempo PlanoDeSprint::getCapacidade() const { return capacidade; }
const std::vector<std::string>& PlanoDeSprint::getHistoriasAssociadas() const { return historiasAssociadas; }

void PlanoDeSprint::setCodigo(const Codigo& c) { codigo = c; }
void PlanoDeSprint::setObjetivo(const Texto& o) { objetivo = o; }
void PlanoDeSprint::setCapacidade(const Tempo& cap) { capacidade = cap; }

void PlanoDeSprint::adicionarHistoria(const std::string& codigoHistoria, int estimativaHistoria) {
    if (std::find(historiasAssociadas.begin(), historiasAssociadas.end(), codigoHistoria) != historiasAssociadas.end()) {
        throw std::invalid_argument("História já associada a este sprint.");
    }
    int novaSoma = somaEstimativas() + estimativaHistoria;
    if (novaSoma > capacidade.getValor()) {
        throw std::invalid_argument("Soma das estimativas excede a capacidade do sprint.");
    }
    historiasAssociadas.push_back(codigoHistoria);
}

void PlanoDeSprint::removerHistoria(const std::string& codigoHistoria) {
    auto it = std::find(historiasAssociadas.begin(), historiasAssociadas.end(), codigoHistoria);
    if (it != historiasAssociadas.end()) {
        historiasAssociadas.erase(it);
    }
}

int PlanoDeSprint::somaEstimativas() const {

    return 0;
}

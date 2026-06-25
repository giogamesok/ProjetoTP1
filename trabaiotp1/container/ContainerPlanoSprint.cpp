#include "ContainerPlanoSprint.hpp"
#include <stdexcept>

void ContainerPlanoSprint::inserir(const PlanoDeSprint& p) {
    dados[p.getCodigo().getValor()] = p;
}

PlanoDeSprint ContainerPlanoSprint::buscar(const std::string& codigo) const {
    auto it = dados.find(codigo);
    if (it == dados.end()) throw std::out_of_range("Plano de sprint não encontrado.");
    return it->second;
}

void ContainerPlanoSprint::atualizar(const PlanoDeSprint& p) {
    std::string chave = p.getCodigo().getValor();
    auto it = dados.find(chave);
    if (it == dados.end()) throw std::invalid_argument("Plano de sprint não encontrado.");
    it->second = p;
}

void ContainerPlanoSprint::remover(const std::string& codigo) {
    dados.erase(codigo);
}

std::vector<PlanoDeSprint> ContainerPlanoSprint::listar() const {
    std::vector<PlanoDeSprint> lista;
    for (const auto& par : dados) lista.push_back(par.second);
    return lista;
}

bool ContainerPlanoSprint::existe(const std::string& codigo) const {
    return dados.find(codigo) != dados.end();
}

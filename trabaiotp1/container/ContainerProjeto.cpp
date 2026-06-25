#include "ContainerProjeto.hpp"
#include <stdexcept>

void ContainerProjeto::inserir(const Projeto& p) {
    dados[p.getCodigo().getValor()] = p;
}

Projeto ContainerProjeto::buscar(const std::string& codigo) const {
    auto it = dados.find(codigo);
    if (it == dados.end()) throw std::out_of_range("Projeto não encontrado.");
    return it->second;
}

void ContainerProjeto::atualizar(const Projeto& p) {
    std::string chave = p.getCodigo().getValor();
    auto it = dados.find(chave);
    if (it == dados.end()) throw std::invalid_argument("Projeto não encontrado.");
    it->second = p;
}

void ContainerProjeto::remover(const std::string& codigo) {
    dados.erase(codigo);
}

std::vector<Projeto> ContainerProjeto::listar() const {
    std::vector<Projeto> lista;
    for (const auto& par : dados) lista.push_back(par.second);
    return lista;
}

bool ContainerProjeto::existe(const std::string& codigo) const {
    return dados.find(codigo) != dados.end();
}

#include "ContainerHistoria.hpp"
#include <stdexcept>

void ContainerHistoria::inserir(const HistoriaDeUsuario& h) {
    dados[h.getCodigo().getValor()] = h;
}

HistoriaDeUsuario ContainerHistoria::buscar(const std::string& codigo) const {
    auto it = dados.find(codigo);
    if (it == dados.end()) throw std::out_of_range("História não encontrada.");
    return it->second;
}

void ContainerHistoria::atualizar(const HistoriaDeUsuario& h) {
    std::string chave = h.getCodigo().getValor();
    auto it = dados.find(chave);
    if (it == dados.end()) throw std::invalid_argument("História não encontrada.");
    it->second = h;
}

void ContainerHistoria::remover(const std::string& codigo) {
    dados.erase(codigo);
}

std::vector<HistoriaDeUsuario> ContainerHistoria::listar() const {
    std::vector<HistoriaDeUsuario> lista;
    for (const auto& par : dados) lista.push_back(par.second);
    return lista;
}

bool ContainerHistoria::existe(const std::string& codigo) const {
    return dados.find(codigo) != dados.end();
}

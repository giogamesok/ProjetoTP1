#include "ContainerPessoa.hpp"
#include <stdexcept>

void ContainerPessoa::inserir(const Pessoa& p) {
    std::string chave = p.getEmail().getValor();
    dados[chave] = p;
}

Pessoa ContainerPessoa::buscar(const std::string& email) const {
    auto it = dados.find(email);
    if (it == dados.end())
        throw std::out_of_range("Pessoa não encontrada.");
    return it->second;
}

void ContainerPessoa::atualizar(const Pessoa& p) {
    std::string chave = p.getEmail().getValor();
    auto it = dados.find(chave);
    if (it == dados.end())
        throw std::invalid_argument("Pessoa não encontrada.");
    it->second = p;
}

void ContainerPessoa::remover(const std::string& email) {
    dados.erase(email);
}

std::vector<Pessoa> ContainerPessoa::listar() const {
    std::vector<Pessoa> lista;
    for (const auto& par : dados)
        lista.push_back(par.second);
    return lista;
}

bool ContainerPessoa::existe(const std::string& email) const {
    return dados.find(email) != dados.end();
}

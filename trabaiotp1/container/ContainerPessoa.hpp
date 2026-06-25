#ifndef CONTAINER_PESSOA_HPP
#define CONTAINER_PESSOA_HPP

#include "pessoa.hpp"
#include <map>
#include <string>
#include <vector>

/**
 * @class ContainerPessoa
 * @brief Armazena objetos Pessoa em memória usando std::map com chave = email.
 */
class ContainerPessoa {
private:
    std::map<std::string, Pessoa> dados;
public:
    void inserir(const Pessoa& p);
    Pessoa buscar(const std::string& email) const;
    void atualizar(const Pessoa& p);
    void remover(const std::string& email);
    std::vector<Pessoa> listar() const;
    bool existe(const std::string& email) const;
};

#endif

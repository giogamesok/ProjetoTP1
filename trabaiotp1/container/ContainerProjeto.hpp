#ifndef CONTAINER_PROJETO_HPP
#define CONTAINER_PROJETO_HPP

#include "projeto.hpp"
#include <map>
#include <string>
#include <vector>

/**
 * @class ContainerProjeto
 * @brief Armazena objetos Projeto em memória com chave = código.
 */
class ContainerProjeto {
private:
    std::map<std::string, Projeto> dados;
public:
    void inserir(const Projeto& p);
    Projeto buscar(const std::string& codigo) const;
    void atualizar(const Projeto& p);
    void remover(const std::string& codigo);
    std::vector<Projeto> listar() const;
    bool existe(const std::string& codigo) const;
};

#endif

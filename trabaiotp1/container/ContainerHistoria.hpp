#ifndef CONTAINER_HISTORIA_HPP
#define CONTAINER_HISTORIA_HPP

#include "historia_de_usuario.hpp"
#include <map>
#include <string>
#include <vector>

class ContainerHistoria {
private:
    std::map<std::string, HistoriaDeUsuario> dados;
public:
    void inserir(const HistoriaDeUsuario& h);
    HistoriaDeUsuario buscar(const std::string& codigo) const;
    void atualizar(const HistoriaDeUsuario& h);
    void remover(const std::string& codigo);
    std::vector<HistoriaDeUsuario> listar() const;
    bool existe(const std::string& codigo) const;
};

#endif

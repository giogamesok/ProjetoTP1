#ifndef CONTAINER_PLANO_SPRINT_HPP
#define CONTAINER_PLANO_SPRINT_HPP

#include "plano_de_sprint.hpp"
#include <map>
#include <string>
#include <vector>

class ContainerPlanoSprint {
private:
    std::map<std::string, PlanoDeSprint> dados;
public:
    void inserir(const PlanoDeSprint& p);
    PlanoDeSprint buscar(const std::string& codigo) const;
    void atualizar(const PlanoDeSprint& p);
    void remover(const std::string& codigo);
    std::vector<PlanoDeSprint> listar() const;
    bool existe(const std::string& codigo) const;
};

#endif

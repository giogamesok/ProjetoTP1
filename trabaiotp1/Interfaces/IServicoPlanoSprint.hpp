#ifndef ISERVICO_PLANO_SPRINT_HPP
#define ISERVICO_PLANO_SPRINT_HPP

#include "plano_de_sprint.hpp"
#include <vector>
#include <string>

class IServicoPlanoSprint {
public:
    virtual ~IServicoPlanoSprint() {}

    virtual void criar(const PlanoDeSprint& plano, const std::string& codigoProjeto) = 0;
    virtual PlanoDeSprint ler(const std::string& codigo) const = 0;
    virtual void atualizar(const PlanoDeSprint& plano) = 0;
    virtual void excluir(const std::string& codigo) = 0;
    virtual std::vector<PlanoDeSprint> listarTodos() const = 0;

    virtual std::vector<PlanoDeSprint> listarPorProjeto(const std::string& codigoProjeto) const = 0;
    virtual void adicionarHistoriaAoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) = 0;
    virtual void removerHistoriaDoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) = 0;
};

#endif

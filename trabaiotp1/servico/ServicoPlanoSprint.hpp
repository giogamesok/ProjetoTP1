#ifndef SERVICO_PLANO_SPRINT_HPP
#define SERVICO_PLANO_SPRINT_HPP

#include "IServicoPlanoSprint.hpp"
#include "ContainerPlanoSprint.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerHistoria.hpp"

class ServicoPlanoSprint : public IServicoPlanoSprint {
private:
    ContainerPlanoSprint* containerSprint;
    ContainerProjeto* containerProjeto;
    ContainerHistoria* containerHistoria;
    std::map<std::string, std::string> sprintProjeto;
public:
    ServicoPlanoSprint(ContainerPlanoSprint* cs, ContainerProjeto* cp, ContainerHistoria* ch);
    void criar(const PlanoDeSprint& plano, const std::string& codigoProjeto) override;
    PlanoDeSprint ler(const std::string& codigo) const override;
    void atualizar(const PlanoDeSprint& plano) override;
    void excluir(const std::string& codigo) override;
    std::vector<PlanoDeSprint> listarTodos() const override;
    std::vector<PlanoDeSprint> listarPorProjeto(const std::string& codigoProjeto) const override;
    void adicionarHistoriaAoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) override;
    void removerHistoriaDoSprint(const std::string& codigoSprint, const std::string& codigoHistoria) override;
    bool verificarCapacidadeTotalProjeto(const std::string& codigoProjeto) const;
};

#endif

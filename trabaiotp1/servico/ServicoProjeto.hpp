/**
 * @file ServicoProjeto.hpp
 * @brief Definição do serviço para a entidade Projeto.
 */

#ifndef SERVICO_PROJETO_HPP
#define SERVICO_PROJETO_HPP

#include "IServicoProjeto.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerPessoa.hpp"

class ServicoProjeto : public IServicoProjeto {
private:
    ContainerProjeto* containerProjeto;
    ContainerPessoa* containerPessoa;
public:
    ServicoProjeto(ContainerProjeto* cp, ContainerPessoa* cpes);
    void criar(const Projeto& projeto, const std::string& emailScrumMaster) override;
    Projeto ler(const std::string& codigo) const override;
    void atualizar(const Projeto& projeto) override;
    void excluir(const std::string& codigo) override;
    std::vector<Projeto> listarTodos() const override;
    std::vector<Projeto> listarProjetosPorPessoa(const std::string& email) const override;
};

#endif

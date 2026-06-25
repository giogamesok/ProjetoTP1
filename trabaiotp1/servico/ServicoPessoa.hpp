#ifndef SERVICO_PESSOA_HPP
#define SERVICO_PESSOA_HPP

#include "IServicoPessoa.hpp"
#include "ContainerPessoa.hpp"

/**
 * @class ServicoPessoa
 * @brief Implementação concreta do serviço de Pessoa.
 */
class ServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa* container; ///< Repositório de pessoas.
public:
    ServicoPessoa(ContainerPessoa* cont);
    void criar(const Pessoa& pessoa) override;
    Pessoa ler(const std::string& email) const override;
    void atualizar(const Pessoa& pessoa) override;
    void excluir(const std::string& email) override;
    std::vector<Pessoa> listarTodos() const override;
};

#endif

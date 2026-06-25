#ifndef ISERVICO_PESSOA_HPP
#define ISERVICO_PESSOA_HPP

#include "pessoa.hpp"
#include <vector>
#include <string>

/**
 * @class IServicoPessoa
 * @brief Interface para serviços relacionados à entidade Pessoa.
 *
 * @details Define as operações CRUD e listagem para Pessoa.
 *          A camada de apresentação depende unicamente desta interface.
 */
class IServicoPessoa {
public:
    virtual ~IServicoPessoa() {}

    /**
     * @brief Cria uma nova pessoa.
     * @param pessoa Objeto contendo os dados da pessoa.
     * @throw std::invalid_argument Se o e-mail já existir ou dados inválidos.
     */
    virtual void criar(const Pessoa& pessoa) = 0;

    /**
     * @brief Lê uma pessoa pelo e-mail.
     * @param email Chave primária.
     * @return Pessoa copiada.
     * @throw std::out_of_range Se não encontrada.
     */
    virtual Pessoa ler(const std::string& email) const = 0;

    /**
     * @brief Atualiza os dados de uma pessoa.
     * @param pessoa Objeto com novos dados (o e-mail não pode ser alterado).
     * @throw std::invalid_argument Se a pessoa não existir.
     */
    virtual void atualizar(const Pessoa& pessoa) = 0;

    /**
     * @brief Exclui uma pessoa pelo e-mail.
     * @param email Chave.
     * @throw std::invalid_argument Se não existir.
     */
    virtual void excluir(const std::string& email) = 0;

    /**
     * @brief Lista todas as pessoas.
     * @return Vetor com todas as pessoas.
     */
    virtual std::vector<Pessoa> listarTodos() const = 0;
};

#endif

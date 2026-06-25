/**
 * @file ControladoraPessoa.hpp
 * @brief Controladora para operações de Pessoa na camada de apresentação.
 */

#ifndef CONTROLADORA_PESSOA_HPP
#define CONTROLADORA_PESSOA_HPP

#include "IServicoPessoa.hpp"
#include <string>

/**
 * @class ControladoraPessoa
 * @brief Gerencia a interação com o usuário para operações CRUD de Pessoa.
 *
 * @details Depende da interface IServicoPessoa, não da implementação concreta.
 *          Exibe menus, coleta dados, valida entrada e chama os serviços.
 */
class ControladoraPessoa {
private:
    IServicoPessoa* servico; ///< Ponteiro para o serviço de Pessoa.

public:
    /**
     * @brief Construtor que injeta a dependência do serviço.
     * @param srv Ponteiro para um objeto que implementa IServicoPessoa.
     */
    ControladoraPessoa(IServicoPessoa* srv);

    /**
     * @brief Exibe o menu principal para gerenciar pessoas.
     */
    void executarMenu();

    /**
     * @brief Cadastra uma nova pessoa.
     */
    void cadastrar();

    /**
     * @brief Lista todas as pessoas cadastradas.
     */
    void listar();

    /**
     * @brief Consulta os dados de uma pessoa pelo email.
     */
    void consultar();

    /**
     * @brief Atualiza os dados de uma pessoa.
     */
    void atualizar();

    /**
     * @brief Exclui uma pessoa pelo email.
     */
    void excluir();
};

#endif

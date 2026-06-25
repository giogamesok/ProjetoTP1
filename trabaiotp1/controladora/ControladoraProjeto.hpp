/**
 * @file ControladoraProjeto.hpp
 * @brief Controladora para operações de Projeto na camada de apresentação.
 */

#ifndef CONTROLADORA_PROJETO_HPP
#define CONTROLADORA_PROJETO_HPP

#include "IServicoProjeto.hpp"
#include "IServicoPessoa.hpp"
#include <string>

/**
 * @class ControladoraProjeto
 * @brief Gerencia a interação com o usuário para operações CRUD de Projeto.
 */
class ControladoraProjeto {
private:
    IServicoProjeto* servicoProjeto;
    IServicoPessoa* servicoPessoa;

public:
    ControladoraProjeto(IServicoProjeto* sp, IServicoPessoa* spess);

    void executarMenu();
    void cadastrar();
    void listar();
    void consultar();
    void atualizar();
    void excluir();
    void listarPorPessoa();
};

#endif

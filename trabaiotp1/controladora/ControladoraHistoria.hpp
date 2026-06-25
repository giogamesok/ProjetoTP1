/**
 * @file ControladoraHistoria.hpp
 * @brief Controladora para operações de História de Usuário.
 */

#ifndef CONTROLADORA_HISTORIA_HPP
#define CONTROLADORA_HISTORIA_HPP

#include "IServicoHistoria.hpp"
#include "IServicoProjeto.hpp"
#include "IServicoPessoa.hpp"
#include <string>

class ControladoraHistoria {
private:
    IServicoHistoria* servicoHistoria;
    IServicoProjeto* servicoProjeto;
    IServicoPessoa* servicoPessoa;

public:
    ControladoraHistoria(IServicoHistoria* sh, IServicoProjeto* sp, IServicoPessoa* spess);

    void executarMenu();
    void cadastrar();
    void listar();
    void consultar();
    void atualizar();
    void excluir();
    void listarPorProjeto();
    void associarDesenvolvedor();
    void desassociarDesenvolvedor();
};

#endif

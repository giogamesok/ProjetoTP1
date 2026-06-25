/**
 * @file ControladoraPlanoSprint.hpp
 * @brief Controladora para operações de Plano de Sprint.
 */

#ifndef CONTROLADORA_PLANO_SPRINT_HPP
#define CONTROLADORA_PLANO_SPRINT_HPP

#include "IServicoPlanoSprint.hpp"
#include "IServicoProjeto.hpp"
#include "IServicoHistoria.hpp"
#include <string>

class ControladoraPlanoSprint {
private:
    IServicoPlanoSprint* servicoPlano;
    IServicoProjeto* servicoProjeto;
    IServicoHistoria* servicoHistoria;

public:
    ControladoraPlanoSprint(IServicoPlanoSprint* sp, IServicoProjeto* sproj, IServicoHistoria* shist);

    void executarMenu();
    void cadastrar();
    void listar();
    void consultar();
    void atualizar();
    void excluir();
    void listarPorProjeto();
    void adicionarHistoria();
    void removerHistoria();
};

#endif

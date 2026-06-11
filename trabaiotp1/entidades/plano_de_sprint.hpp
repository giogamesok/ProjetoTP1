/**
 * @file PlanoDeSprint.hpp
 * @brief Definição da classe entidade PlanoDeSprint.
 */


#ifndef PLANO_DE_SPRINT_HPP_INCLUDED
#define PLANO_DE_SPRINT_HPP_INCLUDED


#include "codigo.hpp"
#include "texto.hpp"
#include "tempo.hpp"
#include <vector>
#include <string>

/**
 * @class PlanoDeSprint
 * @brief Representa um plano de sprint dentro de um projeto Scrum.
 *
 * @details Cada sprint tem um codigo unico, um objetivo textual, uma capacidade
 *          (em dias) e uma colecao de codigos de historias de usuario associadas.
 *          A soma das estimativas das historias nao pode ultrapassar a capacidade.
 *          As regras de capacidade total do projeto devem ser verificadas na camada de servico.
 *
 * @see Projeto
 * @see HistoriaDeUsuario
 */
class PlanoDeSprint {
private:
    Codigo codigo;                        ///< Codigo unico do sprint (formato: 2 letras + 3 digitos)
    Texto objetivo;                       ///< Descricao do objetivo do sprint (max. 40 caracteres)
    Tempo capacidade;                     ///< Capacidade total do sprint em dias (1 a 365)
    std::vector<std::string> historiasAssociadas; ///< Codigos das historias de usuario incluidas no sprint

public:
    /**
     * @brief Construtor padrao.
     */
    PlanoDeSprint();

    /**
     * @brief Construtor com parametros essenciais.
     * @param codigo Codigo do sprint.
     * @param objetivo Objetivo textual do sprint.
     * @param capacidade Capacidade total em dias.
     */
    PlanoDeSprint(const Codigo& codigo, const Texto& objetivo, const Tempo& capacidade);

    /// @name Getters
    /// @{
    Codigo getCodigo() const;
    Texto getObjetivo() const;
    Tempo getCapacidade() const;
    const std::vector<std::string>& getHistoriasAssociadas() const;
    /// @}

    /// @name Setters (lancam excecao se invalido)
    /// @{
    void setCodigo(const Codigo& codigo);
    void setObjetivo(const Texto& objetivo);
    void setCapacidade(const Tempo& capacidade);
    /// @}

    /**
     * @brief Adiciona uma historia de usuario ao sprint.
     * @param codigoHistoria Codigo da historia a ser adicionada.
     * @param estimativaHistoria Estimativa da historia (em dias).
     * @throw std::invalid_argument Se a historia ja estiver associada ou
     *        se a soma das estimativas ultrapassar a capacidade do sprint.
     */
    void adicionarHistoria(const std::string& codigoHistoria, int estimativaHistoria);

    /**
     * @brief Remove uma historia de usuario do sprint.
     * @param codigoHistoria Codigo da historia a ser removida.
     */
    void removerHistoria(const std::string& codigoHistoria);

    /**
     * @brief Calcula a soma das estimativas das historias associadas.
     * @return Soma em dias (como inteiro).
     */
    int somaEstimativas() const;
};

#endif

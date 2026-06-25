/**
 * @file Projeto.hpp
 * @brief Definição da classe entidade Projeto.
 */

#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "Codigo.hpp"
#include "Nome.hpp"
#include "Data.hpp"

/**
 * @class Projeto
 * @brief Representa um projeto no sistema Scrum.
 * @details Possui código (chave), nome, datas de início e término.
 *          O código é a chave primária e não deve ser alterado.
 */
class Projeto {
private:
    Codigo codigo;  ///< Código único do projeto
    Nome nome;
    Data inicio;
    Data termino;

public:
    /**
     * @brief Construtor padrão.
     */
    Projeto();

    /**
     * @brief Construtor com todos os atributos.
     * @param codigo Código do projeto.
     * @param nome Nome do projeto.
     * @param inicio Data de início.
     * @param termino Data de término.
     */
    Projeto(const Codigo& codigo, const Nome& nome, const Data& inicio, const Data& termino);

    /// @name Getters
    /// @{
    Codigo getCodigo() const;
    Nome getNome() const;
    Data getInicio() const;
    Data getTermino() const;
    /// @}

    /// @name Setters (código não deve ser alterado)
    /// @{
    void setCodigo(const Codigo& codigo);
    void setNome(const Nome& nome);
    void setInicio(const Data& inicio);
    void setTermino(const Data& termino);
    /// @}
};

#endif

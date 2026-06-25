/**
 * @file Pessoa.hpp
 * @brief Definição da classe entidade Pessoa.
 */

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "Email.hpp"
#include "Nome.hpp"
#include "Senha.hpp"
#include "Papel.hpp"

/**
 * @class Pessoa
 * @brief Representa uma pessoa (usuário) do sistema.
 * @details Possui email (chave), nome, senha e papel no projeto.
 *          O email é a chave primária e não deve ser alterado após a criação.
 */
class Pessoa {
private:
    Email email;   ///< E-mail (chave primária)
    Nome nome;
    Senha senha;
    Papel papel;

public:
    /**
     * @brief Construtor padrão.
     */
    Pessoa();

    /**
     * @brief Construtor com todos os atributos.
     * @param email E-mail da pessoa.
     * @param nome Nome da pessoa.
     * @param senha Senha da pessoa.
     * @param papel Papel da pessoa.
     */
    Pessoa(const Email& email, const Nome& nome, const Senha& senha, const Papel& papel);

    /// @name Getters
    /// @{
    Email getEmail() const;
    Nome getNome() const;
    Senha getSenha() const;
    Papel getPapel() const;
    /// @}

    /// @name Setters (o email não deve ser alterado; mantemos apenas para completude)
    /// @{
    void setEmail(const Email& email);    // Use com cuidado
    void setNome(const Nome& nome);
    void setSenha(const Senha& senha);
    void setPapel(const Papel& papel);
    /// @}
};

#endif

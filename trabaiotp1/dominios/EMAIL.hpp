/**
 * @file EMAIL.hpp
 * @brief Definicao da classe de dominio Email.
 */

#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <stdexcept>

/**
 * @class Email
 * @brief Representa um endereco de e-mail com validacao rigorosa conforme especificacao.
 *
 * @details Formato: local@dominio. Valida caracteres, pontos, hifens e comprimentos.
 */
class Email {
private:
    std::string valor; ///< Armazena o e-mail.

public:
    /**
     * @brief Construtor padrao. Inicializa com string vazia.
     */
    Email();

    /**
     * @brief Construtor com inicializacao.
     * @param valor String contendo o e-mail.
     * @throw std::invalid_argument Se o formato for invalido.
     */
    Email(const std::string& valor);

    /**
     * @brief Retorna o e-mail.
     * @return std::string Endereco de e-mail.
     */
    std::string getValor() const;

    /**
     * @brief Define um novo e-mail.
     * @param novoValor String com o novo e-mail.
     * @throw std::invalid_argument Se o formato for invalido.
     */
    void setValor(const std::string& novoValor);

    /**
     * @brief Verifica se uma string e um e-mail valido.
     * @param valor String a ser testada.
     * @return true se valido, false caso contrario.
     */
    static bool validar(const std::string& valor);
};

#endif

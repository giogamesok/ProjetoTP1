/**
 * @file codigo.hpp
 * @brief Definição da classe de domínio Codigo.
 */

#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>
#include <stdexcept>

/**
 * @class Codigo
 * @brief Representa um codigo com formato especifico: 2 letras maiusculas + 3 digitos.
 *
 * @details Formato valido: AA999 (ex: AB123). O codigo e imutavel apos definido,
 *          mas pode ser alterado via set desde que o novo valor seja valido.
 */
class Codigo {
private:
    std::string valor; ///< Armazena o codigo.

public:
    /**
     * @brief Construtor padrao. Inicializa com string vazia.
     */
    Codigo();

    /**
     * @brief Construtor com inicializacao.
     * @param valor String contendo o codigo.
     * @throw std::invalid_argument Se o formato for invalido.
     */
    Codigo(const std::string& valor);

    /**
     * @brief Retorna o codigo armazenado.
     * @return std::string Codigo.
     */
    std::string getValor() const;

    /**
     * @brief Define um novo codigo.
     * @param novoValor String com o novo codigo.
     * @throw std::invalid_argument Se o formato for invalido.
     */
    void setValor(const std::string& novoValor);

    /**
     * @brief Verifica se uma string e um codigo valido.
     * @param valor String a ser testada.
     * @return true se valido, false caso contrario.
     */
    static bool validar(const std::string& valor);
};

#endif

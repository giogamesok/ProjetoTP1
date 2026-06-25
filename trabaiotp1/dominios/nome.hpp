/**
 * @file Nome.hpp
 * @brief Definição da classe de domínio Nome.
 */

#ifndef NOME_HPP
#define NOME_HPP

#include <string>
#include <stdexcept>

/**
 * @class Nome
 * @brief Representa um nome próprio com validação de formato.
 * @details Até 10 caracteres, apenas letras e espaços;
 *          não pode iniciar/terminar com espaço; espaço seguido por letra.
 */
class Nome {
private:
    std::string valor; ///< Armazena o nome.

public:
    /**
     * @brief Construtor padrão – inicializa com string vazia.
     */
    Nome();

    /**
     * @brief Construtor com inicialização.
     * @param valor String contendo o nome.
     * @throw std::invalid_argument Se o formato for inválido.
     */
    Nome(const std::string& valor);

    /**
     * @brief Retorna o nome armazenado.
     * @return std::string Nome.
     */
    std::string getValor() const;

    /**
     * @brief Define um novo nome.
     * @param novoValor String com o novo nome.
     * @throw std::invalid_argument Se o formato for inválido.
     */
    void setValor(const std::string& novoValor);

    /**
     * @brief Verifica se uma string é um nome válido.
     * @param valor String a ser testada.
     * @return true se válido, false caso contrário.
     */
    static bool validar(const std::string& valor);
};

#endif

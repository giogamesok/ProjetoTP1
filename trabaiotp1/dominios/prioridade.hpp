/**
 * @file Prioridade.hpp
 * @brief Definição da classe de domínio Prioridade.
 */

#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

#include <string>
#include <stdexcept>

/**
 * @class Prioridade
 * @brief Representa a prioridade de uma história de usuário.
 *
 * @details Os valores válidos são: "ALTA", "MEDIA", "BAIXA".
 *          A classe valida o valor no momento da criação ou alteração.
 */
class Prioridade {
private:
    std::string valor; ///< Armazena a prioridade como string.

public:
    /**
     * @brief Construtor padrão. Inicializa com "MEDIA".
     */
    Prioridade();

    /**
     * @brief Construtor com parâmetro.
     * @param valor String contendo a prioridade.
     * @throw std::invalid_argument Se o valor não for válido.
     */
    Prioridade(const std::string& valor);

    /**
     * @brief Retorna a prioridade armazenada.
     * @return std::string Prioridade.
     */
    std::string getValor() const;

    /**
     * @brief Define uma nova prioridade.
     * @param novoValor Novo valor.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setValor(const std::string& novoValor);

    /**
     * @brief Verifica se uma string é uma prioridade válida.
     * @param valor String a ser testada.
     * @return true se válida, false caso contrário.
     */
    static bool validar(const std::string& valor);
};

#endif


/**
 * @file data.hpp
 * @brief Definicao da classe de dominio Data.
 */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <stdexcept>

/**
 * @class Data
 * @brief Representa uma data no formato DD/MM/AAAA com validacao completa.
 *
 * @details Valida dias por mes, anos bissextos e intervalo de ano (2000-2999).
 */
class Data {
private:
    std::string valor; ///< Data armazenada como string no formato DD/MM/AAAA.

public:
    /**
     * @brief Construtor padrao. Inicializa com string vazia.
     */
    Data();

    /**
     * @brief Construtor com inicializacao.
     * @param valor String no formato DD/MM/AAAA.
     * @throw std::invalid_argument Se a data for invalida.
     */
    Data(const std::string& valor);

    /**
     * @brief Retorna a data.
     * @return std::string Data no formato DD/MM/AAAA.
     */
    std::string getValor() const;

    /**
     * @brief Define uma nova data.
     * @param novoValor String com a nova data.
     * @throw std::invalid_argument Se a data for invalida.
     */
    void setValor(const std::string& novoValor);

    /**
     * @brief Verifica se uma string representa uma data valida.
     * @param valor String no formato DD/MM/AAAA.
     * @return true se valida, false caso contrario.
     */
    static bool validar(const std::string& valor);
};

#endif

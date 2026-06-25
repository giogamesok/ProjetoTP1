/**
 * @file Papel.hpp
 * @brief Definição da classe de domínio Papel.
 */

#ifndef PAPEL_HPP
#define PAPEL_HPP

#include <string>
#include <stdexcept>

/**
 * @class Papel
 * @brief Representa o papel de uma pessoa no projeto.
 * @details Valores permitidos: DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO.
 */
class Papel {
private:
    std::string valor;

public:
    Papel();
    Papel(const std::string& valor);
    std::string getValor() const;
    void setValor(const std::string& novoValor);
    static bool validar(const std::string& valor);
};

#endif

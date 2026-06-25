/**
 * @file Texto.hpp
 * @brief Definição da classe de domínio Texto.
 */

#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
#include <stdexcept>

/**
 * @class Texto
 * @brief Representa um texto genérico com validação de formato.
 * @details Até 40 caracteres, letras, dígitos, vírgula, ponto e espaço;
 *          regras específicas para pontuação e espaços.
 */
class Texto {
private:
    std::string valor;
public:
    Texto();
    Texto(const std::string& valor);
    std::string getValor() const;
    void setValor(const std::string& novoValor);
    static bool validar(const std::string& valor);
};

#endif

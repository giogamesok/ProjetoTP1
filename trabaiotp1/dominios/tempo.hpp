/**
 * @file Tempo.hpp
 * @brief Definição da classe de domínio Tempo.
 */

#ifndef TEMPO_HPP
#define TEMPO_HPP

#include <stdexcept>

/**
 * @class Tempo
 * @brief Representa uma quantidade de dias (estimativa ou capacidade).
 * @details Valor inteiro entre 1 e 365.
 */
class Tempo {
private:
    int valor;

public:
    Tempo();
    Tempo(int valor);
    int getValor() const;
    void setValor(int novoValor);
    static bool validar(int valor);
};

#endif

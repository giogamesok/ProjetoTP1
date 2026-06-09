/**
 * @file codigo.cpp
 * @brief Implementação da classe Codigo.
 */

#include "codigo.hpp"
#include <cctype>
#include <regex>

Codigo::Codigo() : valor("") {}

Codigo::Codigo(const std::string& valor) {
    setValor(valor);
}

std::string Codigo::getValor() const {
    return valor;
}

void Codigo::setValor(const std::string& novoValor) {
    if (!validar(novoValor)) {
        throw std::invalid_argument("Codigo invalido. Formato: 2 letras maiusculas seguidas de 3 digitos.");
    }
    valor = novoValor;
}

bool Codigo::validar(const std::string& valor) {
    std::regex padrao("^[A-Z]{2}[0-9]{3}$");
    return std::regex_match(valor, padrao);
}

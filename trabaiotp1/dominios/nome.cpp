/**
 * @file Nome.cpp
 * @brief Implementação da classe Nome.
 */

#include "nome.hpp"
#include <cctype>

Nome::Nome() : valor("") {}

Nome::Nome(const std::string& v) {
    setValor(v);
}

std::string Nome::getValor() const {
    return valor;
}

void Nome::setValor(const std::string& v) {
    if (!validar(v)) {
        throw std::invalid_argument("Nome invalido: max 10 caracteres, apenas letras e espacos, sem espacos nas bordas.");
    }
    valor = v;
}

bool Nome::validar(const std::string& v) {
    if (v.empty() || v.length() > 10) return false;
    if (v.front() == ' ' || v.back() == ' ') return false;

    for (size_t i = 0; i < v.length(); ++i) {
        char c = v[i];
        if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ') return false;
        if (c == ' ' && (i == 0 || i == v.length()-1 || !std::isalpha(v[i+1]))) return false;
    }
    return true;
}

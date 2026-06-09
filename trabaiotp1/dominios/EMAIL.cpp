/**
 * @file EMAIL.cpp
 * @brief Implementacao da classe Email.
 */

#include "EMAIL.hpp"
#include <regex>
#include <cctype>

Email::Email() : valor("") {}

Email::Email(const std::string& valor) {
    setValor(valor);
}

std::string Email::getValor() const {
    return valor;
}

void Email::setValor(const std::string& novoValor) {
    if (!validar(novoValor)) {
        throw std::invalid_argument("Email invalido. Verifique formato, pontos, hifens e comprimentos.");
    }
    valor = novoValor;
}

bool Email::validar(const std::string& valor) {
    std::regex padrao(
        "^(?!\\.)(?!.*\\.$)(?!.*-)(?!.*--)(?!.*\\.\\.)[a-z0-9][a-z0-9.-]{0,62}[a-z0-9]"
        "@"
        "(?!-)([a-z0-9-]{1,63}\\.)+[a-z0-9]{1,63}$",
        std::regex::icase
    );
    if (!std::regex_match(valor, padrao)) return false;


    size_t arrobaPos = valor.find('@');
    std::string local = valor.substr(0, arrobaPos);
    std::string dominio = valor.substr(arrobaPos + 1);
    if (local.length() > 64 || dominio.length() > 255) return false;

    return true;
}

#include "texto.hpp"
#include <cctype>

Texto::Texto() : valor("") {}

Texto::Texto(const std::string& v) {
    setValor(v);
}

std::string Texto::getValor() const {
    return valor;
}

void Texto::setValor(const std::string& v) {
    if (!validar(v)) {
        throw std::invalid_argument("Texto invalido");
    }
    valor = v;
}

bool Texto::validar(const std::string& v) {

    return true;
}

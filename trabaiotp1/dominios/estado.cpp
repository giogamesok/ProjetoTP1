#include "estado.hpp"

Estado::Estado() : valor("A FAZER") {}

Estado::Estado(const std::string& v) {
    setValor(v);
}

std::string Estado::getValor() const {
    return valor;
}

void Estado::setValor(const std::string& v) {
    if (!validar(v)) {
        throw std::invalid_argument("Estado deve ser A FAZER, FAZENDO ou FEITO.");
    }
    valor = v;
}

bool Estado::validar(const std::string& v) {   // retorna bool, igual à declaração
    return (v == "A FAZER" || v == "FAZENDO" || v == "FEITO");
}

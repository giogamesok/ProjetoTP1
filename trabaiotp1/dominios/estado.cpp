#include "estado.hpp"

void Estado::validar(string valor) {
    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO") {
        throw invalid_argument("Estado invalido. Valores aceitos: A FAZER, FAZENDO, FEITO.");
    }
}

void Estado::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

#include "tempo.hpp"

Tempo::Tempo() : valor(1) {}

Tempo::Tempo(int v) {
    setValor(v);
}

int Tempo::getValor() const {
    return valor;
}

void Tempo::setValor(int v) {
    if (!validar(v)) {
        throw std::invalid_argument("Tempo deve ser um valor entre 1 e 365.");
    }
    valor = v;
}

bool Tempo::validar(int v) {
    return (v >= 1 && v <= 365);
}

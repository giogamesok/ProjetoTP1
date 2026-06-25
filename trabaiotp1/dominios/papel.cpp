#include "papel.hpp"

Papel::Papel() : valor("DESENVOLVEDOR") {}

Papel::Papel(const std::string& v) {
    setValor(v);
}

std::string Papel::getValor() const {
    return valor;
}

void Papel::setValor(const std::string& v) {
    if (!validar(v)) {
        throw std::invalid_argument("Papel invalido: deve ser DESENVOLVEDOR, MESTRE SCRUM ou PROPRIETARIO DE PRODUTO.");
    }
    valor = v;
}

bool Papel::validar(const std::string& v) {
    return (v == "DESENVOLVEDOR" || v == "MESTRE SCRUM" || v == "PROPRIETARIO DE PRODUTO");
}


/**
 * @file Prioridade.cpp
 * @brief Implementação da classe Prioridade.
 */

#include "prioridade.hpp"

Prioridade::Prioridade() : valor("MEDIA") {}

Prioridade::Prioridade(const std::string& v) {
    setValor(v);
}

std::string Prioridade::getValor() const {
    return valor;
}

void Prioridade::setValor(const std::string& novoValor) {
    if (!validar(novoValor)) {
        throw std::invalid_argument("Prioridade invalida. Valores permitidos: ALTA, MEDIA, BAIXA.");
    }
    valor = novoValor;
}

bool Prioridade::validar(const std::string& valor) {
    return valor == "ALTA" || valor == "MEDIA" || valor == "BAIXA";
}

#include "senha.hpp"
#include <cctype>

Senha::Senha() : valor("") {}

Senha::Senha(const std::string& v) {   // const ref
    setValor(v);
}

std::string Senha::getValor() const {
    return valor;
}

void Senha::setValor(const std::string& v) {
    if (!validar(v)) {
        throw std::invalid_argument("Senha invalida: 6 caracteres, letras e digitos, sem repeticoes de tipo.");
    }
    valor = v;
}

bool Senha::validar(const std::string& v) {
    if (v.length() != 6) return false;
    bool temMaiuscula = false, temMinuscula = false, temDigito = false;
    for (size_t i = 0; i < v.length(); ++i) {
        char c = v[i];
        if (std::isupper(static_cast<unsigned char>(c))) temMaiuscula = true;
        else if (std::islower(static_cast<unsigned char>(c))) temMinuscula = true;
        else if (std::isdigit(static_cast<unsigned char>(c))) temDigito = true;
        else return false;
        if (i > 0) {
            bool antLetra = std::isalpha(v[i-1]);
            bool atualLetra = std::isalpha(c);
            if (antLetra && atualLetra) return false;
            if (!antLetra && !atualLetra) return false;
        }
    }
    return temMaiuscula && temMinuscula && temDigito;
}

#include "texto.hpp"
#include <cctype>

void Texto::validar(std::string valor) {
    // Validação de tamanho
    if (valor.length() < 1 || valor.length() > 40)
        throw std::invalid_argument("Texto deve ter entre 1 e 40 caracteres.");

    // Validação de início e fim (deve ser letra ou dígito)
    if (!isalnum(valor.front()) || !isalnum(valor.back()))
        throw std::invalid_argument("Texto deve iniciar e terminar com letra ou digito.");

    // Validação de caracteres especiais em sequência
    for (size_t i = 0; i < valor.length() - 1; i++) {
        if ((ispunct(valor[i]) || isspace(valor[i])) && 
            (ispunct(valor[i+1]) || isspace(valor[i+1]))) {
            throw std::invalid_argument("Nao e permitido pontuacoes ou espacos em sequencia.");
        }
    }
}

void Texto::setValor(std::string valor) {
    validar(valor);
    this->valor = valor;
}

std::string Texto::getValor() const {
    return valor;
}

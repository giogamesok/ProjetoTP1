#include "senha.hpp"

void Senha::validar(string valor) {
    //a senha deve conter 6 (seis) caracteres.
    if (static_cast<int>(valor.length()) != TAMANHO) {
        throw invalid_argument("Senha invalida. Deve conter exatamente 6 caracteres.");
    }

    bool temMinuscula = false;
    bool temMaiuscula = false;
    bool temDigito    = false;

    for (int i = 0; i < TAMANHO; i++) {
        char atual = valor[i];

        bool ehMinuscula = (atual >= 'a' && atual <= 'z');
        bool ehMaiuscula = (atual >= 'A' && atual <= 'Z');
        bool ehLetra     = ehMinuscula || ehMaiuscula;
        bool ehDigito    = (atual >= '0' && atual <= '9');

        //cada caractere deve ser letra (a-z, A-Z) ou digito (0-9).
        if (!ehLetra && !ehDigito) {
            throw invalid_argument("Senha invalida. Use apenas letras e digitos.");
        }

        if (ehMinuscula) temMinuscula = true;
        if (ehMaiuscula) temMaiuscula = true;
        if (ehDigito)    temDigito    = true;

        //letra nao pode ser seguida por letra; digito nao pode ser seguido por digito.
        if (i > 0) {
            char anterior = valor[i - 1];

            bool anteriorLetra  = (anterior >= 'a' && anterior <= 'z') ||
                                  (anterior >= 'A' && anterior <= 'Z');
            bool anteriorDigito = (anterior >= '0' && anterior <= '9');

            if (anteriorLetra && ehLetra) {
                throw invalid_argument("Senha invalida. Letra nao pode ser seguida por letra.");
            }
            if (anteriorDigito && ehDigito) {
                throw invalid_argument("Senha invalida. Digito nao pode ser seguido por digito.");
            }
        }
    }

    //ao menos uma minuscula, uma maiuscula e um digito.
    if (!temMinuscula || !temMaiuscula || !temDigito) {
        throw invalid_argument("Senha invalida. Deve conter ao menos uma letra minuscula, "
                               "uma letra maiuscula e um digito.");
    }
}

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

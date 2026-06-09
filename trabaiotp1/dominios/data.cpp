/**
 * @file data.cpp
 * @brief Implementacao da classe Data.
 */

#include "data.hpp"
#include <sstream>
#include <iomanip>
#include <cctype>

static bool anoBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

Data::Data() : valor("") {}

Data::Data(const std::string& valor) {
    setValor(valor);
}

std::string Data::getValor() const {
    return valor;
}

void Data::setValor(const std::string& novoValor) {
    if (!validar(novoValor)) {
        throw std::invalid_argument("Data invalida. Formato: DD/MM/AAAA, ano entre 2000-2999, data real.");
    }
    valor = novoValor;
}

bool Data::validar(const std::string& valor) {
    if (valor.length() != 10) return false;
    if (valor[2] != '/' || valor[5] != '/') return false;

    int dia, mes, ano;
    std::istringstream iss(valor);
    char barra1, barra2;
    iss >> dia >> barra1 >> mes >> barra2 >> ano;
    if (iss.fail() || barra1 != '/' || barra2 != '/') return false;

    if (ano < 2000 || ano > 2999) return false;
    if (mes < 1 || mes > 12) return false;

    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (anoBissexto(ano)) diasNoMes[1] = 29;

    if (dia < 1 || dia > diasNoMes[mes - 1]) return false;

    return true;
}

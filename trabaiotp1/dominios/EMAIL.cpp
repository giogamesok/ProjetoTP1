/**
 * @file EMAIL.cpp
 * @brief Implementacao da classe Email.
 */

#include "EMAIL.hpp"
#include <cctype>
#include <algorithm>

static bool isAlfanumerico(char c) {
    return std::isalnum(static_cast<unsigned char>(c));
}

static bool isLetraDigitoHifenPonto(char c) {
    return isAlfanumerico(c) || c == '-' || c == '.';
}

static bool validarParteDominio(const std::string& parte) {
    if (parte.empty()) return false;
    if (parte.front() == '-' || parte.back() == '-') return false;
    for (char c : parte) {
        if (!isAlfanumerico(c) && c != '-') return false;
    }
    return true;
}

static bool validarLocal(const std::string& local) {
    if (local.empty() || local.length() > 64) return false;
    if (local.front() == '.' || local.front() == '-' ||
        local.back() == '.' || local.back() == '-') return false;

    for (size_t i = 0; i < local.length(); ++i) {
        char c = local[i];
        if (!isLetraDigitoHifenPonto(c)) return false;

        if ((c == '.' || c == '-') && i + 1 < local.length()) {
            char prox = local[i+1];
            if (!isAlfanumerico(prox)) return false;
        }
        if (c == '.' && i + 1 < local.length() && local[i+1] == '.') return false;
        if (c == '-' && i + 1 < local.length() && local[i+1] == '-') return false;
    }
    return true;
}


Email::Email() : valor("") {}

Email::Email(const std::string& valor) {
    setValor(valor);
}

std::string Email::getValor() const {
    return valor;
}

void Email::setValor(const std::string& novoValor) {
    if (!validar(novoValor)) {
        throw std::invalid_argument("Email invalido. Verifique formato, pontos, hifens e comprimentos.");
    }
    valor = novoValor;
}

bool Email::validar(const std::string& valor) {
    size_t arroba = valor.find('@');
    if (arroba == std::string::npos) return false;
    if (valor.find('@', arroba + 1) != std::string::npos) return false;

    std::string local = valor.substr(0, arroba);
    std::string dominio = valor.substr(arroba + 1);

    if (!validarLocal(local)) return false;
    if (dominio.empty() || dominio.length() > 255) return false;

    if (dominio.find('.') == std::string::npos) return false;

    size_t inicio = 0;
    size_t fim;
    bool temParte = false;
    do {
        fim = dominio.find('.', inicio);
        std::string parte = (fim == std::string::npos) ? dominio.substr(inicio) : dominio.substr(inicio, fim - inicio);
        if (!validarParteDominio(parte)) return false;
        temParte = true;
        inicio = fim + 1;
    } while (fim != std::string::npos);

    return temParte;
}

#include "projeto.hpp"

Projeto::Projeto() {}

Projeto::Projeto(const Codigo& c, const Nome& n, const Data& i, const Data& t)
    : codigo(c), nome(n), inicio(i), termino(t) {}

Codigo Projeto::getCodigo() const { return codigo; }
Nome Projeto::getNome() const { return nome; }
Data Projeto::getInicio() const { return inicio; }
Data Projeto::getTermino() const { return termino; }

void Projeto::setCodigo(const Codigo& c) { codigo = c; }
void Projeto::setNome(const Nome& n) { nome = n; }
void Projeto::setInicio(const Data& i) { inicio = i; }
void Projeto::setTermino(const Data& t) { termino = t; }

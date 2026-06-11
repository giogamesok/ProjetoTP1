/**
 * @file HistoriaDeUsuario.cpp
 * @brief Implementação da classe HistoriaDeUsuario.
 */

#include "historia_de_usuario.hpp"
HistoriaDeUsuario::HistoriaDeUsuario() {}

HistoriaDeUsuario::HistoriaDeUsuario(const Codigo& c, const Texto& t,
                                     const Texto& p, const Texto& a, const Texto& v,
                                     const Tempo& e, const Prioridade& pr, const Estado& es)
    : codigo(c), titulo(t), papel(p), acao(a), valor(v), estimativa(e), prioridade(pr), estado(es) {}

Codigo HistoriaDeUsuario::getCodigo() const { return codigo; }
Texto HistoriaDeUsuario::getTitulo() const { return titulo; }
Texto HistoriaDeUsuario::getPapel() const { return papel; }
Texto HistoriaDeUsuario::getAcao() const { return acao; }
Texto HistoriaDeUsuario::getValor() const { return valor; }
Tempo HistoriaDeUsuario::getEstimativa() const { return estimativa; }
Prioridade HistoriaDeUsuario::getPrioridade() const { return prioridade; }
Estado HistoriaDeUsuario::getEstado() const { return estado; }

void HistoriaDeUsuario::setCodigo(const Codigo& c) { codigo = c; }
void HistoriaDeUsuario::setTitulo(const Texto& t) { titulo = t; }
void HistoriaDeUsuario::setPapel(const Texto& p) { papel = p; }
void HistoriaDeUsuario::setAcao(const Texto& a) { acao = a; }
void HistoriaDeUsuario::setValor(const Texto& v) { valor = v; }
void HistoriaDeUsuario::setEstimativa(const Tempo& e) { estimativa = e; }
void HistoriaDeUsuario::setPrioridade(const Prioridade& p) { prioridade = p; }
void HistoriaDeUsuario::setEstado(const Estado& e) { estado = e; }

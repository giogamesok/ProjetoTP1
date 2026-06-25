/**
 * @file Pessoa.cpp
 * @brief Implementação da classe Pessoa.
 */

#include "pessoa.hpp"

Pessoa::Pessoa() {}

Pessoa::Pessoa(const Email& e, const Nome& n, const Senha& s, const Papel& p)
    : email(e), nome(n), senha(s), papel(p) {}

Email Pessoa::getEmail() const { return email; }
Nome Pessoa::getNome() const { return nome; }
Senha Pessoa::getSenha() const { return senha; }
Papel Pessoa::getPapel() const { return papel; }

void Pessoa::setEmail(const Email& e) { email = e; }
void Pessoa::setNome(const Nome& n) { nome = n; }
void Pessoa::setSenha(const Senha& s) { senha = s; }
void Pessoa::setPapel(const Papel& p) { papel = p; }

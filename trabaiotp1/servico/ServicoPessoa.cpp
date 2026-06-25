#include "ServicoPessoa.hpp"
#include <stdexcept>

ServicoPessoa::ServicoPessoa(ContainerPessoa* cont) : container(cont) {}

void ServicoPessoa::criar(const Pessoa& pessoa) {
    if (container->existe(pessoa.getEmail().getValor()))
        throw std::invalid_argument("Email já cadastrado.");
    container->inserir(pessoa);
}

Pessoa ServicoPessoa::ler(const std::string& email) const {
    return container->buscar(email);
}

void ServicoPessoa::atualizar(const Pessoa& pessoa) {
    if (!container->existe(pessoa.getEmail().getValor()))
        throw std::invalid_argument("Pessoa não encontrada.");
    container->atualizar(pessoa);
}

void ServicoPessoa::excluir(const std::string& email) {
    if (!container->existe(email))
        throw std::invalid_argument("Pessoa não encontrada.");
    container->remover(email);
}

std::vector<Pessoa> ServicoPessoa::listarTodos() const {
    return container->listar();
}

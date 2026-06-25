#include "ServicoHistoria.hpp"
#include <stdexcept>
#include <algorithm>

ServicoHistoria::ServicoHistoria(ContainerHistoria* ch, ContainerProjeto* cp, ContainerPessoa* cpes)
    : containerHistoria(ch), containerProjeto(cp), containerPessoa(cpes) {}

void ServicoHistoria::criar(const HistoriaDeUsuario& historia, const std::string& codigoProjeto) {
    if (containerHistoria->existe(historia.getCodigo().getValor()))
        throw std::invalid_argument("Código de história já existe.");
    if (!containerProjeto->existe(codigoProjeto))
        throw std::invalid_argument("Projeto não encontrado.");

    HistoriaDeUsuario h = historia;
    h.setEstado(Estado("A FAZER"));

    containerHistoria->inserir(h);
    historiaProjeto[h.getCodigo().getValor()] = codigoProjeto;
}

HistoriaDeUsuario ServicoHistoria::ler(const std::string& codigo) const {
    return containerHistoria->buscar(codigo);
}

void ServicoHistoria::atualizar(const HistoriaDeUsuario& historia) {
    if (!containerHistoria->existe(historia.getCodigo().getValor()))
        throw std::invalid_argument("História não encontrada.");
    containerHistoria->atualizar(historia);
}

void ServicoHistoria::excluir(const std::string& codigo) {
    if (!containerHistoria->existe(codigo))
        throw std::invalid_argument("História não encontrada.");
    historiaProjeto.erase(codigo);
    historiaDesenvolvedor.erase(codigo);
    containerHistoria->remover(codigo);
}

std::vector<HistoriaDeUsuario> ServicoHistoria::listarTodos() const {
    return containerHistoria->listar();
}

std::vector<HistoriaDeUsuario> ServicoHistoria::listarPorProjeto(const std::string& codigoProjeto) const {
    std::vector<HistoriaDeUsuario> resultado;
    for (const auto& par : historiaProjeto) {
        if (par.second == codigoProjeto) {
            resultado.push_back(containerHistoria->buscar(par.first));
        }
    }
    return resultado;
}

void ServicoHistoria::associarDesenvolvedor(const std::string& codigoHistoria, const std::string& emailDev) {
    if (!containerHistoria->existe(codigoHistoria))
        throw std::invalid_argument("História não encontrada.");
    if (!containerPessoa->existe(emailDev))
        throw std::invalid_argument("Desenvolvedor não encontrado.");
    Pessoa dev = containerPessoa->buscar(emailDev);
    if (dev.getPapel().getValor() != "DESENVOLVEDOR")
        throw std::invalid_argument("A pessoa não é desenvolvedor.");
    historiaDesenvolvedor[codigoHistoria] = emailDev;
}

void ServicoHistoria::desassociarDesenvolvedor(const std::string& codigoHistoria) {
    if (!containerHistoria->existe(codigoHistoria))
        throw std::invalid_argument("História não encontrada.");
    historiaDesenvolvedor.erase(codigoHistoria);
}

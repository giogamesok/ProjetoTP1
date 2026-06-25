#ifndef ISERVICO_HISTORIA_HPP
#define ISERVICO_HISTORIA_HPP

#include "historia_de_usuario.hpp"
#include <vector>
#include <string>

class IServicoHistoria {
public:
    virtual ~IServicoHistoria() {}

    virtual void criar(const HistoriaDeUsuario& historia, const std::string& codigoProjeto) = 0;
    virtual HistoriaDeUsuario ler(const std::string& codigo) const = 0;
    virtual void atualizar(const HistoriaDeUsuario& historia) = 0;
    virtual void excluir(const std::string& codigo) = 0;
    virtual std::vector<HistoriaDeUsuario> listarTodos() const = 0;

    virtual std::vector<HistoriaDeUsuario> listarPorProjeto(const std::string& codigoProjeto) const = 0;
    virtual void associarDesenvolvedor(const std::string& codigoHistoria, const std::string& emailDev) = 0;
    virtual void desassociarDesenvolvedor(const std::string& codigoHistoria) = 0;
};

#endif

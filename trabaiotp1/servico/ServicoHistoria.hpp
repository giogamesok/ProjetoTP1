#ifndef SERVICO_HISTORIA_HPP
#define SERVICO_HISTORIA_HPP

#include "IServicoHistoria.hpp"
#include "ContainerHistoria.hpp"
#include "ContainerProjeto.hpp"
#include "ContainerPessoa.hpp"

class ServicoHistoria : public IServicoHistoria {
private:
    ContainerHistoria* containerHistoria;
    ContainerProjeto* containerProjeto;
    ContainerPessoa* containerPessoa;
    std::map<std::string, std::string> historiaProjeto;
    std::map<std::string, std::string> historiaDesenvolvedor;
public:
    ServicoHistoria(ContainerHistoria* ch, ContainerProjeto* cp, ContainerPessoa* cpes);
    void criar(const HistoriaDeUsuario& historia, const std::string& codigoProjeto) override;
    HistoriaDeUsuario ler(const std::string& codigo) const override;
    void atualizar(const HistoriaDeUsuario& historia) override;
    void excluir(const std::string& codigo) override;
    std::vector<HistoriaDeUsuario> listarTodos() const override;
    std::vector<HistoriaDeUsuario> listarPorProjeto(const std::string& codigoProjeto) const override;
    void associarDesenvolvedor(const std::string& codigoHistoria, const std::string& emailDev) override;
    void desassociarDesenvolvedor(const std::string& codigoHistoria) override;
};

#endif

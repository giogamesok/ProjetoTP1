#ifndef ISERVICO_PROJETO_HPP
#define ISERVICO_PROJETO_HPP

#include "projeto.hpp"
#include <vector>
#include <string>

class IServicoProjeto {
public:
    virtual ~IServicoProjeto() {}

    /**
     * @brief Cria um projeto e associa a um Scrum Master.
     * @param projeto Projeto a criar.
     * @param emailScrumMaster Email do Scrum Master (deve existir).
     * @throw std::invalid_argument Se código duplicado ou Scrum Master inválido.
     */
    virtual void criar(const Projeto& projeto, const std::string& emailScrumMaster) = 0;

    virtual Projeto ler(const std::string& codigo) const = 0;
    virtual void atualizar(const Projeto& projeto) = 0;
    virtual void excluir(const std::string& codigo) = 0;
    virtual std::vector<Projeto> listarTodos() const = 0;

    /**
     * @brief Lista projetos associados a uma pessoa (como PO, SM ou Dev).
     * @param email Email da pessoa.
     * @return Vetor de projetos.
     */
    virtual std::vector<Projeto> listarProjetosPorPessoa(const std::string& email) const = 0;
};

#endif

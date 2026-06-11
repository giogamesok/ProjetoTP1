/**
 * @file HistoriaDeUsuario.hpp
 * @brief Definição da classe entidade HistoriaDeUsuario.
 */


#ifndef HISTORIA_DE_USUARIO_HPP_INCLUDED
#define HISTORIA_DE_USUARIO_HPP_INCLUDED

#include "codigo.hpp"
#include "texto.hpp"
#include "tempo.hpp"
#include "prioridade.hpp"
#include "estado.hpp"

/**
 * @class HistoriaDeUsuario
 * @brief Representa uma historia de usuario no sistema Scrum.
 *
 * @details Uma historia de usuario contem um codigo unico, titulo, a descricao
 *          no formato "papel", "acao", "valor", alem de estimativa, prioridade
 *          e estado (A FAZER, FAZENDO, FEITO). E associada a um projeto e pode
 *          ser atribuida a um desenvolvedor.
 *
 * @see Projeto
 * @see Pessoa
 */
class HistoriaDeUsuario {
private:
    Codigo codigo;           ///< Codigo unico da historia (formato: 2 letras + 3 digitos)
    Texto titulo;            ///< Titulo resumido da historia (ate 40 caracteres)
    Texto papel;             ///< Papel do usuario (ex: "como cliente")
    Texto acao;              ///< Acao desejada (ex: "eu quero ver saldo")
    Texto valor;             ///< Valor entregue (ex: "para gerenciar contas")
    Tempo estimativa;        ///< Estimativa de esforço em dias (1 a 365)
    Prioridade prioridade;   ///< Prioridade: ALTA, MEDIA, BAIXA
    Estado estado;           ///< Estado atual: A FAZER, FAZENDO, FEITO

public:
    /**
     * @brief Construtor padrao. Inicializa com valores padrao.
     */
    HistoriaDeUsuario();

    /**
     * @brief Construtor com todos os atributos.
     * @param codigo Codigo da historia.
     * @param titulo Titulo da historia.
     * @param papel Papel do usuario.
     * @param acao Acao desejada.
     * @param valor Beneficio entregue.
     * @param estimativa Estimativa em dias.
     * @param prioridade Prioridade da historia.
     * @param estado Estado inicial (normalmente "A FAZER").
     * @throw std::invalid_argument Se algum valor for invalido.
     */
    HistoriaDeUsuario(const Codigo& codigo, const Texto& titulo,
                      const Texto& papel, const Texto& acao, const Texto& valor,
                      const Tempo& estimativa, const Prioridade& prioridade,
                      const Estado& estado);

    /// @name Getters
    /// @{
    Codigo getCodigo() const;
    Texto getTitulo() const;
    Texto getPapel() const;
    Texto getAcao() const;
    Texto getValor() const;
    Tempo getEstimativa() const;
    Prioridade getPrioridade() const;
    Estado getEstado() const;
    /// @}

    /// @name Setters (lancam excecao se o valor for invalido)
    /// @{
    void setCodigo(const Codigo& codigo);
    void setTitulo(const Texto& titulo);
    void setPapel(const Texto& papel);
    void setAcao(const Texto& acao);
    void setValor(const Texto& valor);
    void setEstimativa(const Tempo& estimativa);
    void setPrioridade(const Prioridade& prioridade);
    void setEstado(const Estado& estado);
    /// @}
};

#endif



#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Dominio que representa o estado de uma historia de usuario.
 *
 * Um objeto desta classe armazena um valor textual restrito ao conjunto de estados
 * validos do fluxo de trabalho de historia de usuario.
 *
 * Valores aceitos:
 *  - A FAZER
 *  - FAZENDO
 *  - FEITO
 *
 * O metodo set lanca excecao caso o valor informado nao pertenca a esse conjunto.
 */
class Estado {
private:
    string valor;

    /**
     * @brief Verifica se o valor informado pertence ao conjunto de estados validos.
     * @param valor Texto a ser validado.
     * @throw invalid_argument Se o valor nao for A FAZER, FAZENDO ou FEITO.
     */
    void validar(string valor);

public:
    /**
     * @brief Atribui um estado ao objeto.
     *
     * O valor e validado antes de ser armazenado.
     *
     * @param valor Estado desejado (A FAZER, FAZENDO ou FEITO).
     * @throw invalid_argument Se o valor estiver em formato invalido.
     */
    void setValor(string valor);

    /**
     * @brief Recupera o estado armazenado no objeto.
     * @return Texto correspondente ao estado atual.
     */
    string getValor() const;
};

inline string Estado::getValor() const {
    return valor;
}

#endif // ESTADO_HPP_INCLUDED

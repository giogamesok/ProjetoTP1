#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Dominio que representa a senha de acesso de uma pessoa.
 *
 * A senha e composta por exatamente 6 caracteres, obedecendo as seguintes regras de formato:
 *  - cada caractere e uma letra (a-z ou A-Z) ou um digito (0-9);
 *  - uma letra nao pode ser seguida por outra letra e o digito nao pode ser seguido por outro digito
 *    (ou seja, ha alternancia estrita entre letras e digitos);
 *  - deve existir ao menos uma letra minuscula (a-z), uma letra maiuscula (A-Z)
 *    e um digito (0-9).
 *
 * O metodo set lanca excecao caso qualquer uma dessas regras seja violada.
 */
class Senha {
private:
    static const int TAMANHO = 6;

    string valor;

    /**
     * @brief Verifica se o valor informado atende a todas as regras de formato da senha.
     * @param valor Texto a ser validado.
     * @throw invalid_argument Se o valor nao respeitar o formato especificado.
     */
    void validar(string valor);

public:
    /**
     * @brief Atribui uma senha ao objeto.
     *
     * O valor e validado antes de ser armazenado.
     *
     * @param valor Senha desejada (6 caracteres alternando letras e digitos,
     *        com ao menos uma minuscula, uma maiuscula e um digito).
     * @throw invalid_argument Se o valor estiver em formato invalido.
     */
    void setValor(string valor);

    /**
     * @brief Recupera a senha armazenada no objeto.
     * @return Texto correspondente a senha atual.
     */
    string getValor() const;
};

inline string Senha::getValor() const {
    return valor;
}

#endif // SENHA_HPP_INCLUDED

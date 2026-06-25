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
    std::string valor;
public:
    Estado();
    Estado(const std::string& valor);
    std::string getValor() const;
    void setValor(const std::string& novoValor);
    static bool validar(const std::string& valor);
};

#endif

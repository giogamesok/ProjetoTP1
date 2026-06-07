#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

#include <string>
#include <stdexcept>

class Texto {
private:
    std::string valor;
    void validar(std::string);
public:
    void setValor(std::string);
    std::string getValor() const;
};

#endif // TEXTO_HPP_INCLUDED

#endif // TEMPO_HPP_INCLUDED

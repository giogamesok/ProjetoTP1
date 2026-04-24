#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED



#endif // CODIGO_HPP_INCLUDED
using namespace std

class codigo{
private:
        std::string valor;
        static bool validar(const std::string& v);

public:
    Codigo(const std::string& v);
    std::string getValor() const;
    void setValor(const std::string& v);



};
#endif

#ifndef FLUXO_H
#define FLUXO_H

#include "../Sistema/Sistema.h"

class Fluxo
{
private:
    string nome;
    Sistema *entrada;
    Sistema *saida;
    double valorTransporte;

public:
    virtual double execute() = 0;
    Fluxo();
    Fluxo(string nome, Sistema *entrada, Sistema *saida);

    void setNome(const string &nome);
    string getNome() const;
    void setSistemaEntrada(Sistema *entrada);
    void setSistemaSaida(Sistema *saida);

    Sistema *getSistemaEntrada() const;
    Sistema *getSistemaSaida() const;

    void setValorTransporte(double valor);
    double getValorTransporte() const;
};

#endif // FLUXO_H
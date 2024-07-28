#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
using namespace std;

class Sistema
{
private:
    string nome;
    double valorAcumulador;

public:
    Sistema();
    Sistema(string nome);
    Sistema(string nome, double valor);

    void setNome(const string &nome);
    string getNome() const;

    void setValorAcumulador(double valor);
    double getValorAcumulador() const;
};

#endif // SISTEMA_H

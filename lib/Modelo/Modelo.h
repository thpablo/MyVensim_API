#ifndef MODELO_H
#define MODELO_H

#include "../Fluxo/Fluxo.h"
#include "../Sistema/Sistema.h"
#include <vector>
#include <string>

using namespace std;

class Modelo
{
private:
    vector<Fluxo *> fluxos;
    vector<Sistema *> sistemas;

    string nome;
    int tempoInicial;
    int tempoFinal;

public:
    Modelo();
    Modelo(string nome);
    Modelo(string nome, int tempoInicial);
    Modelo(string nome, int tempoInicial, int tempoFinal);

    void setNome(const string &nome);
    void adicionarSistema(Sistema *sistema);
    void adicionarFluxo(Fluxo *fluxo);
    void setTempoInicial(int tempoInicial);
    void setTempoFinal(int tempoFinal);

    void run(bool printar = false);
    void printarSistemas(int tempo);
};

#endif // MODELO_H

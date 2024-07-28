#include "Modelo.h"
#include <iostream>

using namespace std;

Modelo::Modelo() : nome(""), tempoInicial(0), tempoFinal(0) {}

Modelo::Modelo(string nome) : nome(nome), tempoInicial(0), tempoFinal(0) {}

Modelo::Modelo(string nome, int tempoInicial) : nome(nome), tempoInicial(tempoInicial), tempoFinal(0) {}

Modelo::Modelo(string nome, int tempoInicial, int tempoFinal) : nome(nome), tempoInicial(tempoInicial), tempoFinal(tempoFinal) {}

void Modelo::setNome(const string &nome) {
    this->nome = nome;
}

void Modelo::adicionarSistema(Sistema *sistema) {
    sistemas.push_back(sistema);
}

void Modelo::adicionarFluxo(Fluxo *fluxo) {
    fluxos.push_back(fluxo);
}

void Modelo::run(bool printar) {
    for (int i = tempoInicial; i <= tempoFinal; i++) {
        printar ? printarSistemas(i) : void();
        for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
            (*it)->setValorTransporte((*it)->execute());

        for (auto it = fluxos.begin(); it != fluxos.end(); ++it) {
            Sistema *entrada = (*it)->getSistemaEntrada();
            Sistema *saida = (*it)->getSistemaSaida();

            entrada->setValorAcumulador(entrada->getValorAcumulador() - (*it)->getValorTransporte());
            saida->setValorAcumulador(saida->getValorAcumulador() + (*it)->getValorTransporte());
        }
    }
}

void Modelo::printarSistemas(int tempo) {
    string fluxosVet[6] = {"F", "G", "R", "T", "U", "V"};
    int cont = 0;
    cout << "Tempo: " << tempo << endl;
    for (auto it = fluxos.begin(); it != fluxos.end(); ++it) {
        cout << fluxosVet[cont] << ": " << (*it)->getValorTransporte() << "    ";
        cont++;
    }
    cout << endl;
    for (auto it = sistemas.begin(); it != sistemas.end(); ++it)
        cout << "\t\t" << (*it)->getNome() << ":\t" << (*it)->getValorAcumulador() << endl;
    cout << "---------------------------------" << endl;
}

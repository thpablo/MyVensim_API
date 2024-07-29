#include "Modelo.h"
#include <iostream>

using namespace std;

Modelo::Modelo() : nome(""), tempoInicial(0), tempoFinal(0) {}

Modelo::Modelo(string nome) : nome(nome), tempoInicial(0), tempoFinal(0) {}

Modelo::Modelo(string nome, int tempoInicial, int tempoFinal) : nome(nome), tempoInicial(tempoInicial), tempoFinal(tempoFinal) {}

void Modelo::setNome(const string &nome) {
    this->nome = nome;
}

void Modelo::setTempoInicial(int tempoInicial) {
    if(tempoInicial < 0 || tempoInicial >= tempoFinal)
        throw invalid_argument("Tempo inicial deve ser maior ou igual a zero e menor que o tempo final");
    this->tempoInicial = tempoInicial;
}
void Modelo::setTempoFinal(int tempoFinal) {
    if(tempoFinal < tempoInicial)
        throw invalid_argument("Tempo final deve ser maior que o tempo inicial");
    this->tempoFinal = tempoFinal;
}

void Modelo::adicionarSistema(Sistema *sistema) {
    sistemas.push_back(sistema);
}

void Modelo::adicionarFluxo(Fluxo *fluxo) {
    fluxos.push_back(fluxo);
}

void Modelo::imprimirSistemas() {
    for (auto it = sistemas.begin(); it != sistemas.end(); ++it)
        cout << (*it)->getNome() << ": " << (*it)->getValorAcumulador() << endl;
}

void Modelo::run(bool printar) {
    
    for (int i = tempoInicial; i <= tempoFinal; i++) {
        for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
            (*it)->setValorTransporte((*it)->execute());

        for (auto it = fluxos.begin(); it != fluxos.end(); ++it) {
            Sistema *entrada = (*it)->getSistemaEntrada();
            Sistema *saida = (*it)->getSistemaSaida();

            if(entrada != nullptr)
                entrada->setValorAcumulador(entrada->getValorAcumulador() - (*it)->getValorTransporte());
            if(saida != nullptr)
                saida->setValorAcumulador(saida->getValorAcumulador() + (*it)->getValorTransporte());
        }
    }
    // Printar valores finais
    printar ? imprimirSistemas() : void();
}

/*
void Modelo::printarFluxosEnquantoExecuta(int tempo) {
    cout << "Tempo: " << tempo << endl;
    for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
        cout << (*it)->getNome() << ": " << (*it)->getValorTransporte() << "    ";

    cout << endl;
}

void Modelo::printarSistemasEnquantoExecuta(int tempo){
for (auto it = sistemas.begin(); it != sistemas.end(); ++it)
        cout << "\t\t" << (*it)->getNome() << ":\t" << (*it)->getValorAcumulador() << endl;
    cout << "---------------------------------" << endl;
}
*/
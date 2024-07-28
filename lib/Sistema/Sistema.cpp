#include "Sistema.h"

Sistema::Sistema() : nome(""), valorAcumulador(0.0) {}

Sistema::Sistema(string nome) : nome(nome), valorAcumulador(0.0) {}

Sistema::Sistema(string nome, double valor) : nome(nome), valorAcumulador(valor) {}

void Sistema::setNome(const string &nome) {
    this->nome = nome;
}

string Sistema::getNome() const {
    return nome;
}

void Sistema::setValorAcumulador(double valor) {
    valorAcumulador = valor;
}

double Sistema::getValorAcumulador() const {
    return valorAcumulador;
}

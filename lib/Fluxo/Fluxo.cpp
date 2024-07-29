#include "Fluxo.h"

Fluxo::Fluxo() : nome(""), entrada(nullptr), saida(nullptr), valorTransporte(0.0) {}

Fluxo::Fluxo(string nome, Sistema *entrada, Sistema *saida) : nome(nome), entrada(entrada), saida(saida), valorTransporte(0.0) {}

void Fluxo::setNome(const string &nome) {
    this->nome = nome;
}
string Fluxo::getNome() const {
    return nome;
}

void Fluxo::setSistemaEntrada(Sistema *entrada) {
    this->entrada = entrada;
}

void Fluxo::setSistemaSaida(Sistema *saida) {
    this->saida = saida;
}

Sistema *Fluxo::getSistemaEntrada() const {
    return entrada;
}

Sistema *Fluxo::getSistemaSaida() const {
    return saida;
}

void Fluxo::setValorTransporte(double valor) {
    valorTransporte = valor;
}

double Fluxo::getValorTransporte() const {
    return valorTransporte;
}

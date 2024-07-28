#include "Fluxo.h"

Fluxo::Fluxo() : entrada(nullptr), saida(nullptr), valorTransporte(0.0) {}

Fluxo::Fluxo(Sistema *entrada, Sistema *saida) : entrada(entrada), saida(saida), valorTransporte(0.0) {}

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

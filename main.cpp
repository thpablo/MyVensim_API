#include <iostream>
#include <string>
#include <vector>
#include "lib/Modelo/Modelo.h"
using namespace std;
// Implementação de polimorfismos dos fluxos
class Exponencial : public Fluxo
{
public:
    Exponencial(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class Logistica : public Fluxo
{
public:
    Logistica(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaSaida()->getValorAcumulador() * (1 - (getSistemaSaida()->getValorAcumulador()) / 70);
    }
};

class V : public Fluxo
{
public:
    V(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class U : public Fluxo
{
public:
    U(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class G : public Fluxo
{
public:
    G(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class F : public Fluxo
{
public:
    F(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class R : public Fluxo
{
public:
    R(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class T : public Fluxo
{
public:
    T(string nome, Sistema *entrada, Sistema *saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class Isolado : public Fluxo
{
public:
    Isolado(string nome, Sistema * entrada, Sistema * saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 1;
    }
};

class FluxoSaida : public Fluxo
{
public:
    FluxoSaida(string nome, Sistema * entrada, Sistema * saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 1;
    }
};

class FluxoEntrada  : public Fluxo
{
public:
    FluxoEntrada(string nome, Sistema * entrada, Sistema * saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 1;
    }
};
class FluxoEntradaESaida : public Fluxo
{
public:
    FluxoEntradaESaida(string nome, Sistema * entrada, Sistema * saida) : Fluxo(nome, entrada, saida) {}
    double execute() override
    {
        return 1 + getSistemaEntrada()->getValorAcumulador();
    }
};

#define MODELO_X
#define CASO4

int main()
{
    int tempoInicial = 0;
    int tempoFinal = 100;

#ifdef MODELO_1
    // Criação do modelo
    Modelo m1 = Modelo("Modelo 1", tempoInicial, tempoFinal);

    // Adiciona Sistemas
    Sistema s1 = Sistema("POP 1", 100);
    Sistema s2 = Sistema("POP 2", 0);

    // Adiciona Sistemas e fluxos
    Exponencial fluxo1 = Exponencial("exponencial", &s1, &s2);

    // Adiciona Sistemas e fluxos ao modelo
    m1.adicionarSistema(&s1);
    m1.adicionarSistema(&s2);
    m1.adicionarFluxo(&fluxo1);
    // Execução
    m1.run(true);

#endif

#ifdef MODELO_2

    Modelo m2 = Modelo("Modelo 2", tempoInicial, tempoFinal);

    Sistema s3 = Sistema("p1", 100);
    Sistema s4 = Sistema("p2", 10);

    Logistica fluxo2 = Logistica("logistica", &s3, &s4);

    m2.adicionarSistema(&s3);
    m2.adicionarSistema(&s4);
    m2.adicionarFluxo(&fluxo2);

    m2.run(true);
#endif

#ifdef MODELO_3
    Sistema Q1 = Sistema("Q1", 100);
    Sistema Q2 = Sistema("Q2", 0);
    Sistema Q3 = Sistema("Q3", 100);
    Sistema Q4 = Sistema("Q4", 0);
    Sistema Q5 = Sistema("Q5", 0);

    F f = F("F", &Q1, &Q2);
    G g = G("G", &Q1, &Q3);
    R r = R("R", &Q2, &Q5);
    T t = T("T", &Q2, &Q3);
    U u = U("U", &Q3, &Q4);
    V v = V("V", &Q4, &Q1);

    Modelo m3 = Modelo("Modelo 3", tempoInicial, tempoFinal);
    m3.adicionarSistema(&Q1);
    m3.adicionarSistema(&Q2);
    m3.adicionarSistema(&Q3);
    m3.adicionarSistema(&Q4);
    m3.adicionarSistema(&Q5);

    m3.adicionarFluxo(&f);
    m3.adicionarFluxo(&g);
    m3.adicionarFluxo(&r);
    m3.adicionarFluxo(&t);
    m3.adicionarFluxo(&u);
    m3.adicionarFluxo(&v);
    m3.run(true);

#endif

#ifdef CASO1
    Modelo caso1 = Modelo("Caso 1", tempoInicial, 10);  
    Sistema sistemaIsolado = Sistema("Sistema Isolado", 100);

    caso1.adicionarSistema(&sistemaIsolado);
    caso1.run(true);

#endif

#ifdef CASO2
    Modelo caso2 = Modelo("Caso 2", tempoInicial, 10);
    Isolado fluxoIsolado = Isolado("Fluxo Isolado", nullptr, nullptr);
    caso2.adicionarFluxo(&fluxoIsolado);
    caso2.run(true);

#endif

#ifdef CASO3
    Modelo caso3 = Modelo("Caso 3", tempoInicial, 10);
    Sistema sistemaSaida = Sistema("Sistema Saida", 0);
    FluxoSaida fluxoSaida = FluxoSaida("Fluxo Saida", nullptr, &sistemaSaida);
    caso3.adicionarSistema(&sistemaSaida);
    caso3.adicionarFluxo(&fluxoSaida);
    caso3.run(true);
#endif

#ifdef CASO4
    Modelo caso4 = Modelo("Caso 4", tempoInicial, 10); 
    Sistema sistemaEntrada = Sistema("Sistema Entrada", 100);
    FluxoEntrada fluxoEntrada = FluxoEntrada("Fluxo Entrada", &sistemaEntrada, nullptr);
    caso4.adicionarSistema(&sistemaEntrada);
    caso4.adicionarFluxo(&fluxoEntrada);
    caso4.run(true);
#endif

#ifdef CASO5
    Modelo caso5 = Modelo("Caso 5", tempoInicial, 10);
    Sistema sistemaEntrada = Sistema("Sistema Entrada", 10);
    Sistema sistemaSaida = Sistema("Sistema Saida", 0);
    fluxoEntradaESaida fluxoEntradaESaida = fluxoEntradaESaida("Fluxo Entrada e Saida", &sistemaEntrada, &sistemaSaida);
    caso5.adicionarSistema(&sistemaEntrada);
    caso5.adicionarSistema(&sistemaSaida);
    caso5.adicionarFluxo(&fluxoEntradaESaida);
    caso5.run(true);
#endif

    return 0;
}
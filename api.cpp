#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sistema
{
private:
    string nome;
    double valorAcumulador;

public:
    // Sem nome
    Sistema() : nome(""), valorAcumulador(0.0) {}

    // Somente nome
    Sistema(string nome) : nome(nome), valorAcumulador(0.0) {}

    // Nome e valor
    Sistema(string nome, double valor) : nome(nome), valorAcumulador(valor) {}

    void setNome(const string &nome)
    {
        this->nome = nome;
    }

    string getNome() const
    {
        return nome;
    }

    void setValorAcumulador(long double valor)
    {
        valorAcumulador = valor;
    }

    long double getValorAcumulador() const
    {
        return valorAcumulador;
    }
};

/* Classe Fluxo necessita ser herdada e implementada a funcao equacao, dependendo do usuario para criar a equacao desejada e o modelo */
class Fluxo
{
private:
    Sistema *entrada;
    Sistema *saida;
    double valorTransporte;

public:
    virtual double execute() = 0;
    Fluxo() : entrada(nullptr), saida(nullptr), valorTransporte(0.0) {}
    Fluxo(Sistema *entrada, Sistema *saida) : entrada(entrada), saida(saida), valorTransporte(0.0) {}

    void setSistemaEntrada(Sistema *entrada)
    {
        this->entrada = entrada;
    }

    void setSistemaSaida(Sistema *saida)
    {
        this->saida = saida;
    }

    Sistema *getSistemaEntrada() const
    {
        return entrada;
    }

    Sistema *getSistemaSaida() const
    {
        return saida;
    }

    void setValorTransporte(double valor)
    {
        valorTransporte = valor;
    }

    double getValorTransporte() const
    {
        return valorTransporte;
    }
};


class Modelo
{
    vector<Fluxo *> fluxos;
    vector<Sistema *> sistemas;

    string nome;
    int tempoInicial;
    int tempoFinal;

public:
    // Construtores
    Modelo() : nome(""), tempoInicial(0), tempoFinal(0) {}
    Modelo(string nome) : nome(nome), tempoInicial(0), tempoFinal(0) {}
    Modelo(string nome, int tempoInicial) : nome(nome), tempoInicial(tempoInicial), tempoFinal(0) {}
    Modelo(string nome, int tempoInicial, int tempoFinal) : nome(nome), tempoInicial(tempoInicial), tempoFinal(tempoFinal) {}

    void setNome(const string &nome)
    {
        this->nome = nome;
    }
    void adicionarSistema(Sistema *sistema)
    {
        sistemas.push_back(sistema);
    }
    void adicionarFluxo(Fluxo *fluxo)
    {
        fluxos.push_back(fluxo);
    }

    void run(bool printar = false)
    {
        for (int i = tempoInicial; i <= tempoFinal; i++)
        {
            printar ? printarSistemas(i) : void();
            // Acumula valores para atualizar os sistemas
            for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
                (*it)->setValorTransporte((*it)->execute());

            // Atualiza os sistemas
            for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
            {
                Sistema *entrada = (*it)->getSistemaEntrada();
                Sistema *saida = (*it)->getSistemaSaida();

                entrada->setValorAcumulador(entrada->getValorAcumulador() - (*it)->getValorTransporte());
                saida->setValorAcumulador(saida->getValorAcumulador() + (*it)->getValorTransporte());
            }
        }
    }

    void printarSistemas(int tempo)
    {
        cout << "Tempo: " << tempo << endl;
        for (auto it = sistemas.begin(); it != sistemas.end(); ++it)
            cout << "\t" << (*it)->getNome() << ":\t" << (*it)->getValorAcumulador() << endl;
        cout << "---------------------------------" << endl;
    }
};

// Implementação de polimorfismos dos fluxos
class Exponencial : public Fluxo
{
public:
    Exponencial(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class Logistica : public Fluxo
{
public:
    Logistica(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaSaida()->getValorAcumulador() * ((1 - getSistemaSaida()->getValorAcumulador()) / 70);
    }
};

int main()
{
    int tempoInicial = 0;
    int tempoFinal = 100;

    // Criação do modelo
    Modelo m = Modelo("Modelo 1", tempoInicial, tempoFinal);

    // Adiciona Sistemas
    Sistema s1 = Sistema("POP 1", 100);
    Sistema s2 = Sistema("POP 2", 0);

    // Adiciona Sistemas e fluxos
    Exponencial fluxo1 = Exponencial(&s1, &s2);

    // Adiciona Sistemas e fluxos ao modelo
    m.adicionarSistema(&s1);
    m.adicionarSistema (&s2);
    m.adicionarFluxo(&fluxo1);

    // Execução
    m.run(true);
}
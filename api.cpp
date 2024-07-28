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
        string fluxosVet[6] = {"F", "G", "R", "T", "U", "V"};
        int cont = 0;
        cout << "Tempo: " << tempo << endl;
        // Printa tempo e fluxos
        for (auto it = fluxos.begin(); it != fluxos.end(); ++it)
        {
            cout << fluxosVet[cont] << ": " << (*it)->getValorTransporte() << "    ";
            cont++;
        }
        cout << endl;
        // Printa os sistemas
        for (auto it = sistemas.begin(); it != sistemas.end(); ++it)
            cout << "\t\t" << (*it)->getNome() << ":\t" << (*it)->getValorAcumulador() << endl;
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
        return 0.01 * getSistemaSaida()->getValorAcumulador() * (1 - (getSistemaSaida()->getValorAcumulador()) / 70);
    }
};

class V : public Fluxo
{
public:
    V(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class U : public Fluxo
{
public:
    U(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class G : public Fluxo
{
public:
    G(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class F : public Fluxo
{
public:
    F(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class R : public Fluxo
{
public:
    R(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

class T : public Fluxo
{
public:
    T(Sistema *entrada, Sistema *saida) : Fluxo(entrada, saida) {}
    double execute() override
    {
        return 0.01 * getSistemaEntrada()->getValorAcumulador();
    }
};

#define MODELO_3

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
    Exponencial fluxo1 = Exponencial(&s1, &s2);

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

    Logistica fluxo2 = Logistica(&s3, &s4);

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

    F f = F(&Q1, &Q2);
    G g = G(&Q1, &Q3);
    R r = R(&Q2, &Q5);
    T t = T(&Q2, &Q3);
    U u = U(&Q3, &Q4);
    V v = V(&Q4, &Q1);

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
    return 0;
}
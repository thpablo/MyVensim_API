#define QUANT_SISTEMAS 5
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Modelo{
    vector<Fluxo> fluxos;
    vector<Sistema> sistemas;

    string nome;
    int tempoInicial;
    int tempoFinal; 

public:
    // Construtores
    Modelo(){
        nome = "";
        tempoInicial = 0;
        tempoFinal = 0;
    }
    Modelo(string nome){
        this->nome = nome;
        tempoInicial = 0;
        tempoFinal = 0;
    }
    Modelo(string nome, int tempoInicial){
        this->nome = nome;
        this->tempoInicial = tempoInicial;
        tempoFinal = 0;
    }
    Modelo(string nome, int tempoInicial, int tempoFinal){
        this->nome = nome;
        this->tempoInicial = tempoInicial;
        this->tempoFinal = tempoFinal;
    }

    void setNome(const string& nome) {
        this->nome = nome;
    }

    void adicionarSistema(Sistema& sistema) {
        sistemas.push_back(sistema);
    }
    void adicionarFluxo(Fluxo& fluxo) {
        fluxos.push_back(fluxo);
    }
    void run(){
        int n = fluxos.size();
        int valoresAcumuladosFluxos[n];
    
        for(int i = tempoInicial; i < tempoFinal; i++){
            
            // Acumula valores para atualizar os sistemas
            for(vector<Fluxo>::iterator it = fluxos.begin(); it != fluxos.end(); ++it)
                valoresAcumuladosFluxos[i] = fluxos[i].execute();
            
            // Atualiza os sistemas
            for(vector<Fluxo>::iterator it = fluxos.begin(); it != fluxos.end(); ++it){
                Sistema* entrada = fluxos[i].getSistemaEntrada();
                Sistema* saida = fluxos[i].getSistemaSaida();
                
                entrada->setValorAcumulador(entrada->getValorAcumulador() - valoresAcumuladosFluxos[i]);
                saida->setValorAcumulador(saida->getValorAcumulador() + valoresAcumuladosFluxos[i]);
            }
             // Printa os valores dos sistemas
            for(vector<Sistema>::iterator it = sistemas.begin(); it != sistemas.end(); ++it)
                cout << "Tempo: " << i << "Sistema: " << sistemas[i].getNome() << " Valor: " << sistemas[i].getValorAcumulador() << endl;
        }
    }

    void printarSistemas(){
        for(vector<Sistema>::iterator it = sistemas.begin(); it != sistemas.end(); ++it)
            cout << it->getNome() << " " << it->getValorAcumulador() << endl;
    }

};

class Sistema
{
private:
    string nome;
    double valorAcumulador;

public:
    // Sem nome
    Sistema(){
        nome = "";
        valorAcumulador = 0.0;
    }
    // Somente nome
    Sistema(string nome){
        this->nome = nome;
        valorAcumulador = 0.0;
    }
    // Nome e valor 
    Sistema(string nome, double valorAcumulador){
        this->nome = nome;
        this->valorAcumulador = valorAcumulador;
    }

    void setNome(const string& nome) {
        this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    void setValorAcumulador(long double valor) {
        valorAcumulador = valor;
    }

    long double getValorAcumulador() const {
        return valorAcumulador;
    }
};

/* Classe Fluxo necessita ser herdada e implementada a funcao equacao, dependendo do usuario para criar a equacao desejada e o modelo */
class Fluxo
{
private:
    Sistema* entrada;
    Sistema* saida;
    double valorTransporte;

public:
    virtual double execute() = 0;

    // setados entrada e saida nulos
    Fluxo(){
        entrada = nullptr;
        saida = nullptr; 
        valorTransporte = 0.0;
    }

    void conectarSistemas(Sistema& entrada, Sistema& saida) {
        this->entrada = &entrada;
        this->saida = &saida;
    }

    void setSistemaEntrada(Sistema& entrada) {
        this->entrada = &entrada;
    }

    void setSistemaSaida(Sistema& saida) {
        this->saida = &saida;
    }

    Sistema* getSistemaEntrada() const {
        return entrada;
    }

    Sistema* getSistemaSaida() const {
        return saida;
    }

    void setValorTransporte(double valor) {
        valorTransporte = valor;
    }

    double getValorTransporte() const {
        return valorTransporte;
    }
};

class Exponencial : public Fluxo {
public:
    double execute() override {
        return 0.3 * getSistemaEntrada()->getValorAcumulador();
    }
};

class Logistica : public Fluxo {
public:
    double execute() override{
        return 0.01 * getSistemaSaida()->getValorAcumulador() * ((1 - getSistemaSaida()->getValorAcumulador())/70);
    }
};

int main(){
    int tempoInicial = 0;
    int tempoFinal = 0;

    // Criação do modelo
    Modelo m = Modelo("Modelo 1", tempoInicial, tempoFinal);

    // Adiciona Sistemas
    Sistema s1 = Sistema("Sistema 1", 100);
    Sistema s2 = Sistema("Sistema 2", 0);
    // Adiciona Sistemas e fluxos

    // Execução
    m.run();
}
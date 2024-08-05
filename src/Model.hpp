#ifndef MODELO_H
#define MODELO_H

#include "./Flow.hpp"
#include "./System.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Model
{
private:
    vector<Flow *> flows;
    vector<System *> systems;
    string name;

public:
    Model();
    Model(string name);
    Model(const Model &m);
    Model &operator=(const Model &m);

    void setName(const string &name);
    void add(System *system);
    void add(Flow *flow);

    void run(int initialTime, int finalTime);
    
    virtual ~Model();

    // Auxiliar functions
    void printRun(int time);
    void printSystems();
};

#endif // MODELO_H

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
    Model(const Model &m);
    Model &operator=(const Model &m);

public:
    Model();
    Model(string name);

    void setName(const string &name);
    void add(System *system);
    void add(Flow *flow);

    void getSystems();

    void run(int initialTime, int finalTime);
    
    virtual ~Model(){
        systems.clear();
        flows.clear();
    }



    void printRun(int time);
    void printSystems();



};

#endif // MODELO_H

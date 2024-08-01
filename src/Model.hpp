#ifndef MODELO_H
#define MODELO_H

#include "./Flow.hpp"
#include "./System.hpp"
#include <vector>
#include <string>

using namespace std;

class Model
{
private:
    vector<Flow *> flows;
    vector<System *> systems;

    string name;
    //void printFlowsWhileExecuting(int time);
    //void printSystemsWhileExecuting(int time);

public:
    Model();
    Model(string name);

    //Model(const Model &m);
    //Model &operator=(const Model &m);

    void setName(const string &name);
    void add(System *system);
    void add(Flow *flow);

    void run(int initialTime, int finalTime);
    //~Model();



    void printRun(int time);
    void printSystems();



};

#endif // MODELO_H

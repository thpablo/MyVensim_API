#ifndef MODELO_H
#define MODELO_H

#include "../Flow/Flow.h"
#include "../System/System.h"
#include <vector>
#include <string>

using namespace std;

class Model
{
private:
    vector<Flow *> flows;
    vector<System *> systems;

    string name;
    void printSystems();
    //void printFlowsWhileExecuting(int time);
    //void printSystemsWhileExecuting(int time);

public:
    Model();
    Model(string name);

    void setName(const string &name);
    void add(System *system);
    void add(Flow *flow);

    void run(int initialTime, int finalTime);
    ~Model();
};

#endif // MODELO_H

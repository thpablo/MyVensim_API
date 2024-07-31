#include "Model.h"
#include <iostream>

using namespace std;

Model::Model() : name(""){}

Model::Model(string name) : name(name) {}

void Model::setName(const string &name) {
    this->name = name;
}

void Model::add(System *system) {
    systems.push_back(system);
}

void Model::add(Flow *flow) {
    flows.push_back(flow);
}

void Model::printSystems() {
    for (auto it = systems.begin(); it != systems.end(); ++it)
        cout << (*it)->getName() << ": " << (*it)->getAccumulatorValue() << endl;
}


void Model::run(int initialTime, int finalTime) {
    
    for (int i = initialTime; i <= finalTime; i++) {
        for (auto it = flows.begin(); it != flows.end(); ++it)
            (*it)->setTransportValue((*it)->execute());

        for (auto it = flows.begin(); it != flows.end(); ++it) {
            System *input = (*it)->getTarget();
            System *output = (*it)->getSource();

            if(input != nullptr)
                input->setAccumulatorValue(input->getAccumulatorValue() - (*it)->getTransportValue());
            if(output != nullptr)
                output->setAccumulatorValue(output->getAccumulatorValue() + (*it)->getTransportValue());
        }
    }
    // Print final values
    //print ? printSystems() : void();
}


Model::~Model() {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        delete *it;
    }
}

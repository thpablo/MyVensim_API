#include "./Model.hpp"
#include <iostream>

using namespace std;

Model::Model() : name(""){}

Model::Model(string name) : name(name) {}

// Copy constructor
Model::Model(const Model &m) : name(m.name) {
    
    // Delete and clear the systems
    for(System* s : systems){
        delete s;
    }
    systems.clear();

    // Make a deep copy of the systems
    for (auto it = m.systems.begin(); it != m.systems.end(); ++it){
        System *s = new System(**it);
        systems.push_back(s);
    }

    // Delete and clear the flows    
    for(Flow* f : flows){
        delete f;
    }
    flows.clear();

    // Make a deep copy of the flows
    for (auto it = m.flows.begin(); it != m.flows.end(); ++it){
        flows.push_back((*it)->create());
    }
}

// Overload of the assignment operator
Model &Model::operator=(const Model &m) {
    //Verify if the object is the same
    if(&m == this)
        return *this;

    name = m.name;

    // Delete and clear the systems
    for(System* s : systems){
        delete s;
    }
    systems.clear();

    // Make a deep copy of the systems
    for (auto it = m.systems.begin(); it != m.systems.end(); ++it){
        System *s = new System(**it);
        systems.push_back(s);
    }

    // Delete and clear the flows    
    for(Flow* f : flows){
        delete f;
    }
    flows.clear();

    // Make a deep copy of the flows
    for (auto it = m.flows.begin(); it != m.flows.end(); ++it){
        flows.push_back((*it)->create());
    }

    return *this;
}

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

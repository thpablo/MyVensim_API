#include "./ModelBody.hpp"
#include "./Model.hpp"

// ModelImpl is a Factory class, because of this it includes Flow and System Implementation classes
#include "./FlowBody.hpp"
#include "./SystemBody.hpp"

#include <math.h>

ModelBody* ModelBody::model = nullptr;

ModelBody::ModelBody() : name(""), currentTime(0) {}

ModelBody::ModelBody(string name, int currentTime) : name(name), currentTime(currentTime) {}

// Copy constructor
ModelBody::ModelBody(const ModelBody &m) : name(m.name)
{
    // Clear the systems vector
    systems.clear();

    for (auto it = m.systems.begin(); it != m.systems.end(); ++it)
        add(&(**it));
    // Clear the flows vector
    flows.clear();

    for (auto it = m.flows.begin(); it != m.flows.end(); ++it)
        add(&(**it));
}

// Overload of the assignment operator
ModelBody &ModelBody::operator=(const ModelBody &m)
{
    // Verify if the object is the same
    if (&m == this)
        return *this;

    name = m.name;
    // Clear the systems vector
    systems.clear();

    for (auto it = m.systems.begin(); it != m.systems.end(); ++it)
        add(&(**it));

    // Clear the flows vector
    flows.clear();

    for (auto it = m.flows.begin(); it != m.flows.end(); ++it)
        add(&(**it));

    return *this;
}

string ModelBody::getName() const
{
    return name;
}

void ModelBody::setName(const string &name)
{
    this->name = name;
}
int ModelBody::getCurrentTime() const
{
    return currentTime;
}
void ModelBody::add(System *system)
{
    systems.push_back(system);
}

void ModelBody::add(Flow *flow)
{
    flows.push_back(flow);
}

Model::itSystem ModelBody::getSystem()
{
    return systems.begin();
}
Model::itFlow ModelBody::getFlow()
{
    return flows.begin();
}
Model::itSystem ModelBody::getSystem(string name)
{
    for (auto it = systems.begin(); it != systems.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            return it;
        }
    }
    return systems.end();
}

Model::itFlow ModelBody::getFlow(string name)
{
    for (auto it = flows.begin(); it != flows.end(); ++it)
    {
        if ((*it)->getName() == name)
        {
            return it;
        }
    }
    return flows.end();
}

int ModelBody::getSystemsSize(){
    return systems.size();
}
int ModelBody::getFlowsSize(){
    return flows.size();
}

void ModelBody::run(int initialTime, int finalTime)
{
    for (int i = initialTime; i < finalTime; i++)
    {
        currentTime = i;
        // Execute the flows and salve the values
        for (auto it = flows.begin(); it != flows.end(); ++it)
            (*it)->setTransportValue((*it)->execute());

        // Update the systems
        for (auto it = flows.begin(); it != flows.end(); ++it)
        {
            System *tempSource = (*it)->getSource();
            System *tempTarget = (*it)->getTarget();

            // Verify null pointers to source and target
            if (tempSource != nullptr)
                tempSource->setAccumulatorValue(tempSource->getAccumulatorValue() - (*it)->getTransportValue());
            if (tempTarget != nullptr)
                tempTarget->setAccumulatorValue(tempTarget->getAccumulatorValue() + (*it)->getTransportValue());
        }
    }
}


ModelBody * ModelBody::createModel(string name = "", int currentTime = 0)
{
    if(model == NULL)
        model = new ModelBody(name, currentTime);
    return model;
}

Model * Model::createModel(string name, int currentTime){
    return ModelBody::createModel(name, currentTime);
}

System * ModelBody::createSystem(string name, double value){
    System *system = new SystemHandle(name, value);
    add(system);
    return system;
}

bool ModelBody::deleteSystem(const string &name){
    for(auto it = systems.begin(); it != systems.end(); ++it){
        if((*it)->getName() == name){
            delete *it;
            return true;
        }
    }
    return false;
}
bool ModelBody::deleteFlow(const string &name){
    for(auto it = flows.begin(); it != flows.end(); ++it){
        if((*it)->getName() == name){
            delete *it;
            return true;
        }
    }
    return false;
}

ModelBody::~ModelBody() { 
    for(itSystem it = systems.begin(); it != systems.end(); ++it){
        delete *it;
    }
    systems.clear();

    for(itFlow it = flows.begin(); it != flows.end(); ++it){
        delete *it;
    }
    flows.clear();

    model = nullptr;
}

bool Model::deleteModel(){
    return ModelBody::deleteModel();
}

bool ModelBody::deleteModel(){
    if(model != nullptr){
        delete model;
        return true;
    }
    return false;
}
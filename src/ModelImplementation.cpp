#include "./ModelImplementation.hpp"
#include "./Model.hpp"
#include <iostream>
#include <math.h>
using namespace std;

ModelImplementation::ModelImplementation() : name("") {}

ModelImplementation::ModelImplementation(string name) : name(name) {}

// Copy constructor
ModelImplementation::ModelImplementation(const ModelImplementation &m) : name(m.name)
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
ModelImplementation &ModelImplementation::operator=(const ModelImplementation &m)
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

string ModelImplementation::getName() const
{
    return name;
}

void ModelImplementation::setName(const string &name)
{
    this->name = name;
}
int ModelImplementation::getCurrentTime() const
{
    return currentTime;
}
void ModelImplementation::add(System *system)
{
    systems.push_back(system);
}

void ModelImplementation::add(Flow *flow)
{
    flows.push_back(flow);
}
Model::itSystem ModelImplementation::getSystem()
{
    return systems.begin();
}
Model::itFlow ModelImplementation::getFlow()
{
    return flows.begin();
}
Model::itSystem ModelImplementation::getSystem(string name)
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

Model::itFlow ModelImplementation::getFlow(string name)
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

int ModelImplementation::getSystemsSize(){
    return systems.size();
}
int ModelImplementation::getFlowsSize(){
    return flows.size();
}

void ModelImplementation::run(int initialTime, int finalTime)
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

ModelImplementation::~ModelImplementation()
{
    systems.clear();
    flows.clear();
}
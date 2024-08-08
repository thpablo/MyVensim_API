#include "./Model.hpp"

using namespace std;

Model::Model() : name("") {}

Model::Model(string name) : name(name) {}

// Copy constructor
Model::Model(const Model &m) : name(m.name)
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
Model &Model::operator=(const Model &m)
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

void Model::setName(const string &name)
{
    this->name = name;
}

void Model::add(System *system)
{
    systems.push_back(system);
}

void Model::add(Flow *flow)
{
    flows.push_back(flow);
}

// Run the model
void Model::run(int initialTime, int finalTime)
{
    for (int i = initialTime; i < finalTime; i++)
    {
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

Model::~Model()
{
    systems.clear();
    flows.clear();
}
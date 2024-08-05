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
    {
        add(&(**it));
    }

    // Clear the flows vector
    flows.clear();
    for (auto it = m.flows.begin(); it != m.flows.end(); ++it)
    {
        add(&(**it));
    }
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
    {
        systems.push_back(&(**it));
    }

    // Clear the flows vector
    flows.clear();
    for (auto it = m.flows.begin(); it != m.flows.end(); ++it)
    {
        flows.push_back(&(**it));
    }

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


void Model::printSystems()
{
    for (auto it = systems.begin(); it != systems.end(); ++it)
        cout << (*it)->getName() << ": " << (*it)->getAccumulatorValue() << endl;
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
            System *input = (*it)->getSource();
            System *output = (*it)->getTarget();

            // Verify null pointers to source and target
            if (input != nullptr)
                input->setAccumulatorValue(input->getAccumulatorValue() - (*it)->getTransportValue());
            if (output != nullptr)
                output->setAccumulatorValue(output->getAccumulatorValue() + (*it)->getTransportValue());
        }
    }
}

Model::~Model()
{
    systems.clear();
    flows.clear();
}

void Model::printRun(int time)
{
    cout << "Time: " << time << endl;
    for (auto it = flows.begin(); it != flows.end(); ++it)
    {
        cout << (*it)->getName() << ": " << (*it)->getTransportValue() << " ";
    }
    cout << endl;
    for (auto it = systems.begin(); it != systems.end(); ++it)
        cout << (*it)->getName() << ": " << (*it)->getAccumulatorValue() << endl;
}
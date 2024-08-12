#ifndef MODELO_H
#define MODELO_H

#include "./Flow.hpp"
#include "./System.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @brief Class Model represents the model with different systems and flows
 */
class Model
{
private:
    vector<Flow *> flows;
    vector<System *> systems;
    string name;

public:
    Model();
    Model(string name);

private:
    Model(const Model &m);
    Model &operator=(const Model &m);

public:
    /**
     * @brief Set the Name of model
     * 
     * @param name 
     */
    void setName(const string &name);
    /**
     * @brief Add a single System to the model
     * 
     * @param system System object
     */
    void add(System *system);
    /**
     * @brief Add a single System to the model
     * 
     * @param flow Flow object
     */
    void add(Flow *flow);
    /**
     * @brief Run the model, processing and calculating the values of all the systems
     * 
     * @param initialTime initial time to start the model
     * @param finalTime  final time to finish the model
     */
    void run(int initialTime, int finalTime);
    
    virtual ~Model();
};

#endif // MODELO_H

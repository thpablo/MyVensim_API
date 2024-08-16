#ifndef MODELO_H
#define MODELO_H

#include "./Flow.hpp"
#include "./System.hpp"
using namespace std;

/**
 * @brief Class Model represents the model with different systems and flows
 */
class Model
{
public:
    /**
     * @brief Set the Name of model
     * 
     * @param name name to the model
     */
    virtual void setName(const string &name) = 0;
    /**
     * @brief Get the Name object
     * 
     */
    virtual string getName() const = 0;
    /**
     * @brief Add a single System to the model
     * 
     * @param system System object
     */
    virtual void add(System *system) = 0;
    /**
     * @brief Add a single System to the model
     * 
     * @param flow Flow object
     */
    virtual void add(Flow *flow) = 0;
    /**
     * @brief Run the model, processing and calculating the values of all the systems
     * 
     * @param initialTime initial time to start the model
     * @param finalTime  final time to finish the model
     */
    virtual void run(int initialTime, int finalTime) = 0;
    
    /**
     * @brief Destroy the Model object
     * 
     */
    virtual ~Model(){};
};

#endif // MODELO_H

#ifndef MODEL_H
#define MODEL_H

#include "./Flow.hpp"
#include "./System.hpp"
#include <vector>
using namespace std;

/**
 * @brief Class Model represents the model with different systems and flows
 */
class Model
{
public:
    typedef typename vector<System *>::iterator itSystem;
    typedef typename vector<Flow *>::iterator itFlow;
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
     * @brief Get the current time in run() method
     *
     * @return current time in run() method
     */
    virtual int getCurrentTime() const = 0;
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
     * @brief Get the first system
     *
     * @return iterator for the first system
     */
    virtual itSystem getSystem() = 0;
    /**
     * @brief Get the first flow
     *
     * @return iterator for the first flow
     */
    virtual itFlow getFlow() = 0;
    /**
     * @brief Get the System object
     *
     * @param name name to find the systems
     * @return itSystem Iterator to the system or end if not found
     */
    virtual itSystem getSystem(string name) = 0;
    /**
     * @brief Get the Flow object
     *
     * @param name name to find the flow
     * @return itFlow Iterator to the flow or end if not found
     */
    virtual itFlow getFlow(string name) = 0;

    /**
     * @brief Get the System Size object
     * 
     * @return size of systems
     */
    virtual int getSystemsSize() = 0;

    /**
     * @brief Get the Flows Size object
     * 
     * @return size of Flows
     */
    virtual int getFlowsSize() = 0;

    /**
     * @brief Run the model, processing and calculating the values of all the systems
     *
     * @param initialTime initial time to start the model
     * @param finalTime  final time to finish the model
     */
    virtual void run(int initialTime, int finalTime) = 0;
    /**
     * @brief Friend class to unit tests
     *
     */
    friend class UnitModel;
    /**
     * @brief Destroy the Model object
     *
     */
    virtual ~Model() {};
};

#endif // MODEL_H

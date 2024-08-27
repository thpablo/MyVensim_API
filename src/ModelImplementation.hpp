#ifndef MODELIMPLEMENTATION_H
#define MODELIMPLEMENTATION_H

#include "./Flow.hpp"
#include "./System.hpp"
#include "./Model.hpp"
#include <vector>
using namespace std;
/**
 * @brief Class ModelImplementation represents the model with different systems and flows
 */
class ModelImplementation : public Model
{
private:
    vector<Flow *> flows;
    vector<System *> systems;
    string name;
    int currentTime;
    static ModelImplementation * model;

public:
    static ModelImplementation *createModel(string name, int currentTime);
private:
    /**
     * @brief Construct a new ModelImplementation object
     *
     */
    ModelImplementation();
    /**
     * @brief Construct a new ModelImplementation object with a name
     *
     * @param name name to the model
     */
    ModelImplementation(string name, int currentTime);
    ModelImplementation(const ModelImplementation &m);
    ModelImplementation &operator=(const ModelImplementation &m);

public:
    /**
     * @brief Set the Name of model
     *
     * @param name name to the model
     */
    void setName(const string &name);
    /**
     * @brief Get the Name object
     */
    string getName() const;
    /**
     * @brief Get the current time in run() method
     *
     * @return current time in run() method
     */
    int getCurrentTime() const;

    /**
     * @brief Create a Model collection with a name
     * 
     * @param name name to the model
     * @return Model* 
     */
    static Model *createModel(string name = "");

public:
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

public:
    /**
     * @brief Get the System begin object
     *
     * @return reference to first system in collection
     */
    itSystem getSystem();

    /**
     * @brief Get the Flow begin object
     *
     * @return reference to first Flow in collection
     */
    itFlow getFlow();

    /**
     * @brief Get the System object by name
     *
     * @return reference to first system finds by name
     */
    itSystem getSystem(string name);
    /**
     * @brief Get the flow object by name
     *
     * @return reference to first flow finds by name
     */
    itFlow getFlow(string name);

    /**
     * @brief Get the Systems size
     *
     * @return number of systems in model
     */
    int getSystemsSize();

    /**
     * @brief Get the flows size
     *
     * @return number of flows in model
     */
    int getFlowsSize();
    /**
     * @brief Run the model, processing and calculating the values of all the systems
     *
     * @param initialTime initial time to start the model
     * @param finalTime  final time to finish the model
     */
    void run(int initialTime, int finalTime);

    /**
     * @brief Destroy the ModelImplementation object
     *
     */

    System* createSystem(string name, double value);
    bool deleteSystem(const string &name);
    bool deleteFlow(const string &name);
    virtual ~ModelImplementation();
};

#endif // MODELIMPLEMENTATION

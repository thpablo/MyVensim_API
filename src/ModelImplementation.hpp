#ifndef MODELOImplementation_H
#define MODELOImplementation_H

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

public:
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
    ModelImplementation(string name);

protected:
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

    /**
     * @brief Destroy the ModelImplementation object
     *
     */
    virtual ~ModelImplementation();
};

#endif // MODELOImplementation_H

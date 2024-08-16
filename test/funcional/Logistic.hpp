#ifndef LOGISTIC_HPP
#define LOGISTIC_HPP

#include "../../src/Flow.hpp"
#include "../../src/FlowImplementation.hpp"

/** 
 * @brief This class represents a logistic flow in the system dynamics model.
*/
class Logistic : public FlowImplementation
{
public:
    /**
     * @brief Construct a new Logistic object
     * 
     * @param name name of the flow
     * @param source reference to the source system
     * @param target reference to the target system
     */
    Logistic(string name, System *source, System *target);
    /**
     * @brief Implementation of equation in the flow
     * 
     * @return return the value of the equation of flow
     */
    double execute() override;
};

#endif

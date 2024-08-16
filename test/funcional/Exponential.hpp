#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "../../src/Flow.hpp"
#include "../../src/FlowImplementation.hpp"
/**
 * @brief This class represents a exponential flow in the system dynamics model.
 * 
 */
class Exponential : public FlowImplementation
{
public:
    /**
     * @brief Construct a new Exponential object
     * 
     * @param name name of the flow
     * @param input reference to the source system
     * @param output reference to the target system
     */
    Exponential(string name, System *input, System *output);
    /**
     * @brief Implementation of equation in the flow
     * 
     * @return return the value of the equation of flow
     */
    double execute() override;
};

#endif

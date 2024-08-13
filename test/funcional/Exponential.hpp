#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "../../src/Flow.hpp"
/**
 * @brief This class represents a exponential flow in the system dynamics model.
 * 
 */
class Exponential : public Flow
{
public:
    Exponential(string name, System *input, System *output);
    double execute() override;
};

#endif

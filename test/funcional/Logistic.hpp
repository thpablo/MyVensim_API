#ifndef LOGISTIC_HPP
#define LOGISTIC_HPP

#include "../../src/Flow.hpp"

/** 
 * @brief This class represents a logistic flow in the system dynamics model.
*/
class Logistic : public Flow
{
public:
    Logistic(string name, System *source, System *target);
    double execute() override;
};

#endif

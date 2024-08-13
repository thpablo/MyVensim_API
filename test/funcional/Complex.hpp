#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "../../src/Flow.hpp"

/**
 * @brief This class represents a complex flow in the system dynamics model.
 * 
 */
class Complex : public Flow
{
public:
    Complex(string name, System *source, System *target);
    double execute() override;
};

#endif

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
    /**
     * @brief Construct a new Complex object
     * 
     * @param name name of the flow
     * @param source reference to the source system
     * @param target reference to the target system
     */
    Complex(string name, System *source, System *target);
    
    /**
     * @brief Implementation of equation in the flow
     * 
     * @return return the value of the equation of flow
     */
    double execute() override;
};

#endif

#ifndef FLOW_H
#define FLOW_H

#include "./System.hpp"

/**
 * @brief Class Flow represents the flow in the system dynamics model.
 * 
 */
class Flow
{
public:
    /**
     * @brief Set the Name of the Flow
     * 
     * @param name name of the Flow
     */
    virtual void setName(const string &name) = 0;
    /**
     * @brief Get the Name of the Flow
     * 
     * @return name of the Flow
     */
    virtual string getName() const = 0;
    /**
     * @brief Set the System object that represents the source of the flux
     * 
     * @param source System object reference
     */
    virtual void setSource(System *source) = 0;
    /**
     * @brief Set the System object that represents the final target of the flux
     * 
     * @param target System object reference
     */
    virtual void setTarget(System *target) = 0;

    /**
     * @brief Get the Source System object reference
     * 
     * @return the source system object reference
     */
    virtual System *getSource() const = 0;
    /**
     * @brief Get the Target System object reference
     * 
     * @return the target system object reference
     */
    virtual System *getTarget() const = 0;

    /**
     * @brief Set the Transport Value object
     * 
     * @param value a value to transport in the Flow
     */
    virtual void setTransportValue(double value) = 0;
    /**
     * @brief Get the Transport Value object
     * 
     * @return the value of the transport
     */
    virtual double getTransportValue() const = 0;

    /**
     * @brief Abstract method that represents the equation of the Flow
     * 
     * @return double Value of the Flow
     */
    virtual double execute() = 0;

    /**
     * @brief Friend class to unit tests
     * 
     */
    friend class UnitFlow;

    /**
     * @brief Overload of the assignment operator
     * 
     * @return a copy of the flow object
     */
    virtual Flow &operator=(const Flow &f) = 0;
    /**
     * @brief Destroy the Flow object
     * 
     */
    virtual ~Flow(){};
};

#endif // FLOW_H
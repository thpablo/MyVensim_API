#ifndef FLOWImplementation_H
#define FLOWImplementation_H

#include "./System.hpp"
#include "./Flow.hpp"

/**
 * @brief Class Flow represents the flow in the system dynamics model.
 * 
 */
class FlowImplementation : public Flow
{
private:
    string name;
    System *source;
    System *target;
    double transportValue;

public:
    /**
     * @brief Construct a new Flow object
     * 
     */
    FlowImplementation();
    /**
     * @brief Construct a new Flow Implementation with just a name
     * 
     * @param name name to the FlowImplementation
     */
    FlowImplementation(string name);
    /**
     * @brief Construct a new FlowImplementation object
     * 
     * @param name name to the FlowImplementation
     * @param source reference to the source system
     * @param target reference to the target system
     */
    FlowImplementation(string name, System *source, System *target);

    /**
     * @brief Construct a new FlowImplementation object
     * 
     * @param name name to the FlowImplementation
     */

    FlowImplementation(const FlowImplementation &f);
    /**
     * @brief Construct a new FlowImplementation object
     * 
     * @param name name to the FlowImplementation
     */
    Flow &operator=(const Flow &f);

    /**
     * @brief Set the Name of the FlowImplementation
     * 
     * @param name 
     */
    void setName(const string &name);
    /**
     * @brief Get the Name of the FlowImplementation
     * 
     * @return name of the FlowImplementation
     */
    string getName() const;
    /**
     * @brief Set the System object that represents the source of the flux
     * 
     * @param source System object reference
     */
    void setSource(System *source);
    /**
     * @brief Set the System object that represents the final target of the flux
     * 
     * @param target System object reference
     */
    void setTarget(System *target);

    /**
     * @brief Get the Source System object reference
     * 
     * @return the source system object reference
     */
    System *getSource() const;
    /**
     * @brief Get the Target System object reference
     * 
     * @return the target system object reference
     */
    System *getTarget() const;

    /**
     * @brief Set the Transport Value object
     * 
     * @param value a value to transport in the FlowImplementation
     */
    void setTransportValue(double value);
    /**
     * @brief Get the Transport Value object
     * 
     * @return the value of the transport
     */
    double getTransportValue() const;

    /**
     * @brief Abstract method that represents the equation of the FlowImplementation
     * 
     * @return double Value of the FlowImplementation
     */
    virtual double execute() = 0;
    
    
    /**
     * @brief Destroy the FlowImplementation object
     * 
     */
    virtual ~FlowImplementation();
};

#endif // FLOWImplementation_H
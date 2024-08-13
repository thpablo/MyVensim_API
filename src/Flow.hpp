#ifndef FLOW_H
#define FLOW_H

#include "./System.hpp"

/**
 * @brief Class Flow represents the flow in the system dynamics model.
 * 
 */
class Flow
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
    Flow();
    /**
     * @brief Construct a new Flow object
     * 
     * @param name name to the flow
     * @param source reference to the source system
     * @param target reference to the target system
     */
    Flow(string name, System *source, System *target);
    /**
     * @brief Construct a new Flow object
     * 
     * @param name name to the flow
     */
    Flow(const Flow &f);
    /**
     * @brief Construct a new Flow object
     * 
     * @param name name to the flow
     */
    Flow &operator=(const Flow &f);

    /**
     * @brief Set the Name of the flow
     * 
     * @param name 
     */
    void setName(const string &name);
    /**
     * @brief Get the Name of the flow
     * 
     * @return name of the flow
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
     * @param value a value to transport in the flow
     */
    void setTransportValue(double value);
    /**
     * @brief Get the Transport Value object
     * 
     * @return the value of the transport
     */
    double getTransportValue() const;

    /**
     * @brief Abstract method that represents the equation of the flow
     * 
     * @return double Value of the flow
     */
    virtual double execute() = 0;
    /**
     * @brief Destroy the Flow object
     * 
     */
    virtual ~Flow();
};

#endif // FLOW_H
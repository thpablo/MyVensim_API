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
    Flow();
    Flow(string name, System *source, System *target);
    Flow(const Flow &f);
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
     * @return string 
     */
    string getName() const;
    /**
     * @brief Set the System object that represents the source of the flux
     * 
     * @param source System object reference
     * @return * void 
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
     * @return System* 
     */
    System *getSource() const;
    /**
     * @brief Get the Target System object reference
     * 
     * @return System* 
     */
    System *getTarget() const;

    /**
     * @brief Set the Transport Value object
     * 
     * @param value 
     */
    void setTransportValue(double value);
    /**
     * @brief Get the Transport Value object
     * 
     * @return double 
     */
    double getTransportValue() const;

    /**
     * @brief Abstract method that represents the equation of the flow
     * 
     * @return double Value of the flow
     */
    virtual double execute() = 0;
    virtual ~Flow();
};

#endif // FLOW_H
#ifndef FlowBody_H
#define FlowBody_H

#include "./handleBody.hpp"
#include "./Flow.hpp"

/**
 * @brief Class Flow represents the flow in the system dynamics model.
 * 
 */
class FlowBody : public Body
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
    FlowBody();
    /**
     * @brief Construct a new FlowBody object
     * 
     * @param name name to the FlowBody
     * @param source reference to the source system
     * @param target reference to the target system
     */
    FlowBody(string name, System *source, System *target);

    /**
     * @brief Construct a new FlowBody object
     * 
     * @param name name to the FlowBody
     */

    FlowBody(const FlowBody &f);
    /**
     * @brief Construct a new FlowBody object
     * 
     * @param name name to the FlowBody
     */
    FlowBody &operator=(const FlowBody &f);

    /**
     * @brief Set the Name of the FlowBody
     * 
     * @param name 
     */
    void setName(const string &name);
    /**
     * @brief Get the Name of the FlowBody
     * 
     * @return name of the FlowBody
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
     * @param value a value to transport in the FlowBody
     */
    void setTransportValue(double value);
    /**
     * @brief Get the Transport Value object
     * 
     * @return the value of the transport
     */
    double getTransportValue() const;    
    
    /**
     * @brief Destroy the FlowBody object
     * 
     */
    virtual ~FlowBody();

    friend class UnitFlow;
};

class FlowHandle : public Flow, public Handle<FlowBody>
{
    public:
    FlowHandle(){
        pImpl_->setName("");
        pImpl_->setSource(nullptr);
        pImpl_->setTarget(nullptr);
    }
    FlowHandle(string name, System *source, System *target) { 
        pImpl_->setName(name);
        pImpl_->setSource(source); 
        pImpl_->setTarget(target); 
    }
    
    void setName(const string &name) override { pImpl_->setName(name); }
    string getName() override { return pImpl_->getName(); }
    void setSource(System *source) override { pImpl_->setSource(source); }
    void setTarget(System *target) override { pImpl_->setTarget(target); }
    System *getSource() override { return pImpl_->getSource(); }
    System *getTarget() override { return pImpl_->getTarget(); }
    void setTransportValue(double value) override { pImpl_->setTransportValue(value); }
    double getTransportValue() override { return pImpl_->getTransportValue(); }
    double execute() override = 0;
    
    friend class UnitFlow;
};

#endif // FlowBody_H
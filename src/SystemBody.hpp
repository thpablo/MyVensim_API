#ifndef SystemBody_H
#define SystemBody_H

#include <string>
#include "./System.hpp"
#include "./handleBody.hpp"
using namespace std;

/**
 * @brief System class represents a single system in the system dynamics model.
 *
 */
class SystemBody : public Body
{
protected:
    string name;
    double accumulatorValue;

public:
    /**
     * @brief Construct a new SystemBody object
     *
     */
    SystemBody();
    /**
     * @brief Construct a new SystemBody object with name
     *
     * @param name name of the SystemBody
     */
    SystemBody(string name);
    /**
     * @brief Construct a new SystemBody object with a name and initial value
     *
     * @param name name of the SystemBody
     * @param value initial value to the accumulator
     */
    SystemBody(string name, double value);

    /**
     * @brief Implement the assignment operator
     *
     * @param s
     * @return SystemBody&
     */
    SystemBody &operator=(const SystemBody &s);
    /**
     * @brief Construct a new SystemBody object by a copy of another SystemBody object
     *
     * @param s another SystemBody object
     */
    SystemBody(System &s);

    /**
     * @brief Set the Name object
     *
     * @param name name of the SystemBody
     */
    void setName(const string &name);
    /**
     * @brief Get the Name object
     *
     * @return name of the SystemBody
     */
    string getName() const;
    /**
     * @brief Set the Accumulator Value object
     *
     * @param value a value to set the accumulator
     */
    void setAccumulatorValue(double value);
    /**
     * @brief Get the Accumulator Value object
     *
     * @return the value of the accumulator
     */
    double getAccumulatorValue() const;
    /**
     * @brief Destroy the SystemBody object
     *
     */
    virtual ~SystemBody();
    friend class UnitSystem;
};

class SystemHandle : public System, public Handle<SystemBody>
{
public:
    SystemHandle() : Handle<SystemBody>() {}
    SystemHandle(string name)
    {
        pImpl_->setName(name);
    }
    SystemHandle(string name, double value)
    {
        pImpl_->setName(name);
        pImpl_->setAccumulatorValue(value);
    }
    void setName(const string &name) override
    {
        pImpl_->setName(name);
    }
    string getName() override
    {
        return pImpl_->getName();
    }
    void setAccumulatorValue(double value) override
    {
        pImpl_->setAccumulatorValue(value);
    }
    double getAccumulatorValue() override
    {
        return pImpl_->getAccumulatorValue();
    }
};
#endif // SYSTEM_H

#ifndef SYSTEMImplementation_H
#define SYSTEMImplementation_H

#include <string>
#include "./System.hpp"
using namespace std;

/**
 * @brief System class represents a single system in the system dynamics model.
 *
 */
class SystemImplementation : public System
{
protected:
    string name;
    double accumulatorValue;

public:
    /**
     * @brief Construct a new SystemImplementation object
     *
     */
    SystemImplementation();
    /**
     * @brief Construct a new SystemImplementation object with name
     *
     * @param name name of the systemImplementation
     */
    SystemImplementation(string name);
    /**
     * @brief Construct a new SystemImplementation object with a name and initial value
     *
     * @param name name of the systemImplementation
     * @param value initial value to the accumulator
     */
    SystemImplementation(string name, double value);
    /**
     * @brief Construct a new SystemImplementation object by a copy of another SystemImplementation object
     *
     * @param s another systemImplementation object
     */
    SystemImplementation(const System &s);
    /**
     * @brief Overload of the assignment operator
     *
     * @param s another system object
     * @return A copy of the system object
     */
    System &operator=(const System &s);

    /**
     * @brief Set the Name object
     *
     * @param name name of the systemImplementation
     */
    void setName(const string &name);
    /**
     * @brief Get the Name object
     *
     * @return name of the systemImplementation
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
     * @brief Destroy the SystemImplementation object
     *
     */
    virtual ~SystemImplementation();
};

#endif // SYSTEM_H

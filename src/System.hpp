#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

/**
 * @brief System class represents a single system in the system dynamics model.
 * 
 */
class System
{
private:
    string name;
    double accumulatorValue;

public:
/**
 * @brief Construct a new System object
 * 
 */
    System();
/**
 * @brief Construct a new System object with name
 * 
 * @param name name of the system
 */
    System(string name);
/**
 * @brief Construct a new System object with a name and initial value
 * 
 * @param name name of the system
 * @param value initial value to the accumulator
 */
    System(string name, double value);
/**
 * @brief Construct a new System object by a copy of another System object
 * 
 * @param s another system object
 */
    System(const System &s);

    /**
     * @brief Set the Name object
     * 
     * @param name name of the system
     */
    void setName(const string &name);
    /**
     * @brief Get the Name object
     * 
     * @return name of the system
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
     * @brief Destroy the System object
     * 
     */
    virtual ~System();

    /**
     * @brief Construct a new System object
     * 
     * @param name name of the system
     */
    System(const System &s);

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
     * @param name name to the system
     */
    void setName(const string &name);
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName() const;
    /**
     * @brief Set the Accumulator Value object
     * 
     * @param value value to set the accumulator
     */
    void setAccumulatorValue(double value);
    /**
     * @brief Get the Accumulator Value object
     * 
     * @return value of the accumulator
     */
    double getAccumulatorValue() const;

    /**
     * @brief Destroy the System object
     * 
     */
    virtual ~System();
};

#endif // SYSTEM_H

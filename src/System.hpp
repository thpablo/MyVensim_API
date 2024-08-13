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
 * @param name 
 */
    System(string name);
/**
 * @brief Construct a new System object with a name and initial value
 * 
 * @param name 
 * @param value 
 */
    System(string name, double value);
/**
 * @brief Construct a new System object by a copy of another System object
 * 
 * @param s another system object
 */
    System(const System &s);

    System &operator=(const System &s);

    /**
     * @brief Set the Name object
     * 
     * @param name 
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
     * @param value 
     */
    void setAccumulatorValue(double value);
    /**
     * @brief Get the Accumulator Value object
     * 
     * @return double 
     */
    double getAccumulatorValue() const;

    /**
     * @brief Destroy the System object
     * 
     */
    virtual ~System();

    System(const System &s);

    System &operator=(const System &s);

    /**
     * @brief Set the Name object
     * 
     * @param name 
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
     * @param value 
     */
    void setAccumulatorValue(double value);
    /**
     * @brief Get the Accumulator Value object
     * 
     * @return double 
     */
    double getAccumulatorValue() const;

    virtual ~System();
};

#endif // SYSTEM_H

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
    System();
    System(string name);
    System(string name, double value);
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

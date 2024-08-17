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
public:
   /**
    * @brief Set the Name object
    *
    * @param name
    */
   virtual void setName(const string &name) = 0;
   /**
    * @brief Get the Name object
    *
    * @return string
    */
   virtual string getName() const = 0;
   /**
    * @brief Set the Accumulator Value object
    *
    * @param value value to set the accumulator
    */
   virtual void setAccumulatorValue(double value) = 0;
   /**
    * @brief Get the Accumulator Value object
    *
    * @return value of the accumulator
    */
   virtual double getAccumulatorValue() const = 0;
   /**
    * @brief Overload of the assignment operator
    * 
    * @param s system object
    * @return The system object copy
    */
   virtual System &operator=(const System &s) = 0;
   /**
    * @brief Friend class to unit tests
    * 
    */
   friend class UnitSystem;
   
   /**
    * @brief Destroy the System object
    *
    */
   virtual ~System() {};
};

#endif // SYSTEM_H

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
    * @brief Destroy the System object
    * 
    */
   virtual System& operator=(const System &s) = 0;
   virtual ~System(){};
};

#endif // SYSTEM_H

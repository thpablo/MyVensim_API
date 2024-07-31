#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

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
    void setName(const string &name);
    string getName() const;

    void setAccumulatorValue(double value);
    double getAccumulatorValue() const;

    ~System(); // Destructor declaration
};;

#endif // SYSTEM_H

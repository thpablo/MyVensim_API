#ifndef FLOW_H
#define FLOW_H

#include "../System/System.h"

class Flow
{
private:
    string name;
    System *input;
    System *output;
    double transportValue;

public:
    virtual double execute() = 0;
    Flow();
    Flow(string name, System *input, System *output);

    void setName(const string &name);
    string getName() const;
    void setInputSystem(System *input);
    void setOutputSystem(System *output);

    System *getInputSystem() const;
    System *getOutputSystem() const;

    void setTransportValue(double value);
    double getTransportValue() const;
    virtual ~Flow(); // Destructor declaration
};

#endif // FLOW_H
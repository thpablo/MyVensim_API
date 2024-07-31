#ifndef FLOW_H
#define FLOW_H

#include "../System/System.h"

class Flow
{
private:
    string name;
    System *source;
    System *target;
    double transportValue;

public:
    virtual double execute() = 0;
    Flow();
    Flow(string name, System *source, System *target);

    void setName(const string &name);
    string getName() const;
    void setSource(System *source);
    void setTarget(System *target);

    System *getSource() const;
    System *getTarget() const;

    void setTransportValue(double value);
    double getTransportValue() const;
    virtual ~Flow(); // Destructor declaration
};

#endif // FLOW_H
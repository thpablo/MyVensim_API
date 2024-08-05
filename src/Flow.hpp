#ifndef FLOW_H
#define FLOW_H

#include "./System.hpp"

class Flow
{
private:
    string name;
    System *source;
    System *target;
    double transportValue;

public:
    Flow();
    Flow(string name, System *source, System *target);
    Flow(const Flow &f);
    Flow &operator=(const Flow &f);

    void setName(const string &name);
    string getName() const;
    void setSource(System *source);
    void setTarget(System *target);

    System *getSource() const;
    System *getTarget() const;

    void setTransportValue(double value);
    double getTransportValue() const;

    virtual double execute() = 0;
    virtual ~Flow();
};

#endif // FLOW_H
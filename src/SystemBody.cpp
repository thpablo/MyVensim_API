#include "./SystemBody.hpp"

SystemBody::SystemBody() : name(""), accumulatorValue(0.0) {}

SystemBody::SystemBody(string name) : name(name), accumulatorValue(0.0) {}

SystemBody::SystemBody(string name, double value) : name(name), accumulatorValue(value) {}

// Copy constructor
SystemBody::SystemBody(System &s) : name(s.getName()), accumulatorValue(s.getAccumulatorValue()) {}

// Overload of the assignment operator
SystemBody &SystemBody::operator=(const SystemBody &s) {
    //Verify if the object is the same
    if(&s == this)
        return *this;

    name = s.getName();
    accumulatorValue = s.getAccumulatorValue();
    return *this;
}

void SystemBody::setName(const string &name) {
    this->name = name;
}

string SystemBody::getName() const {
    return name;
}

void SystemBody::setAccumulatorValue(double value) {
    accumulatorValue = value;
}

double SystemBody::getAccumulatorValue() const {
    return accumulatorValue;
}
SystemBody::~SystemBody() {}
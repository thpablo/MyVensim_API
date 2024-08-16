#include "./SystemImplementation.hpp"

SystemImplementation::SystemImplementation() : name(""), accumulatorValue(0.0) {}

SystemImplementation::SystemImplementation(string name) : name(name), accumulatorValue(0.0) {}

SystemImplementation::SystemImplementation(string name, double value) : name(name), accumulatorValue(value) {}

// Copy constructor
SystemImplementation::SystemImplementation(const System &s) : name(s.getName()), accumulatorValue(s.getAccumulatorValue()) {}

// Overload of the assignment operator
System &SystemImplementation::operator=(const System &s) {
    //Verify if the object is the same
    if(&s == this)
        return *this;

    name = s.getName();
    accumulatorValue = s.getAccumulatorValue();
    return *this;
}

void SystemImplementation::setName(const string &name) {
    this->name = name;
}

string SystemImplementation::getName() const {
    return name;
}

void SystemImplementation::setAccumulatorValue(double value) {
    accumulatorValue = value;
}

double SystemImplementation::getAccumulatorValue() const {
    return accumulatorValue;
}
SystemImplementation::~SystemImplementation() {}
#include "./System.hpp"

System::System() : name(""), accumulatorValue(0.0) {}

System::System(string name) : name(name), accumulatorValue(0.0) {}

System::System(string name, double value) : name(name), accumulatorValue(value) {}

// Copy constructor
System::System(const System &s) : name(s.name), accumulatorValue(s.accumulatorValue) {}

// Overload of the assignment operator
System &System::operator=(const System &s) {
    //Verify if the object is the same
    if(&s == this)
        return *this;

    name = s.name;
    accumulatorValue = s.accumulatorValue;
    return *this;
}

void System::setName(const string &name) {
    this->name = name;
}

string System::getName() const {
    return name;
}

void System::setAccumulatorValue(double value) {
    accumulatorValue = value;
}

double System::getAccumulatorValue() const {
    return accumulatorValue;
}
System::~System() {

}
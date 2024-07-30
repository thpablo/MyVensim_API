#include "System.h"

System::System() : name(""), accumulatorValue(0.0) {}

System::System(string name) : name(name), accumulatorValue(0.0) {}

System::System(string name, double value) : name(name), accumulatorValue(value) {}

System::~System() {

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

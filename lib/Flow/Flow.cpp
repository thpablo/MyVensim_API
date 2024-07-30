#include "Flow.h"

Flow::Flow() : name(""), input(nullptr), output(nullptr), transportValue(0.0) {}

Flow::Flow(string name, System *input, System *output) : name(name), input(input), output(output), transportValue(0.0) {}

void Flow::setName(const string &name) {
    this->name = name;
}

string Flow::getName() const {
    return name;
}

void Flow::setInputSystem(System *input) {
    this->input = input;
}

void Flow::setOutputSystem(System *output) {
    this->output = output;
}

System *Flow::getInputSystem() const {
    return input;
}

System *Flow::getOutputSystem() const {
    return output;
}

void Flow::setTransportValue(double value) {
    transportValue = value;
}

double Flow::getTransportValue() const {
    return transportValue;
}
Flow::~Flow() {
    
}

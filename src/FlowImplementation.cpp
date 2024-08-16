#include "./FlowImplementation.hpp"

FlowImplementation::FlowImplementation() : name(""), source(nullptr), target(nullptr), transportValue(0.0) {}

FlowImplementation::FlowImplementation(string name, System *source, System *target) : name(name), source(source), target(target), transportValue(0.0) {}

FlowImplementation::FlowImplementation(const FlowImplementation &f) : name(f.name), source(f.source), target(f.target), transportValue(f.transportValue) {}

// Overload of the assignment operator
Flow &FlowImplementation::operator=(const Flow &f) {
    // Verify if the object is the same
    if(&f == this)
        return *this;

    name = f.getName();
    source = f.getSource();
    target = f.getTarget();
    transportValue = f.getTransportValue();
    return *this;
}

void FlowImplementation::setName(const string &name) {
    this->name = name;
}

string FlowImplementation::getName() const {
    return name;
}

void FlowImplementation::setSource(System *source) {
    this->source = source;
}

void FlowImplementation::setTarget(System *target) {
    this->target = target;
}

System *FlowImplementation::getSource() const {
    return source;
}

System *FlowImplementation::getTarget() const {
    return target;
}

void FlowImplementation::setTransportValue(double value) {
    transportValue = value;
}

double FlowImplementation::getTransportValue() const {
    return transportValue;
}

FlowImplementation::~FlowImplementation() {
    
}

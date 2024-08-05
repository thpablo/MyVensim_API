#include "./Flow.hpp"

Flow::Flow() : name(""), source(nullptr), target(nullptr), transportValue(0.0) {}

Flow::Flow(string name, System *source, System *target) : name(name), source(source), target(target), transportValue(0.0) {}

Flow::Flow(const Flow &f) : name(f.name), source(f.source), target(f.target), transportValue(f.transportValue) {}

// Overload of the assignment operator
Flow &Flow::operator=(const Flow &f) {
    // Verify if the object is the same
    if(&f == this)
        return *this;

    name = f.name;
    source = f.source;
    target = f.target;
    transportValue = f.transportValue;
    return *this;
}

void Flow::setName(const string &name) {
    this->name = name;
}

string Flow::getName() const {
    return name;
}

void Flow::setSource(System *source) {
    this->source = source;
}

void Flow::setTarget(System *target) {
    this->target = target;
}

System *Flow::getSource() const {
    return source;
}

System *Flow::getTarget() const {
    return target;
}

void Flow::setTransportValue(double value) {
    transportValue = value;
}

double Flow::getTransportValue() const {
    return transportValue;
}

Flow::~Flow() {
    
}

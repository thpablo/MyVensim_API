#include "Flow.h"

Flow::Flow() : name(""), source(nullptr), target(nullptr), transportValue(0.0) {}

Flow::Flow(string name, System *source, System *target) : name(name), source(source), target(target), transportValue(0.0) {}

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

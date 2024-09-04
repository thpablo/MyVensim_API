#include "./FlowBody.hpp"

FlowBody::FlowBody() : name(""), source(nullptr), target(nullptr), transportValue(0.0) {}

FlowBody::FlowBody(string name, System *source, System *target) : name(name), source(source), target(target), transportValue(0.0) {}

FlowBody::FlowBody(const FlowBody &f) : name(f.name), source(f.source), target(f.target), transportValue(f.transportValue) {}

// Overload of the assignment operator
FlowBody &FlowBody::operator=(const FlowBody &f) {
    // Verify if the object is the same
    if(&f == this)
        return *this;

    name = f.getName();
    source = f.getSource();
    target = f.getTarget();
    transportValue = f.getTransportValue();
    return *this;
}

void FlowBody::setName(const string &name) {
    this->name = name;
}

string FlowBody::getName() const {
    return name;
}

void FlowBody::setSource(System *source) {
    this->source = source;
}

void FlowBody::setTarget(System *target) {
    this->target = target;
}

System *FlowBody::getSource() const {
    return source;
}

System *FlowBody::getTarget() const {
    return target;
}

void FlowBody::setTransportValue(double value) {
    transportValue = value;
}

double FlowBody::getTransportValue() const {
    return transportValue;
}

FlowBody::~FlowBody() {
    
}

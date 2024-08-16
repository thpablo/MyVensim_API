#include "Exponential.hpp"

Exponential::Exponential(string name, System *input, System *output): FlowImplementation(name, input, output) {}

double Exponential::execute()
{
    return 0.01 * getSource()->getAccumulatorValue();
}

#include "Exponential.hpp"

Exponential::Exponential(string name, System *input, System *output) : FlowHandle(name, input, output) {}
double Exponential::execute()
{
    return 0.01 * getSource()->getAccumulatorValue();
}

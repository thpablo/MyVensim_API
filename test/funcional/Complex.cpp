#include "Complex.hpp"

Complex::Complex(string name, System *source, System *target) : FlowImplementation(name, source, target) {}

double Complex::execute()
{
    return 0.01 * getSource()->getAccumulatorValue();
}

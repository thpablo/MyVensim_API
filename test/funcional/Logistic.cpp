#include "Logistic.hpp"

Logistic::Logistic(string name, System *source, System *target)
    : Flow(name, source, target) {}

double Logistic::execute()
{
    return 0.01 * getTarget()->getAccumulatorValue() * (1 - (getTarget()->getAccumulatorValue()) / 70);
}

#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <cmath>
#include <iostream>
using namespace std;

#include "../../src/System.hpp"
#include "../../src/Flow.hpp"
#include "../../src/Model.hpp"

// Exponential Class
class Exponential : public Flow
{
public:
    Exponential(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 0.01 * getSource()->getAccumulatorValue();
    }
};

// Logistic Class
class Logistic : public Flow
{
public:
    Logistic(string name, System *source, System *target) : Flow(name, source, target) {}
    double execute() override
    {
        return 0.01 * getTarget()->getAccumulatorValue() * (1 - (getTarget()->getAccumulatorValue()) / 70);
    }
};

// Complex Model Class
class Complex : public Flow
{
public:
    Complex(string name, System *source, System *target) : Flow(name, source, target) {}
    double execute() override
    {
        return 0.01 * getSource()->getAccumulatorValue();
    }
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif //FUNCIONAL_TESTS_H
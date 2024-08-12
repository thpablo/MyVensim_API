#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <cmath>
#include <iostream>
using namespace std;

#include "../../src/System.hpp"
#include "../../src/Flow.hpp"
#include "../../src/Model.hpp"

/**
 * @brief This class represents a exponential flow in the system dynamics model.
 * 
 */
class Exponential : public Flow
{
public:
    Exponential(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 0.01 * getSource()->getAccumulatorValue();
    }
};

/** 
 * @brief This class represents a logistic flow in the system dynamics model.
 */
class Logistic : public Flow
{
public:
    Logistic(string name, System *source, System *target) : Flow(name, source, target) {}
    double execute() override
    {
        return 0.01 * getTarget()->getAccumulatorValue() * (1 - (getTarget()->getAccumulatorValue()) / 70);
    }
};

/**
 * @brief This class represents a complex flow in the system dynamics model.
 * 
 */
class Complex : public Flow
{
public:
    Complex(string name, System *source, System *target) : Flow(name, source, target) {}
    double execute() override
    {
        return 0.01 * getSource()->getAccumulatorValue();
    }
};

/**
 * @brief Functional tests for the exponential flow.
 * 
 */
void exponentialFuncionalTest();

/**
 * @brief Logistic functional tests.
 * 
 */
void logisticalFuncionalTest();
/**
 * @brief Complex functional tests.
 * 
 */
void complexFuncionalTest();

#endif //FUNCIONAL_TESTS_H
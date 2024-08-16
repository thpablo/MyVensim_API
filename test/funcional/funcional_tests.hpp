#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include <assert.h>
#include <cmath>
#include <iostream>
#include "Complex.hpp"
#include "Exponential.hpp"
#include "Logistic.hpp"

/** ????? */
#include "../../src/System.hpp"
#include "../../src/Flow.hpp"
#include "../../src/Model.hpp"

#include "../../src/SystemImplementation.hpp"
#include "../../src/FlowImplementation.hpp"
#include "../../src/ModelImplementation.hpp"


using namespace std;

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
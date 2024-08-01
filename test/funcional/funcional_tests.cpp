#include "./funcional_tests.hpp"
#include <assert.h>
#include <cmath>
// Exponential Class
class Exponential : public Flow
{
public:
    Exponential(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 0.01 * getSource()->getAccumulatorValue();
    }
    Flow *create() const override
    {
        return new Exponential(*this);
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
    Flow *create() const override{
        return new Logistic(*this);
    }
};

// Complex Model Class
class Complex : public Flow
{
public:
    Complex(string name, System *source, System * target) : Flow(name, source, target) {}
    double execute() override{
       return 0.01 * getSource()->getAccumulatorValue(); 
    }
    Flow *create() const override{
        return new Complex(*this);
    }
};

void exponentialFuncionalTest()
{
    // Create the model
    Model m1 = Model("Model 1");

    // Add systems
    System source = System("POP 1", 100);
    System target = System("POP 2", 0);

    // Add systems and flows
    Exponential flow1 = Exponential("exponential", &source, &target);

    // Add systems and flows to the model
    m1.add(&source);
    m1.add(&target);
    m1.add(&flow1);

    // Execution
    m1.run(0,100);

    assert(fabs(source.getAccumulatorValue() - 36.6032) < 0.0001);
    assert(fabs(target.getAccumulatorValue() - 63.3968) < 0.0001);
}
void logisticalFuncionalTest()
{
    // Create the model
    Model m2 = Model("Model 2");

    System source = System("p1", 100);
    System target = System("p2", 10);

    Logistic flow2 = Logistic("logistic", &source, &target);

    m2.add(&source);
    m2.add(&target);
    m2.add(&flow2);

    m2.run(0,100);

    assert(fabs(source.getAccumulatorValue() - 88.2167) < 0.0001);
    assert(fabs(target.getAccumulatorValue() - 21.7833) < 0.0001);
}

void complexFuncionalTest()
{
   System Q1 = System("Q1", 100);
    System Q2 = System("Q2", 0);
    System Q3 = System("Q3", 100);
    System Q4 = System("Q4", 0);
    System Q5 = System("Q5", 0);

    Complex f = Complex("F", &Q1, &Q2);
    Complex g = Complex("G", &Q1, &Q3);
    Complex r = Complex("R", &Q2, &Q5);
    Complex t = Complex("T", &Q2, &Q3);
    Complex u = Complex("U", &Q3, &Q4);
    Complex v = Complex("V", &Q4, &Q1);

    Model m3 = Model("Model 3");
    m3.add(&Q1);
    m3.add(&Q2);
    m3.add(&Q3);
    m3.add(&Q4);
    m3.add(&Q5);

    m3.add(&f);
    m3.add(&g);
    m3.add(&r);
    m3.add(&t);
    m3.add(&u);
    m3.add(&v);
    m3.run(0,100);

    assert(fabs(Q1.getAccumulatorValue() - 31.8513) < 0.0001);
    assert(fabs(Q2.getAccumulatorValue() - 18.4003) < 0.0001);
    assert(fabs(Q3.getAccumulatorValue() - 77.1143) < 0.0001);
    assert(fabs(Q4.getAccumulatorValue() - 56.1728) < 0.0001);
    assert(fabs(Q5.getAccumulatorValue() - 16.4612) < 0.0001);

    //* Asserts
}
#include "./funcional_tests.hpp"
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

bool exponentialFuntionalTest()
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

    //assert(source->getAccumulatorValue() == );
}
bool logisticFuntionalTest()
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

    //assert(target.getAccumulatorValue() == );
}

bool complexFuntionalTest()
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

    //* Asserts
}
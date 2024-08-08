#include "./funcional_tests.hpp"
void exponentialFuncionalTest()
{
    // Create the model
    Model *m1 = new Model("Model 1");

    // Add systems
    System *source = new System("POP 1", 100);
    System *target = new System("POP 2", 0);

    // Add systems and flows
    Flow *flow1 = new Exponential("exponential", source, target);

    // Add systems and flows to the model
    m1->add(source);
    m1->add(target);
    m1->add(flow1);

    // Execution
    m1->run(0, 100);

    // Check the values
    assert((trunc(fabs(source->getAccumulatorValue() - 36.6032) * 10000)) <= 1);
    assert((trunc(fabs(target->getAccumulatorValue() - 63.3968) * 10000)) <= 1);
    // Deletes systems, flows, and models
    delete source;
    delete target;
    delete flow1;
    delete m1;
}
void logisticalFuncionalTest()
{
    // Create the model
    Model *m2 = new Model("Model 2");

    System *source = new System("p1", 100);
    System *target = new System("p2", 10);

    Flow *flow2 = new Logistic("logistic", source, target);

    m2->add(source);
    m2->add(target);
    m2->add(flow2);

    m2->run(0, 100);

    assert((trunc(fabs(source->getAccumulatorValue() - 88.2167) * 10000)) <= 1);
    assert((trunc(fabs(target->getAccumulatorValue() - 21.7833) * 10000)) <= 1);

    // Delete systems, flows, and models
    delete source;
    delete target;
    delete flow2;
    delete m2;
}

void complexFuncionalTest()
{
    System *Q1 = new System("Q1", 100);
    System *Q2 = new System("Q2", 0);
    System *Q3 = new System("Q3", 100);
    System *Q4 = new System("Q4", 0);
    System *Q5 = new System("Q5", 0);

    Flow *f = new Complex("F", Q1, Q2);
    Flow *g = new Complex("G", Q1, Q3);
    Flow *r = new Complex("R", Q2, Q5);
    Flow *t = new Complex("T", Q2, Q3);
    Flow *u = new Complex("U", Q3, Q4);
    Flow *v = new Complex("V", Q4, Q1);

    Model *m3 = new Model("Model 3");

    // add Systems and Flows
    m3->add(Q1);
    m3->add(Q2);
    m3->add(Q3);
    m3->add(Q4);
    m3->add(Q5);

    m3->add(f);
    m3->add(g);
    m3->add(r);
    m3->add(t);
    m3->add(u);
    m3->add(v);
    m3->run(0, 100);

    // Check the values
    assert((trunc(fabs(Q1->getAccumulatorValue() - 31.8513) * 10000)) <= 1);
    assert((trunc(fabs(Q2->getAccumulatorValue() - 18.4003) * 10000)) <= 1);
    assert((trunc(fabs(Q3->getAccumulatorValue() - 77.1143) * 10000)) <= 1);
    assert((trunc(fabs(Q4->getAccumulatorValue() - 56.1728) * 10000)) <= 1);
    assert((trunc(fabs(Q5->getAccumulatorValue() - 16.4612) * 10000)) <= 1);

    // Delete systems, flows, and models
    delete Q1;
    delete Q2;
    delete Q3;
    delete Q4;
    delete Q5;

    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;

    delete m3;
}
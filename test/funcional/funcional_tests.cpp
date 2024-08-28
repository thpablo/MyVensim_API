#include "./funcional_tests.hpp"

void exponentialFuncionalTest()
{
    // Create the model
    Model* m1 = Model::createModel("Model 1",0);

    // Add systems
    System *source = m1->createSystem("POP 1", 100);
    System *target = m1->createSystem("POP 2", 0);

    // Add systems and flows
    Flow *flow1 = m1->createFlow<Exponential>("flow1", nullptr, nullptr);
    flow1->setSource(source);
    flow1->setTarget(target);

    // Execution
    m1->run(0, 100);

    // Check the values
    assert(fabs(round((source->getAccumulatorValue() * 10000) - (36.6032 * 10000))) < 1);
    assert(fabs(round((target->getAccumulatorValue() * 10000) - (63.3968 * 10000))) < 1);
    
    Model::deleteModel();
}
void logisticalFuncionalTest()
{
    Model* m2 = Model::createModel("Model 2");

    System *source = m2->createSystem("p1", 100);
    System *target = m2->createSystem("p2", 10);

    Flow *flow2 = m2->createFlow<Logistic>("flow2", nullptr, nullptr);

    flow2->setSource(source);
    flow2->setTarget(target);

    m2->run(0, 100);

    assert(fabs(round((source->getAccumulatorValue() * 10000) - (88.2167 * 10000))) < 1);
    assert(fabs(round((target->getAccumulatorValue() * 10000) - (21.7833 * 10000))) < 1);
    
    Model::deleteModel();
}

void complexFuncionalTest()
{
    Model *m3 = Model::createModel("Model 3");

    System *Q1 = m3->createSystem("Q1", 100);
    System *Q2 = m3->createSystem("Q2", 0);
    System *Q3 = m3->createSystem("Q3", 100);
    System *Q4 = m3->createSystem("Q4", 0);
    System *Q5 = m3->createSystem("Q5", 0);

    Flow *f = m3->createFlow<Complex>("F", nullptr, nullptr);
    Flow *g = m3->createFlow<Complex>("G", nullptr, nullptr);
    Flow *r = m3->createFlow<Complex>("R", nullptr, nullptr);
    Flow *t = m3->createFlow<Complex>("T", nullptr, nullptr);
    Flow *u = m3->createFlow<Complex>("U", nullptr, nullptr);
    Flow *v = m3->createFlow<Complex>("V", nullptr, nullptr);

    f->setSource(Q1); f->setTarget(Q2);
    g->setSource(Q1); g->setTarget(Q3);
    r->setSource(Q2); r->setTarget(Q5);
    t->setSource(Q2); t->setTarget(Q3);
    u->setSource(Q3); u->setTarget(Q4);
    v->setSource(Q4); v->setTarget(Q1);

    m3->run(0, 100);

    // Check the values
    assert(fabs(round((Q1->getAccumulatorValue() * 10000) - (31.8513 * 10000))) < 1);
    assert(fabs(round((Q2->getAccumulatorValue() * 10000) - (18.4003 * 10000))) < 1);
    assert(fabs(round((Q3->getAccumulatorValue() * 10000) - (77.1143 * 10000))) < 1);
    assert(fabs(round((Q4->getAccumulatorValue() * 10000) - (56.1728 * 10000))) < 1);
    assert(fabs(round((Q5->getAccumulatorValue() * 10000) - (16.4612 * 10000))) < 1);

    Model::deleteModel();
}
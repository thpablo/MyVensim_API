#include "unit_Model.hpp"
#include "../../src/Model.hpp"
#include "../../src/ModelImplementation.hpp"
#include "../../src/Flow.hpp"
#include "../../src/FlowImplementation.hpp"
#include "unit_Flow.hpp" // To use FlowUnitImplementation
#include "../../src/System.hpp"
#include "../../src/SystemImplementation.hpp"
#include <assert.h>

// This is a test class for the flow unit tests
class FlowToTest : public FlowImplementation
{
public:
    double execute() override{
        return 1.0;
    }
};

bool UnitModel::unit_Model_constructor(){
    Model *m = new ModelImplementation();
    assert(m->getName() == "");
    assert(m->getSystemsSize() == 0);
    assert(m->getFlowsSize() == 0);
    assert(m->getCurrentTime() == 0);
    delete m;
    return true;
}
bool UnitModel::unit_getName()
{
    Model *m = new ModelImplementation();
    m->setName("Model 1");
    assert(m->getName() == "Model 1");

    delete m;
    return true;
}

bool UnitModel::unit_setName()
{
    Model *m = new ModelImplementation();
    m->setName("Model 1");
    assert(m->getName() == "Model 1");

    delete m;
    return true;
}
bool UnitModel::unit_addSystem()
{
    Model *m = new ModelImplementation();
    System *s = new SystemImplementation();
    m->add(s);
    assert(m->getSystemsSize() == 1);

    delete s;
    delete m;
    return true;
}
bool UnitModel::unit_addFlow()
{
    Model *m = new ModelImplementation();
    Flow *f = new FlowToTest();
    m->add(f);
    assert(m->getFlowsSize() == 1);

    delete f;
    delete m;
    return true;
}
bool UnitModel::unit_run(){
    int initialTime = 0;
    int finalTime = 10;
    Model *m = new ModelImplementation();
    System *s = new SystemImplementation();
    Flow *f = new FlowToTest();
    m->add(s);
    m->add(f);
    m->run(initialTime, finalTime);
    assert(m->getCurrentTime() == (finalTime - 1));
    
    delete s;
    delete f;
    delete m;
    return true;
}
bool UnitModel::unit_getCurrentTime(){
    Model *m = new ModelImplementation();
    assert(m->getCurrentTime() == 0);
    delete m;
    return true;
}

bool UnitModel::unit_getSystems() {
    Model * model = new ModelImplementation("TestModel");
    System * s = new SystemImplementation("System1");
    model->add(s);

    auto it = model->getSystem("System1");
    assert((*it)->getName() == "System1");

    delete s;
    delete model;
    return true;
}

bool UnitModel::unit_getFlows() {
    Model * model = new ModelImplementation("TestModel");
    FlowToTest* f = new FlowToTest();
    f->setName("Flow1");
    model->add(f);

    auto it = model->getFlow("Flow1");
    assert((*it)->getName() == "Flow1");

    delete f;
    delete model;
    return true;
}
bool UnitModel::unit_getSystemsSize(){
    Model *m = new ModelImplementation();
    System *s = new SystemImplementation();
    m->add(s);
    assert(m->getSystemsSize() == 1);
    delete s;
    delete m;
    return true;
}
bool UnitModel::unit_getFlowsSize(){
    Model *m = new ModelImplementation();
    Flow *f = new FlowToTest();
    m->add(f);
    assert(m->getFlowsSize() == 1);
    delete f;
    delete m;
    return true;
}

bool UnitModel::unit_Model_destructor(){return true;}

void UnitModel::run_unit_tests_Model()
{
    UnitModel unit;
    assert(unit.unit_Model_constructor());
    assert(unit.unit_getName());
    assert(unit.unit_setName());
    assert(unit.unit_addSystem());
    assert(unit.unit_addFlow());
    assert(unit.unit_getCurrentTime());
    assert(unit.unit_getSystems());
    assert(unit.unit_getFlows());
    assert(unit.unit_getSystemsSize());
    assert(unit.unit_getFlowsSize());
    assert(unit.unit_run());
    assert(unit.unit_Model_destructor());
}
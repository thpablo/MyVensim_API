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
    FlowToTest(string name = "", System *source = nullptr, System *target = nullptr) : FlowImplementation(name, source, target) {}
    double execute() override{
        return 1.0;
    }
};

bool UnitModel::unit_Model_constructor(){
    Model *m = Model::createModel("");
    assert(m->getName() == "");
    assert(m->getSystemsSize() == 0);
    assert(m->getFlowsSize() == 0);
    assert(m->getCurrentTime() == 0);
    Model::deleteModel();
    return true;
}
bool UnitModel::unit_getName()
{
    Model *m = Model::createModel("");
    m->setName("Model 1");
    assert(m->getName() == "Model 1");

    Model::deleteModel();
    return true;
}

bool UnitModel::unit_setName()
{
    Model *m = Model::createModel("");
    m->setName("Model 1");
    assert(m->getName() == "Model 1");

    Model::deleteModel();
    return true;
}
bool UnitModel::unit_addSystem()
{
    Model *model = Model::createModel("");
    model->createSystem("", 0);
    assert(model->getSystemsSize() == 1);

    Model::deleteModel();
    return true;
}
bool UnitModel::unit_addFlow()
{
    Model *m = Model::createModel("");
    System * s1 = m->createSystem("System1", 0);
    System * s2 = m->createSystem("System2", 0);
    m->createFlow<FlowToTest>("Flow1", s1, s2);
    assert(m->getFlowsSize() == 1);

    Model::deleteModel();
    return true;
}
bool UnitModel::unit_run(){
    int initialTime = 0;
    int finalTime = 10;
    Model *m = Model::createModel("");
    System * s = m->createSystem("System1", 0);
    m->createFlow<FlowToTest>("Flow1", s, s);

    m->run(initialTime, finalTime);
    assert(m->getCurrentTime() == (finalTime - 1));
    
    Model::deleteModel();
    return true;
}
bool UnitModel::unit_getCurrentTime(){
    Model *m = Model::createModel("Model1");
    assert(m->getCurrentTime() == 0);
    Model::deleteModel();
    return true;
}

bool UnitModel::unit_getSystems() {
    Model * model = Model::createModel("TestModel");
    model->createSystem("System1",0);

    auto it = model->getSystem("System1");
    assert((*it)->getName() == "System1");

    Model::deleteModel();
    return true;
}
bool UnitModel::unit_getFlows() {
    Model * model = Model::createModel("TestModel");
    model->createFlow<FlowToTest>("Flow1", nullptr, nullptr);
    auto it = model->getFlow("Flow1");
    assert((*it)->getName() == "Flow1");
    Model::deleteModel();
    return true;
}
bool UnitModel::unit_getSystemsSize(){
    Model *model = Model::createModel("");
    model->createSystem("", 0);
    assert(model->getSystemsSize() == 1);

    Model::deleteModel();
    return true;
}
bool UnitModel::unit_getFlowsSize(){
    Model *m = Model::createModel("");
    m->createFlow<FlowToTest>("Flow1", nullptr, nullptr);
    assert(m->getFlowsSize() == 1);
    Model::deleteModel();
    return true;
}

bool UnitModel::unit_Model_destructor(){ return true; }

#include <iostream>
using namespace std;

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
    assert(unit.unit_getFlowsSize());;
    assert(unit.unit_run());;
    assert(unit.unit_Model_destructor());
}
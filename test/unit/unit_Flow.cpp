#include "unit_Flow.hpp"
#include "../../src/Flow.hpp"
#include "../../src/System.hpp"
#include "../../src/SystemImplementation.hpp"
#include <assert.h>

class FlowToTests : public FlowImplementation{
    public:
    FlowToTests() : FlowImplementation() {}
    FlowToTests(const std::string& name, System* source, System* target) : FlowImplementation(name, source, target) {}
    double execute() override {
        return 1.0;
    }
};


bool UnitFlow::unit_getName()
{
    System * s = new SystemImplementation("System");
    Flow * f = new FlowToTests("Flow 1", s, s);
    assert(f->getName() == "Flow 1");

    delete s;
    delete f;
    return true;
}


bool UnitFlow::unit_setName()
{
    Flow * f =  new FlowToTests();
    f->setName("Flow 1");
    assert(f->getName() == "Flow 1");

    delete f;
    return true;
}

bool UnitFlow::unit_setSource()
{
    System * s = new SystemImplementation();
    Flow * f = new FlowToTests("Flow 1", nullptr, nullptr);
    f->setSource(s);
    assert(f->getSource() == s);

    delete f;
    delete s;
    return true;
}

bool UnitFlow::unit_setTarget()
{
    System * s = new SystemImplementation();
    Flow * f = new FlowToTests("Flow 1", nullptr, nullptr);
    f->setTarget(s);
    assert(f->getTarget() == s);

    delete f;
    delete s;
    return true;
}

bool UnitFlow::unit_getSource()
{
    System * s = new SystemImplementation();
    Flow * f = new FlowToTests("Flow 1", s, nullptr);
    assert(f->getSource() == s);

    delete f;
    delete s;
    return true;
}

bool UnitFlow::unit_getTarget()
{
    System * s = new SystemImplementation();
    Flow * f = new FlowToTests("Flow 1", nullptr, s);
    assert(f->getTarget() == s);

    delete f;
    delete s;
    return true;
}

bool UnitFlow::unit_setTransportValue()
{
    Flow * f = new FlowToTests("Flow 1", nullptr, nullptr);
    f->setTransportValue(10.0);
    assert(f->getTransportValue() == 10.0);

    delete f;
    return true;
}

bool UnitFlow::unit_getTransportValue()
{
    Flow * f = new FlowToTests("Flow 1", nullptr, nullptr);
    f->setTransportValue(10.0);
    assert(f->getTransportValue() == 10.0);

    delete f;
    return true;
}

bool UnitFlow::unit_operatorAssignament()
{
    System * s = new SystemImplementation();
    Flow * f1 = new FlowToTests("Flow 1", s, s);
    Flow * f2 = new FlowToTests("Flow 2", nullptr, nullptr);
    *f2 = *f1;
    assert(f2->getName() == "Flow 1");
    assert(f2->getSource() == s);
    assert(f2->getTarget() == s);
    assert(f2->getTransportValue() == 0.0);

    delete f1;
    delete f2;
    delete s;
    return true;
}

bool UnitFlow::unit_Flow_destructor(){ return true;}

void UnitFlow::run_unit_tests_Flow()
{
    UnitFlow unit;
    assert(unit.unit_getName());
    assert(unit.unit_setName());
    assert(unit.unit_setSource());
    assert(unit.unit_setTarget());
    assert(unit.unit_getSource());
    assert(unit.unit_getTarget());
    assert(unit.unit_setTransportValue());
    assert(unit.unit_getTransportValue());
    assert(unit.unit_operatorAssignament());
}
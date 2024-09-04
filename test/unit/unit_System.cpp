#include <assert.h>
#include "unit_System.hpp"
#include "../../src/SystemBody.hpp"
#include "../../src/System.hpp"

#include <iostream>

bool UnitSystem::unit_System_constructor()
{
    SystemBody * s = new SystemBody();
    assert(s->getName() == "");
    assert(s->getAccumulatorValue() == 0.0);
    SystemBody s1("System 1", 10.0);
    assert(s1.getName() == "System 1");
    assert(s1.getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_setName()
{
    SystemBody * s = new SystemBody();
    s->setName("System 1");
    assert(s->getName() == "System 1");
    delete s;
    return true;
}

bool UnitSystem::unit_getName()
{
    SystemBody * s = new SystemBody("System 1");
    assert(s->getName() == "System 1");
    delete s;
    return true;
}

bool UnitSystem::unit_setAccumulatorValue()
{
    SystemBody * s = new SystemBody("System 1", 0.0);
    s->setAccumulatorValue(10.0);
    assert(s->getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_getAccumulatorValue()
{
    SystemBody * s = new SystemBody("System 1", 10.0);
    assert(s->getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_operatorAssignament()
{
    SystemBody * s1 = new SystemBody("System 1", 10.0);
    SystemBody * s2 = new SystemBody();
    *s2 = *s1;
    assert(s2->getName() == "System 1");
    assert(s2->getAccumulatorValue() == 10.0);

    delete s1;
    delete s2;
    return true;
}

bool UnitSystem::unit_System_destructor(){return true;};

void UnitSystem::run_unit_tests_System()
{
    UnitSystem unit;
    assert(unit.unit_System_constructor());
    assert(unit.unit_setName());
    assert(unit.unit_getName());
    assert(unit.unit_setAccumulatorValue());;
    assert(unit.unit_getAccumulatorValue());;
    assert(unit.unit_operatorAssignament());
    assert(unit.unit_System_destructor());
}
#include <assert.h>
#include "unit_System.hpp"
#include "../../src/SystemImplementation.hpp"
#include "../../src/System.hpp"

#include <iostream>

bool UnitSystem::unit_System_constructor()
{
    System * s = new SystemImplementation();
    assert(s->getName() == "");
    assert(s->getAccumulatorValue() == 0.0);
    SystemImplementation s1("System 1", 10.0);
    assert(s1.getName() == "System 1");
    assert(s1.getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_setName()
{
    System * s = new SystemImplementation();
    s->setName("System 1");
    assert(s->getName() == "System 1");
    delete s;
    return true;
}

bool UnitSystem::unit_getName()
{
    System * s = new SystemImplementation("System 1");
    assert(s->getName() == "System 1");
    delete s;
    return true;
}

bool UnitSystem::unit_setAccumulatorValue()
{
    System * s = new SystemImplementation("System 1", 0.0);
    s->setAccumulatorValue(10.0);
    assert(s->getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_getAccumulatorValue()
{
    System * s = new SystemImplementation("System 1", 10.0);
    assert(s->getAccumulatorValue() == 10.0);
    delete s;
    return true;
}

bool UnitSystem::unit_operatorAssignament()
{
    System * s1 = new SystemImplementation("System 1", 10.0);
    System * s2 = new SystemImplementation();
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
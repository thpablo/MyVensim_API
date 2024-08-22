#ifndef UNITFLOW_HPP
#define UNITFLOW_HPP

#include "../../src/Flow.hpp"
#include "../../src/FlowImplementation.hpp"

class UnitFlow
{
public:
    bool unit_getName();
    bool unit_setName();
    bool unit_getSource();
    bool unit_setSource();
    bool unit_getTarget();
    bool unit_setTarget();
    bool unit_getTransportValue();
    bool unit_setTransportValue();
    bool unit_operatorAssignament();
    bool unit_Flow_destructor();
    void run_unit_tests_Flow();
};

#endif // UNITFLOW_HPP
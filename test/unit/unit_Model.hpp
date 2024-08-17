#ifndef UNITMODEL_HPP
#define UNITMODEL_HPP

class UnitModel
{
public:
//TESTES GETS SYSTEMS FLOWS SYSTEMS SIZE FLOWS SIZE
    bool unit_Model_constructor();
    bool unit_setName();
    bool unit_getName();
    bool unit_addSystem();
    bool unit_addFlow();
    bool unit_getCurrentTime();
    bool unit_getSystems();
    bool unit_getFlows();
    bool unit_getSystemsSize();
    bool unit_getFlowsSize();
    bool unit_run();
    bool unit_Model_destructor();
    void run_unit_tests_Model();
};

#endif // UNITMODEL_HPP
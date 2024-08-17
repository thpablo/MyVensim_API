#include "unit_tests.hpp"

void run_unit_tests_globals(){
    UnitSystem us;
    us.run_unit_tests_System();
    UnitFlow uf;
    uf.run_unit_tests_Flow();
    UnitModel um;
    um.run_unit_tests_Model();
}
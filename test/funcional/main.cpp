#ifndef  MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "./funcional_tests.hpp"
#include <iostream>

int main(){
    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

#endif
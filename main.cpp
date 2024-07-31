#include <iostream>
#include <string>
#include <vector>
#include "./src/Model.h"
#include "./src/Flow.h"
#include "./src/System.h"

/* IMPLEMENT DESTRUCTOR AND CANONICAL FORM FOR ALL CLASSES
COPY CONSTRUCTOR FOR ALL CLASSES
OVERLOAD OPERATOR =
DESTRUCTOR
---
ASSERT COMPARISON -> (SYSTEM VALUE - TRUE SYSTEM VALUE) < 0.0001 (DECIMAL PLACES VERIFICATION)
Functional tests and check if unit tests need to be done
*/

#define MODEL_3
#define CASE_X

using namespace std;

class Isolated : public Flow
{
public:
    Isolated(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 1;
    }
};

class OutputFlow : public Flow
{
public:
    OutputFlow(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 1;
    }
};

class InputFlow : public Flow
{
public:
    InputFlow(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 1;
    }
};

class InputOutputFlow : public Flow
{
public:
    InputOutputFlow(string name, System *input, System *output) : Flow(name, input, output) {}
    double execute() override
    {
        return 1 + getSource()->getAccumulatorValue();
    }
};

int main()
{
    int initialTime = 0;
    int finalTime = 10;

#ifdef MODEL_3
    System Q1 = System("Q1", 100);
    System Q2 = System("Q2", 0);
    System Q3 = System("Q3", 100);
    System Q4 = System("Q4", 0);
    System Q5 = System("Q5", 0);

    F f = F("F", &Q1, &Q2);
    G g = G("G", &Q1, &Q3);
    R r = R("R", &Q2, &Q5);
    T t = T("T", &Q2, &Q3);
    U u = U("U", &Q3, &Q4);
    V v = V("V", &Q4, &Q1);

    Model m3 = Model("Model 3");
    m3.add(&Q1);
    m3.add(&Q2);
    m3.add(&Q3);
    m3.add(&Q4);
    m3.add(&Q5);

    m3.add(&f);
    m3.add(&g);
    m3.add(&r);
    m3.add(&t);
    m3.add(&u);
    m3.add(&v);
    m3.run(0,10);

#endif

#ifdef CASE_1
    Model case1 = Model("Case 1");
    System isolatedSystem = System("Isolated System", 100);

    case1.add(&isolatedSystem);
    case1.run(0,10);

#endif

#ifdef CASE_2
    Model case2 = Model("Case 2");
    Isolated isolatedFlow = Isolated("Isolated Flow", nullptr, nullptr);
    case2.add(&isolatedFlow);
    case2.run(0,10);

#endif

#ifdef CASE_3
    Model case3 = Model("Case 3");
    System outputSystem = System("Output System", 0);
    OutputFlow outputFlow = OutputFlow("Output Flow", nullptr, &outputSystem);
    case3.add(&outputSystem);
    case3.add(&outputFlow);
    case3.run(0,10);
#endif

#ifdef CASE_4
    Model case4 = Model("Case 4");
    System inputSystem = System("Input System", 100);
    InputFlow inputFlow = InputFlow("Input Flow", &inputSystem, nullptr);
    case4.add(&inputSystem);
    case4.add(&inputFlow);
    case4.run(0,10);
#endif

#ifdef CASE_5
    Model case5 = Model("Case 5");
    System inputSystem = System("Input System", 10);
    System outputSystem = System("Output System", 0);
    InputOutputFlow inputOutputFlow = InputOutputFlow("Input and Output Flow", &inputSystem, &outputSystem);
    case5.add(&inputSystem);
    case5.add(&outputSystem);
    case5.add(&inputOutputFlow);
    case5.run(0,10);
#endif

    return 0;
}
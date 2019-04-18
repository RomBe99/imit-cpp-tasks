#ifndef CPP_TASKS_DYNAMICTESTARRAYINT_H
#define CPP_TASKS_DYNAMICTESTARRAYINT_H

#include "DynamicArrayInt.h"

namespace testarrayint {
    bool defaultConstructorTest(const int expectedArraySize);

    bool sizeConstructorTest(const int expectedArraySize);

    bool sizeAndNumberConstructorTest(const int expectedArraySize, const int n);

    bool copyConstructorTest(const DynamicArrayInt &objForCopy);

    bool assigmentConstructorTest(DynamicArrayInt &objForAssigment);

    bool reserveConstructorTest(const int expectedArraySize, const int expectedArrayReserve);

    bool assignmentOperatorTest(const DynamicArrayInt &dynamicArrayInt);
}

#endif
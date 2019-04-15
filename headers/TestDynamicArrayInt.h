#ifndef CPP_TASKS_DYNAMICTESTARRAYINT_H
#define CPP_TASKS_DYNAMICTESTARRAYINT_H

#include "DynamicArrayInt.h"

namespace testArrayInt {
    bool defaultConstructorTest(const int expectedArraySize);

    bool sizeConstructorTest(const int expectedArraySize);

    bool sizeAndNumberConstructorTest(const int expectedArraySize, const int n);

    bool copyConstructorTest(const DynamicArrayInt &objForCopy);

    bool assigmentConstructor(DynamicArrayInt &objForAssigment);
}

#endif
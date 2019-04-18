#include <iostream>

#include "../headers/BoxClass.h"
#include "../headers/BoxClassProcessor.h"
#include "../headers/TestDynamicArrayInt.h"

int main() {
    DynamicArrayInt a = DynamicArrayInt(10);
    std::cout << testarrayint::assignmentOperatorTest(a);
    return 0;
}
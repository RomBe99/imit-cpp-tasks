#include "../headers/TestDynamicArrayInt.h"

bool testarrayint::defaultConstructorTest(const int expectedArraySize)  {
    const auto *temp = new DynamicArrayInt();
    const int RESULT = temp->getArraySize();

    delete temp;

    return RESULT == expectedArraySize;
}

bool testarrayint::sizeConstructorTest(const int expectedArraySize) {
    const auto *temp = new DynamicArrayInt(expectedArraySize);
    const int RESULT = temp->getArraySize();

    delete temp;

    return RESULT == expectedArraySize;
}

bool testarrayint::sizeAndNumberConstructorTest(const int expectedArraySize, const int n) {
    const auto *temp = new DynamicArrayInt(expectedArraySize, n);
    const int SIZE = temp->getArraySize();

    if (expectedArraySize != SIZE) {
        delete temp;

        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        if (temp->getElement(i) != n) {
            delete temp;

            return false;
        }
    }

    delete temp;

    return true;
}

bool testarrayint::copyConstructorTest(const DynamicArrayInt &objForCopy) {
    const auto *ARRAY_COPY = new DynamicArrayInt(objForCopy);
    const bool RESULT = *ARRAY_COPY != objForCopy;
    delete ARRAY_COPY;

    return RESULT;
}

// fixme Сделать тест для конструктора перемещения
bool testarrayint::assigmentConstructorTest(DynamicArrayInt &objForAssigment) {
    bool RESULT = false;
    return RESULT;
}

bool testarrayint::reserveConstructorTest(const int expectedArraySize, const int expectedArrayReserve) {
    const auto *temp = new DynamicArrayInt(expectedArraySize, 0, expectedArrayReserve);
    const bool RESULT = (temp->getArraySize() == expectedArraySize) && (temp->capacity() == expectedArrayReserve);
    delete temp;

    return RESULT;
}
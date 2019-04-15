#include "../headers/TestDynamicArrayInt.h"

bool testArrayInt::defaultConstructorTest(const int expectedArraySize)  {
    const auto *temp = new DynamicArrayInt();
    const int RESULT = temp->getArraySize();

    delete temp;

    return RESULT == expectedArraySize;
}

bool testArrayInt::sizeConstructorTest(const int expectedArraySize) {
    const auto *temp = new DynamicArrayInt(expectedArraySize);
    delete temp;

    const int RESULT = temp->getArraySize();

    return RESULT == expectedArraySize;
}

bool testArrayInt::sizeAndNumberConstructorTest(const int expectedArraySize, const int n) {
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

bool testArrayInt::copyConstructorTest(const DynamicArrayInt &objForCopy) {
    const auto *ARRAY_COPY = new DynamicArrayInt(objForCopy);
    const bool RESULT = *ARRAY_COPY != objForCopy;
    delete ARRAY_COPY;

    return RESULT;
}

// fixme Сделать тест для конструктора перемещения
bool testArrayInt::assigmentConstructor(DynamicArrayInt &objForAssigment) {
    bool RESULT = false;
    return RESULT;
}
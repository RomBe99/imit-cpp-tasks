#include "../headers/DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt() : DynamicArrayInt(DEFAULT_SIZE) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize) : DynamicArrayInt(arraySize, 0) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize, int n) {
    DynamicArrayInt::arraySize = arraySize;
    DynamicArrayInt::array = new int{arraySize};

    for (int i = 0; i < arraySize; i++) {
        array[i] = n;
    }
}

bool operator==(DynamicArrayInt firstArray, DynamicArrayInt secondArray) {
    const int SIZE = firstArray.arraySize;

    if (SIZE != secondArray.arraySize) {
        throw 1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (firstArray[i] != secondArray[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(DynamicArrayInt firstArray, DynamicArrayInt secondArray) {
    const int SIZE = firstArray.arraySize;

    if (SIZE != secondArray.arraySize) {
        throw 1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (firstArray[i] == secondArray[i]) {
            return false;
        }
    }

    return true;
}

void DynamicArrayInt::resize(const int newSize) {
    int *newArr = new int[newSize];

    for (int i = 0; i < arraySize; i++) {
        newArr[i] = arraySize > i ? array[i] : 0;
    }

    arraySize = newSize;
    array = newArr;
    delete[]newArr;
}

int DynamicArrayInt::operator[](const int index) {
    return DynamicArrayInt::array[index];
}

int DynamicArrayInt::getElement(const int index) const {
    return DynamicArrayInt::array[index];
}

int *DynamicArrayInt::getArray() const {
    return array;
}

int DynamicArrayInt::getArraySize() const {
    return arraySize;
}

DynamicArrayInt::~DynamicArrayInt() {
    delete[]array;
}

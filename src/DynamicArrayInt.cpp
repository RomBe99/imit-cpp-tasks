#include "../headers/DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt(const int arraySize) : DynamicArrayInt(arraySize, 0) {}

DynamicArrayInt::DynamicArrayInt() : DynamicArrayInt(DEFAULT_SIZE) {}


DynamicArrayInt::DynamicArrayInt(const int arraySize, int n) {
    DynamicArrayInt::arraySize = arraySize;
    DynamicArrayInt::array = new int{arraySize};

    for (int i = 0; i < arraySize; i++) {
        array[i] = n;
    }
}

int DynamicArrayInt::setElement(int index) {
    return DynamicArrayInt::array[index];
}

int *DynamicArrayInt::getArray() const {
    return array;
}

int DynamicArrayInt::getArraySize() const {
    return arraySize;
}

int DynamicArrayInt::operator[](const unsigned int index) {
    return DynamicArrayInt::array[index];
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

DynamicArrayInt::~DynamicArrayInt() {
    delete[]array;
}

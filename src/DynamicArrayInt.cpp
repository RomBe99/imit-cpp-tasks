#include "../headers/DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt(const int arraySize) {
    DynamicArrayInt::arraySize = arraySize;
    DynamicArrayInt::array = new int{arraySize};

    for (int i = 0; i < arraySize; i++) {
        array[i] = 0;
    }
}

DynamicArrayInt::DynamicArrayInt() : DynamicArrayInt(DEFAULT_SIZE) {}


DynamicArrayInt::DynamicArrayInt(const int arraySize, int n) : DynamicArrayInt(arraySize) {
    for (int i = 0; i < arraySize; i++) {
        array[i] = n;
    }
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
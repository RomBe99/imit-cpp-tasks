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

bool operator==(const DynamicArrayInt left, const DynamicArrayInt right) {
    const int SIZE = left.arraySize;

    if (SIZE != right.arraySize) {
        throw 1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const DynamicArrayInt left, const DynamicArrayInt right){
    const int SIZE = left.arraySize;

    if (SIZE != right.arraySize) {
        throw 1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (left[i] == right[i]) {
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

int DynamicArrayInt::operator[](const int index) const {
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

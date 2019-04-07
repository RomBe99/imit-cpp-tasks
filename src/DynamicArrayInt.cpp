#include "../headers/DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt() : DynamicArrayInt(DynamicArrayInt::DEFAULT_SIZE) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize) : DynamicArrayInt(arraySize, 0) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize, int n) {
    this->arraySize = arraySize;
    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        array[i] = n;
    }
}

DynamicArrayInt::DynamicArrayInt(const DynamicArrayInt &dynamicArrayInt) {
    setArraySize(dynamicArrayInt.arraySize);

    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        array[i] = dynamicArrayInt.array[i];
    }
}

DynamicArrayInt &DynamicArrayInt::operator=(const DynamicArrayInt &dynamicArrayInt) {
    if (!(*this == dynamicArrayInt)) {
        *this = DynamicArrayInt(dynamicArrayInt);
    }

    return *this;
}

bool operator==(const DynamicArrayInt &left, const DynamicArrayInt &right) {
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

bool operator!=(const DynamicArrayInt &left, const DynamicArrayInt &right){
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

bool operator<(const DynamicArrayInt &left, const DynamicArrayInt &right) {
    const int SIZE = (left.arraySize >= right.arraySize ? left.arraySize : right.arraySize);

    for (int i = 0; i < SIZE; i++) {
        if (left[i] >= right[i]) {
            return false;
        }
    }

    return true;
}

bool operator<=(const DynamicArrayInt &left, const DynamicArrayInt &right) {
    const int SIZE = (left.arraySize >= right.arraySize ? left.arraySize : right.arraySize);

    for (int i = 0; i < SIZE; i++) {
        if (left[i] > right[i]) {
            return false;
        }
    }

    return true;
}

bool operator>(const DynamicArrayInt &left, const DynamicArrayInt &right) {
    const int SIZE = (left.arraySize >= right.arraySize ? left.arraySize : right.arraySize);

    for (int i = 0; i < SIZE; i++) {
        if (left[i] <= right[i]) {
            return false;
        }
    }

    return true;
}

bool operator>=(const DynamicArrayInt &left, const DynamicArrayInt &right) {
    const int SIZE = (left.arraySize >= right.arraySize ? left.arraySize : right.arraySize);

    for (int i = 0; i < SIZE; i++) {
        if (left[i] < right[i]) {
            return false;
        }
    }

    return true;
}

DynamicArrayInt operator+(const DynamicArrayInt &left, const DynamicArrayInt &right) {
    DynamicArrayInt newDynamicArrayInt = DynamicArrayInt(left.arraySize + right.arraySize);

    const int LEFT_ARRAY_SIZE = left.arraySize;

    for (int i = 0; i < LEFT_ARRAY_SIZE; i++) {
        newDynamicArrayInt.array[i] = left.array[i];
    }

    const int RIGHT_ARRAY_SIZE = right.arraySize;

    for (int j = 0; j < RIGHT_ARRAY_SIZE; j++) {
        newDynamicArrayInt.array[LEFT_ARRAY_SIZE + j] = right.array[j];
    }

    return newDynamicArrayInt;
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

void DynamicArrayInt::setArraySize(const int arraySize) {
    this.arraySize = arraySize;
}

std::istream &operator>>(std::istream &is, DynamicArrayInt &dynamicArrayInt) {
    int arraySize;
    is >> arraySize;

    dynamicArrayInt.setArraySize(arraySize);

    for (int i = 0; i < arraySize; i++) {
        is >> dynamicArrayInt.array[i];
    }
}

std::ostream &operator<<(std::ostream &os, const DynamicArrayInt &dynamicArrayInt) {
    const int SIZE = dynamicArrayInt.arraySize;

    os << "arraySize: " << SIZE << " arrayElements: ";

    for (int i = 0; i < SIZE; i++) {
        os << dynamicArrayInt.array[i];
    }

    os << '\n';

    return os;
}

int DynamicArrayInt::operator[](const int index) const {
    return array[index];
}

int DynamicArrayInt::getElement(const int index) const {
    return array[index];
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

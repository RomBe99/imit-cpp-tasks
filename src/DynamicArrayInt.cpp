#include "../headers/DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt() : DynamicArrayInt(DynamicArrayInt::DEFAULT_SIZE) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize) : DynamicArrayInt(arraySize, 0) {}

DynamicArrayInt::DynamicArrayInt(const int arraySize, const int n) {
    this->arraySize = arraySize;
    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        array[i] = n;
    }
}

DynamicArrayInt::DynamicArrayInt(const int arraySize, const int n, const int newReserve) : DynamicArrayInt(arraySize, n) {
    setReserve(newReserve);
}

DynamicArrayInt::DynamicArrayInt(const DynamicArrayInt &dynamicArrayInt) {
    setArraySize(dynamicArrayInt.arraySize);

    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        array[i] = dynamicArrayInt.array[i];
    }
}

DynamicArrayInt::DynamicArrayInt(DynamicArrayInt &&dynamicArrayInt) noexcept {
    setArraySize(dynamicArrayInt.arraySize);

    array = dynamicArrayInt.array;

    dynamicArrayInt.array = nullptr;
}

void DynamicArrayInt::setArraySize(const int newArraySize) {
    arraySize = newArraySize;
}

void DynamicArrayInt::setReserve(const int newReserve) {
    reserve = newReserve;
}

DynamicArrayInt& DynamicArrayInt::operator=(DynamicArrayInt &&dynamicArrayInt) noexcept {
    std::swap(arraySize, dynamicArrayInt.arraySize);
    std::swap(array, dynamicArrayInt.array);

    return *this;
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

bool operator!=(const DynamicArrayInt &left, const DynamicArrayInt &right) {
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

void DynamicArrayInt::resize(const int newArraySize) {
    if (newArraySize > arraySize + reserve) {
        int *newArr = new int[newArraySize];

        for (int i = 0; i < arraySize; i++) {
            newArr[i] = arraySize > i ? array[i] : 0;
        }

        std::swap(newArr, array);
        delete[]newArr;
    } else {
        if (newArraySize < arraySize) {
            for (int i = newArraySize; i < arraySize; ++i) {
                array[i] = 0;
            }

            setReserve(reserve + arraySize - newArraySize);
        }
    }

    setArraySize(newArraySize);
}

void DynamicArrayInt::reserveMemory(const int newReserve) {
    setReserve(newReserve);

    const int NEW_SIZE = arraySize + reserve;

    int *temp = new int [NEW_SIZE];

    for (int i = 0; i < NEW_SIZE; i++) {
        temp[i] = arraySize > i ? array[i] : 0;
    }

    std::swap(temp, array);
    delete[]temp;
}

std::istream &operator>>(std::istream &is, DynamicArrayInt &dynamicArrayInt) {
    int arraySize;
    is >> arraySize;

    dynamicArrayInt.setArraySize(arraySize);

    for (int i = 0; i < arraySize; i++) {
        is >> dynamicArrayInt.array[i];
    }

    return is;
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

void DynamicArrayInt::setArrayElement(const int index, const int value) {
    array[index] = value;
}

void DynamicArrayInt::pushBack(int value) {
    resize(arraySize + 1);
    array[arraySize - 1] = value;
}

void DynamicArrayInt::popBack() {
    resize(arraySize - 1);
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

int DynamicArrayInt::capacity() const {
    return reserve;
}

DynamicArrayInt::~DynamicArrayInt() {
    delete[]array;
}

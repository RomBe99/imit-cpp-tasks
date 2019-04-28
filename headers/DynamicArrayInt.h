#ifndef CPP_TASKS_DYNAMICARRAYINT_H
#define CPP_TASKS_DYNAMICARRAYINT_H

#include <iostream>

class DynamicArrayInt {
private:
    int *array;
    int arraySize;
    int reserve = 0;
    static const int DEFAULT_SIZE = 10;

    void setArraySize(const int arraySize);

public:
    DynamicArrayInt();

    explicit DynamicArrayInt(const int arraySize);

    DynamicArrayInt(const int arraySize, const int n);

    DynamicArrayInt(const int arraySize, const int n, const int newReserve);

    DynamicArrayInt(const DynamicArrayInt &dynamicArrayInt);

    DynamicArrayInt(DynamicArrayInt &&dynamicArrayInt) noexcept;

    DynamicArrayInt &operator=(const DynamicArrayInt &dynamicArrayInt);

    DynamicArrayInt &operator=(DynamicArrayInt &&dynamicArrayInt) noexcept ;

    friend bool operator==(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator!=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator<(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator<=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator>(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator>=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend DynamicArrayInt operator+(const DynamicArrayInt &left, const DynamicArrayInt &right);

    void resize(const int newArraySize);

    void reserveMemory(const int newReserve);

    friend std::istream &operator>>(std::istream &is, DynamicArrayInt &dynamicArrayInt);

    friend std::ostream &operator<<(std::ostream &os, const DynamicArrayInt &dynamicArrayInt);

    int operator[](const int index) const;

    void setArrayElement(const int index, const int value);

    void pushBack(int value);

    int popBack();

    int getElement(const int index) const;

    int *getArray() const;

    int getArraySize() const;

    int capacity() const;

    ~DynamicArrayInt();
};

#endif
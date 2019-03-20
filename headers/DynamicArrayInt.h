#ifndef CPP_TASKS_DYNAMICARRAYINT_H
#define CPP_TASKS_DYNAMICARRAYINT_H

#include <iostream>

class DynamicArrayInt {
private:
    int *array;
    int arraySize;
    const int DEFAULT_SIZE = 10;

    void setArraySize(const int arraySize);

public:
    DynamicArrayInt();

    explicit DynamicArrayInt(const int arraySize);

    DynamicArrayInt(const int arraySize, int n);

    // TODO Конструктор копирования

    // TODO Конструктор перемещения

    // TODO Оператор присваивания

    // TODO Оператор перемещения

    friend bool operator==(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator!=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator<(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator<=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator>(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend bool operator>=(const DynamicArrayInt &left, const DynamicArrayInt &right);

    friend DynamicArrayInt operator+(const DynamicArrayInt &left, const DynamicArrayInt &right);

    void resize(const int newSize);

    friend std::istream &operator>>(std::istream &is, DynamicArrayInt &dynamicArrayInt);

    friend std::ostream &operator<<(std::ostream &os, const DynamicArrayInt &dynamicArrayInt);

    int operator[](const int index) const;

    int getElement(const int index) const;

    int *getArray() const;

    int getArraySize() const;

    ~DynamicArrayInt();
};

#endif
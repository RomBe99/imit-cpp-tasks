#ifndef CPP_TASKS_DYNAMICARRAYINT_H
#define CPP_TASKS_DYNAMICARRAYINT_H

class DynamicArrayInt {
private:
    int *array;
    int arraySize;
    const int DEFAULT_SIZE = 10;

public:
    DynamicArrayInt();

    explicit DynamicArrayInt(const int arraySize);

    DynamicArrayInt(const int arraySize, int n);

    friend bool operator==(DynamicArrayInt firstArray, DynamicArrayInt secondArray);

    friend bool operator!=(DynamicArrayInt firstArray, DynamicArrayInt secondArray);

    friend DynamicArrayInt operator+(const DynamicArrayInt &firstArray, const DynamicArrayInt &secondArray);

    void resize(const int newSize);

    int operator[](const int index);

    int getElement(const int index) const;

    int *getArray() const;

    int getArraySize() const;

    ~DynamicArrayInt();
};

#endif
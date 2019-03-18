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

    friend bool operator==(const DynamicArrayInt left, const DynamicArrayInt right);

    friend bool operator!=(const DynamicArrayInt left, const DynamicArrayInt right);

    friend DynamicArrayInt operator+(const DynamicArrayInt &left, const DynamicArrayInt &right);

    void resize(const int newSize);

    int operator[](const int index) const;

    int getElement(const int index) const;

    int *getArray() const;

    int getArraySize() const;

    ~DynamicArrayInt();
};

#endif
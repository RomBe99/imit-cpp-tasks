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

    int setElement(int index);

    friend bool operator==(DynamicArrayInt firstArray, DynamicArrayInt secondArray);

    friend bool operator!=(DynamicArrayInt firstArray, DynamicArrayInt secondArray);

    friend bool operator+(DynamicArrayInt firstArray, DynamicArrayInt secondArray);

    int *getArray() const;

    int getArraySize() const;

    int operator[](const unsigned int index);

    void resize(const int newSize);

    ~DynamicArrayInt();
};


#endif
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

    int *getArray() const;

    int getArraySize() const;

    ~DynamicArrayInt();
};


#endif
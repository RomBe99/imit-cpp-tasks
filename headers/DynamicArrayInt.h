#ifndef CPP_TASKS_DYNAMICARRAYINT_H
#define CPP_TASKS_DYNAMICARRAYINT_H


class DynamicArrayInt {
private:
    int *array;
    int arraySize;

public:
    DynamicArrayInt();

    DynamicArrayInt(const unsigned long int arraySize);

    DynamicArrayInt(const unsigned long int arraySize, int n);

    int *getArray() const;

    int getArraySize() const;

    ~DynamicArrayInt();
};


#endif
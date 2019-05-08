#ifndef CPP_TASKS_LIST_H
#define CPP_TASKS_LIST_H

#include "Iterator.h"

template <typename T>
class List {
public:
    virtual void insert(const T value, const Iterator<List<T>> &iterator) = 0;
    virtual void deleteElement(const Iterator<List<T>> &iterator) = 0;
    virtual Iterator<List<T>> &iterator firstEnter(const T value) = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual Iterator<List<T>> &iterator begin() = 0;
};

#endif
#ifndef CPP_TASKS_ITERATOR_H
#define CPP_TASKS_ITERATOR_H

#include "List.h"

template <class T>
class Iterator {
public:
    virtual void start() = 0;
    virtual T getValue() const = 0;
    virtual void next() = 0;
    virtual bool isFinish() const = 0;
};

#endif
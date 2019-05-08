#ifndef CPP_TASKS_ITERATOR_H
#define CPP_TASKS_ITERATOR_H

#include "List.h"

template <template <typename> class List>
class Iterator {
    virtual void start() = 0;
    virtual T getValue() = 0;
    virtual void next() = 0;
    virtual bool isFinish() = 0;
};

#endif
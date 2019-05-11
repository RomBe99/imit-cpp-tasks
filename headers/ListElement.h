#ifndef CPP_TASKS_LISTELEMENT_H
#define CPP_TASKS_LISTELEMENT_H

template<typename T>
class ListElement {
    virtual T getValue() const = 0;
};

#endif

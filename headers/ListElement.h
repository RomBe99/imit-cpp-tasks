#ifndef CPP_TASKS_LISTELEMENT_H
#define CPP_TASKS_LISTELEMENT_H

template<typename T>
class ListElement {
public:
    virtual T getValue() const = 0;
};

#endif
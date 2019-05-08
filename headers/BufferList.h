#ifndef CPP_TASKS_BUFFERLIST_H
#define CPP_TASKS_BUFFERLIST_H

#include "List.h"

template <typename T>
class BufferList : public List<T> {
private:
    class ListElement {
    public:
        ListElement *nextElement = nullptr;
        T value;
        ListElement *previousElement = nullptr;

        explicit ListElement(const T value);
        ~ListElement();
    };
};

#endif

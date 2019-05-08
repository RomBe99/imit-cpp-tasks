#include "BufferList.h"

template<typename T>
BufferList<T>::ListElement::ListElement(const T value) {
    this->value = value;
}

template<typename T>
BufferList<T>::ListElement::~ListElement() {
    nextElement = nullptr;
    value = 0;
    previousElement = nullptr;
}
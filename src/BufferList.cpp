#include "../headers/BufferList.h"

template<typename T>
BufferList<T>::BidirectionalListElement::BidirectionalListElement(const T value) {
    this->value = value;
}

template<typename T>
BufferList<T>::BufferList() : BufferList(DEFAULT_SIZE) {}

template<typename T>
BufferList<T>::~BufferList() {
    // FIXME Исправить деструктор BufferList
    BidirectionalListElement *temp = bufferElement->nextElement;

    for (int i = 0; i < listSize; i++) {
        bufferElement->nextElement = temp->nextElement;
        delete temp;
        temp = bufferElement->nextElement;
    }
}
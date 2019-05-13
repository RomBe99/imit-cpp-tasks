#include "../headers/BufferList.h"

template<typename T>
BufferList<T>::BidirectionalListElement::BidirectionalListElement(const T value) : BidirectionalListElement(nullptr,
                                                                                                            value,
                                                                                                            nullptr) {}

template<typename T>
BufferList<T>::BidirectionalListElement::BidirectionalListElement(BufferList::BidirectionalListElement *nextElement,
                                                                  T value,
                                                                  BufferList::BidirectionalListElement *previousElement) {
    this->nextElement = nextElement;
    this->value = value;
    this->previousElement = previousElement;
}

template<typename T>
BufferList<T>::ListIterator::ListIterator(BufferList::BidirectionalListElement *currentValue) {
    this->currentValue = currentValue;
}

template<typename T>
BufferList<T>::BufferList() : BufferList(DEFAULT_LIST_SIZE) {}

template<typename T>
BufferList<T>::~BufferList() {
    BidirectionalListElement *temp = bufferElement->nextElement;

    for (int i = 0; i < listSize; i++) {
        bufferElement->nextElement = temp->nextElement;
        delete temp;
        temp = bufferElement->nextElement;
    }

    delete temp;
}
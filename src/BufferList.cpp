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
void BufferList<T>::BufferListIterator::start() {
    iterator = bufferElement->nextElement;

    if (isFullIterated) {
        isFullIterated = false;
    }
}


template<typename T>
void BufferList<T>::BufferListIterator::next() {
    iterator->nextElement;

    if (iterator == bufferElement) {
        isFullIterated = true;
    }
}

template<typename T>
bool BufferList<T>::BufferListIterator::isFinish() const {
    return false;
}

template<typename T>
BufferList<T>::BufferListIterator::BufferListIterator(BufferList::BidirectionalListElement *iterator) {
    this->iterator = iterator;
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
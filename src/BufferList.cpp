#include "../headers/BufferList.h"

template<typename T>
BufferList<T>::BidirectionalListElement::BidirectionalListElement(const T value) {
    this->value = value;
}

template<typename T>
BufferList<T>::BidirectionalListElement::~BidirectionalListElement() {
    value = 0;

    nextElement = nullptr;
    previousElement = nullptr;

    delete nextElement;
    delete previousElement;
}

template<typename T>
BufferList<T>::BufferList() : BufferList(DEFAULT_SIZE) {}

template<typename T>
BufferList<T>::BufferList(const int size) {
    // FIXME Исправить конструктор BufferList
    this->listSize = size;
    BidirectionalListElement *temp = bufferElement;

    for (int i = 0; i < size; i++) {
        temp->nextElement = new BidirectionalListElement();
    }

    temp->nextElement = bufferElement;
    bufferElement->previousElement = temp;

    temp = nullptr;
    delete temp;
}

template<typename T>
void BufferList<T>::insert(const T value, const Iterator<List<T>> &iterator) {
    // TODO Реализовать метод insert
}

template<typename T>
void BufferList<T>::deleteElement(const Iterator<List<T>> &iterator) {
    // TODO Реализовать метод deleteElement
}

template<typename T>
Iterator<T> &BufferList<T>::firstEnter(const T value) {
    // TODO Реализовать метод firstEnter
    return nullptr;
}

template<typename T>
void BufferList<T>::clear() {
    // FIXME Исправить метод clear
    BidirectionalListElement *temp = bufferElement->nextElement;

    for (int i = 0; i < listSize; ++i) {
        temp->value = BidirectionalListElement::DEFAULT_VALUE;
    }

    temp = nullptr;
    delete temp;
}

template<typename T>
bool BufferList<T>::isEmpty() {
    return bufferElement->nextElement == nullptr;
}

template<typename T>
int BufferList<T>::size() {
    return listSize;
}

template<typename T>
Iterator<T> &BufferList<T>::begin() {
    // TODO Реализовать метод begin
    return nullptr;
}

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
#include "../headers/BufferList.h"

template<typename T>
BufferList<T>::BidirectionalListElement::BidirectionalListElement(const T value) : BidirectionalListElement(nullptr,
                                                                                                            value,
                                                                                                            nullptr) {}

template<typename T>
BufferList<T>::~BufferList() {
    clear();
    delete bufferElement;
}
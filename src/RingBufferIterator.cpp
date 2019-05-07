#include "../headers/RingBufferIterator.h"

RingBufferIterator::RingBufferIterator(RingBuffer *ringBufferForIteration) {
    this->ringBufferForIteration = ringBufferForIteration;
    iterator = ringBufferForIteration->getHead();
}

void RingBufferIterator::start() {
    if (iterator != ringBufferForIteration->getHead()) {
        iterator = ringBufferForIteration->getHead();
    }

    if (isFullIterated) {
        isFullIterated = false;
    }
}

void RingBufferIterator::next() {
    if (iterator == ringBufferForIteration->getTail()) {
        iterator = ringBufferForIteration->getHead();
        isFullIterated = true;
    } else {
        iterator++;
    }
}

bool RingBufferIterator::finish() {
    return isFullIterated;
}

int RingBufferIterator::getValue() {
    if (iterator->isEmpty) {
        throw 3;
    }

    return iterator->value;
}

bool RingBufferIterator::isEmpty() {
    return iterator->isEmpty;
}

RingBufferIterator::~RingBufferIterator() {
    ringBufferForIteration = nullptr;
    iterator = nullptr;
}
#include "../headers/RingBufferIterator.h"

RingBufferIterator::RingBufferIterator(RingBuffer &ringBufferForIteration) : ringBufferForIteration(
        ringBufferForIteration) {
    iterator = ringBufferForIteration.getHead();
}

void RingBufferIterator::start() {
    iterator = ringBufferForIteration.getHead();
}

void RingBufferIterator::next() {
    if (iterator == ringBufferForIteration.getTail()) {
        iterator = ringBufferForIteration.getHead();
        isFullIterated = true;
    } else {
        iterator++;
    }
}

bool RingBufferIterator::finish() {
    return isFullIterated;
}

int RingBufferIterator::getValue() {
    return iterator->value;
}
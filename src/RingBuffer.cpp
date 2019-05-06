#include "../headers/RingBuffer.h"

void RingBuffer::postIncrementIn() {
    if (in < bufferSize) {
        in++;
    } else {
        in = 0;
    }
}

void RingBuffer::postIncrementOut() {
    if (out < bufferSize) {
        out++;
    } else {
        out = 0;
    }
}

RingBuffer::RingBuffer(const size_t bufferSize) {
    this->bufferSize = bufferSize;

    buffer = new RingBufferElement[bufferSize];

    head = buffer;
    tail = head + bufferSize - 1;
}

void RingBuffer::pushBack(const int value) {
    if (bufferIsFull) {
        // TODO Сделать Exception для переполнения
    }

    if (bufferIsEmpty) {
        bufferIsEmpty = false;
    }

    buffer[in].isEmpty = false;
    buffer[in].value = value;

    postIncrementIn();
}

int RingBuffer::popFirst() {
    return 0;
}

int RingBuffer::getFirst() const {
    return 0;
}

void RingBuffer::clear() {
    if (bufferIsEmpty) {
        return;
    }

    if (bufferIsFull) {
        bufferIsFull = false;
    }

    bufferIsEmpty = true;
    in = 0;
    out = 0;

    for (int i = 0; i < bufferSize; i++) {
        buffer[i].isEmpty = false;
        buffer[i].value = 0;
    }
}

size_t RingBuffer::size() const {
    return bufferSize;
}

bool RingBuffer::isEmpty() const {
    return bufferIsEmpty;
}

bool RingBuffer::isFull() const {
    return bufferIsFull;
}

RingBuffer::~RingBuffer() {
    delete[]buffer;
}

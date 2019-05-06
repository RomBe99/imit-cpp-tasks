#ifndef CPP_TASKS_RINGBUFFERITERATOR_H
#define CPP_TASKS_RINGBUFFERITERATOR_H

#include "RingBuffer.h"

class RingBufferIterator {
private:
    RingBuffer &ringBufferForIteration;

    RingBuffer::RingBufferElement *iterator;

    bool isFullIterated = false;

public:
    explicit RingBufferIterator(RingBuffer &ringBufferForIteration);

    void start();

    void next();

    bool finish();

    int getValue();

    virtual ~RingBufferIterator() = default;
};

#endif
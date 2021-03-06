#ifndef CPP_TASKS_RINGBUFFER_H
#define CPP_TASKS_RINGBUFFER_H

#include <cstddef>

class RingBuffer {
public:
    struct RingBufferElement {
      bool isEmpty = true;
      int value = 0;
    };

private:
    RingBufferElement* buffer;
    std::size_t bufferSize;

    RingBufferElement* head;
    RingBufferElement* tail;

    bool bufferIsEmpty = true;
    bool bufferIsFull = false;

    unsigned int in = 0;
    unsigned int out = 0;

    void postIncrementIn();

    void postIncrementOut();

public:
    explicit RingBuffer(const size_t bufferSize);

    void pushBack(const int value);

    int popFirst();

    int getFirst() const;

    void clear();

    size_t size() const;

    bool isEmpty() const;

    bool isFull() const;

    RingBufferElement* getHead() const;

    RingBufferElement* getTail() const;

    ~RingBuffer();
};

#endif
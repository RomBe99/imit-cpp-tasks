#include <iostream>
#include "../headers/RingBuffer.h"
#include "../headers/RingBufferIterator.h"

int main() {
    const std::size_t BUFFER_SIZE = 5;

    auto *r = new RingBuffer(BUFFER_SIZE);
    auto *i = new RingBufferIterator(r);

    r->pushBack(22);
    r->pushBack(33);
    r->pushBack(44);
    r->pushBack(56);
    r->pushBack(77);

    while (!i->finish() && !i->isEmpty()) {
        std::cout << i->getValue() << ' ';
        i->next();
    }

    std::cout << std::endl;

    i->start();

    while (!i->finish() && !i->isEmpty()) {
        std::cout << i->getValue() << ' ';
        i->next();
    }

    i->start();

    std::cout << std::endl;

    std::cout << r->popFirst() << std::endl;
    std::cout << r->popFirst() << std::endl;

    i->next();
    i->next();

    while (!i->finish() && !i->isEmpty()) {
        std::cout << i->getValue() << ' ';
        i->next();
    }

    return 0;
}
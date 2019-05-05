#include <iostream>
#include "../headers/RingBuffer.h"

int main() {
    const std::size_t BUFFER_SIZE = 5;

    auto *r = new RingBuffer(BUFFER_SIZE);

    return 0;
}
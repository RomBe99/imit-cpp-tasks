#include <iostream>

#include "../headers/HashTable.h"

int main()
{
    auto ht = new HashTable();

    std::cout << std::endl << ht -> isEmpty() << std::endl;

    ht -> put(0, 55);

    try {
        ht -> put(0, 22);
    }
    catch (std::exception& e) {
        std::cout << std::endl << "Collusion" << std::endl;
    }

    ht -> put(1, 12);
    ht -> put(22, 87);
    ht -> put(3, 28);
    ht -> put(8, 44);
    ht -> put(5, 22);
    ht -> put(9, 64);

    auto hi = ht -> begin();

    for (int i = 0; !hi -> isFinish(); i++) {
        hi -> next();
        std::cout << i << std::endl;
    }

    hi -> start();

    ht -> deleteElement(22);
    ht -> deleteElement(5);

    while (!hi -> isFinish()) {
        hi -> next();
        std::cout << hi -> getValue() << std::endl;
    }

    std::cout << std::endl << ht -> isEmpty() << std::endl;

    ht -> clear();

    std::cout << std::endl << ht -> isEmpty() << std::endl;

    return 0;
}
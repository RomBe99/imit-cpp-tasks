#include <iostream>

#include "../headers/LinkedHashTable.h"

int main()
{
    auto ht = new LinkedHashTable();

    std::cout << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;

    ht -> put(0, 11);

    try {
        ht -> put(0, 55);
    }
    catch (exception& e) {
        std::cout << "Collision" << std::endl;
    }

    ht -> put(10, 99);
    ht -> put(1, 12);
    ht -> put(22, 87);
    ht -> put(3, 28);
    ht -> put(8, 44);
    ht -> put(5, 83);
    ht -> put(9, 64);

    auto hi = ht -> begin();

    std::cout << "Just listing";

    for (int i = 0; !hi . isFinish(); i++) {
        hi . next();
        std::cout << ' ' << i;
    }

    std::cout << std::endl;

    hi . start();

    ht -> deleteElement(22);
    ht -> deleteElement(5);

    std::cout << "Linked hash table elements:";
    while (!hi . isFinish()) {
        std::cout << ' ' << &hi;
        hi . next();
    }

    std::cout << std::endl << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;

    ht -> clear();

    std::cout << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;

    return 0;
}
#include <iostream>

#include "../headers/DynamicArrayInt.h"

void testDynamicArrayInt() {
    // Тест конструктора по умолчанию
    DynamicArrayInt defaultConstructor;

    // Тест конструктора по размеру
    const int SIZE1 = 4;
    DynamicArrayInt sizeConstructor(SIZE1);

    // Тест конструктора по размеру и числу
    const int SIZE2 = 10;
    const int NUMBER = 33;
    DynamicArrayInt sizeAndNumberConstructor(SIZE2, NUMBER);

    // Тест конструктора копирования и оператора присваивания
    DynamicArrayInt copyConstructor(sizeAndNumberConstructor);
    std::cout << &copyConstructor << "   " << &sizeAndNumberConstructor << std::endl;
    std::cout << copyConstructor << "   " << sizeAndNumberConstructor << std::endl;

    copyConstructor = defaultConstructor;
    std::cout << &copyConstructor << "   " << &defaultConstructor << std::endl;
    std::cout << copyConstructor << "   " << defaultConstructor << std::endl;

    // Тест конструктора перемещения и оператора перемещения
//    DynamicArrayInt moveConstructor = std::move(defaultConstructor);
//    std::cout << &moveConstructor << "   " << &defaultConstructor << std::endl; // Адреса объектов одинаковые, но вот далее
//    std::cout << moveConstructor << "   " << defaultConstructor << std::endl; // Выбросит сегфолт, так как пытаемся обратится к несуществующему объекту

    // Тест операций сравнения
//    std::cout << (defaultConstructor == copyConstructor) << std::endl;
//    std::cout << (defaultConstructor != copyConstructor) << std::endl;
//    std::cout << (defaultConstructor <= copyConstructor) << std::endl;
//    std::cout << (defaultConstructor >= copyConstructor) << std::endl;
//    std::cout << (sizeAndNumberConstructor > defaultConstructor) << std::endl;

    // Тест сложения массивов
    DynamicArrayInt arrSum = sizeAndNumberConstructor + defaultConstructor;
    std::cout << arrSum << std::endl;

    // Тест резерва
    const int NEW_SIZE = 15;
    arrSum.resize(NEW_SIZE);
    std::cout << arrSum << arrSum.capacity() << std::endl;
    arrSum.pushBack(NEW_SIZE);
    std::cout << arrSum << arrSum.capacity() << std::endl;
    std::cout << arrSum << arrSum.popBack() << ' ' << arrSum.capacity() << std::endl;
    std::cout << arrSum;
}

int main() {
    testDynamicArrayInt();
    return 0;
}
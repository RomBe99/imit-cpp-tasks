#include <iostream>

#include "../headers/BufferList.h"

int main()
{
    const size_t SIZE = 10;

    auto b = new BufferList<int>(SIZE);
    auto bi = b -> begin();

    // Тест итератора

    const int POSITION = 4;
    const int VALUE = 22;

    // Замена элемента

    for (int i = 1; !bi -> isFinish(); i++) {
        std::cout << i << std::endl;
        b -> setValue(i, *bi);
        bi -> next();
    }

    // Вставка элемента

    for (int i = 0; i < POSITION; i++) {
        bi -> next();
    }

    b -> insert(VALUE, *bi);

    bi -> start();

    // Тест поиска первого вхождения определённого значения и удаление элемента списка

    auto fe = b -> firstEnter(VALUE);

    b -> deleteElement(*fe);

    return 0;
}
#ifndef CPP_TASKS_ITERATOR_H
#define CPP_TASKS_ITERATOR_H

#include "List.h"

/**
 * Класс абстракного итератора.
 */
class Iterator {
public:
    /**
     * Метод для начала итерации структуры данных.
     */
    virtual void start() = 0;

    /**
     * Метод для смещения итератора на соедующую позицию.
     */
    virtual void next() = 0;

    /**
     * Метод для проверки окончани итерации по структуре данных.
     * @return true - если пройдёны все элементы структуры данных.
     */
    virtual bool isFinish() const = 0;
};

#endif
#ifndef CPP_TASKS_ITERATOR_H
#define CPP_TASKS_ITERATOR_H

#include "List.h"
#include "ListElement.h"

/**
 * Класс абстракного итератора.
 *
 * @tparam T любой примитивный тип данных.
 */
template<typename T>
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
     * Метод для проверки окончания итерации по структуре данных.
     *
     * @return true - если пройдёны все элементы структуры данных.
     */
    virtual bool isFinish() const = 0;

    /**
     * Получить значение элемента на который указывает итератор.
     *
     * @return значение элемента.
     */
    virtual const T getValue() const = 0;

    /**
     * Получить указатель на абстрактный класс элемента.
     *
     * @return Указатель на абстрактный класс элемента.
     */
    virtual ListElement<T> *getCurrentElement() = 0;
};

#endif
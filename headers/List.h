#ifndef CPP_TASKS_LIST_H
#define CPP_TASKS_LIST_H

#include "Iterator.h"
#include "ListElement.h"

/**
 * Абстрактный класс List для списков.
 *
 * @tparam T любой примитивный тип данных.
 */
template<typename T>
class List {
public:
    /**
     * Вставка нового значеня в позицию на которую указывает итератор.
     *
     * @param value значение для указанного элемента.
     * @param iterator итератор на элемент списка в который хотим вставить значение.
     */
    virtual void setValue(const T value, Iterator<T> &iterator) = 0;

    /**
     * Удаляет выбранный итератором элемент из списка.
     *
     * @param iterator Итератор на элемент для удаления.
     */
    virtual void deleteElement(Iterator<T> &iterator) = 0;

    /**
     * Находит первое вохождение значения в список.
     *
     * @param value Значение которое необходимо найти.
     * @return Указатель на итератор, который указывает на найденное значение.
     */
    virtual Iterator<T> *firstEnter(const T value) = 0;

    /**
     * Очистка списка.
     */
    virtual void clear() = 0;

    /**
     * Проверяет список на пустоту.
     *
     * @return Возвращает true - если пуст
     */
    virtual bool isEmpty() = 0;

    /**
     * Возращает размер списка.
     *
     * @return Размер списка.
     */
    virtual size_t size() = 0;

    /**
     * Позволяет получить итератор на первый элемент списка.
     *
     * @return Указатель на итератор указываеющего на первый элемент списка.
     */
    virtual Iterator<T> *begin() = 0;
};

#endif
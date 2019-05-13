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
     * Вставка нового элемента в любую часть списка.
     *
     * @param value значение для указанного элемента.
     * @param iterator итератор на элемент списка в который хотим вставить значение.
     */
    virtual void insert(const T value, const Iterator &iterator) = 0;

    /**
     * Удаляет выбранный итератором элемент из списка.
     *
     * @param iterator Итератор на элемент для удаления.
     */
    virtual void deleteElement(const Iterator &iterator) = 0;

    /**
     * Находит первое вохождение значения в список.
     *
     * @param value Значение которое необходимо найти.
     * @return Указатель на итератор, который указывает на найденное значение.
     */
    virtual Iterator *firstEnter(const T value) = 0;

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
    virtual Iterator *begin() = 0;
};

#endif
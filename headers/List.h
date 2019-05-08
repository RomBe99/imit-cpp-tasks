#ifndef CPP_TASKS_LIST_H
#define CPP_TASKS_LIST_H

#include "Iterator.h"

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
     * @param value значение нового элемента.
     * @param iterator позиция итератора для вставки нового элемента.
     */
    virtual void insert(const T value, const Iterator<List<T>> &iterator) = 0;

    /**
     * Удаляет выбранный итератором элемент.
     *
     * @param iterator выбранный итератором элемент.
     */
    virtual void deleteElement(const Iterator<List<T>> &iterator) = 0;

    /**
     * Находит первое вохождение значения в список.
     *
     * @param value Значение которое необходимо найти.
     * @return Ссылка на итератор, который указывает на найденное значение.
     */
    virtual Iterator<List<T>> &firstEnter(const T value) = 0;

    /**
     * Очистка списка.
     */
    virtual void clear() = 0;

    /**
     * Проверяет список на пустоту.
     *
     * @return Возвращает true - если пуст, false - в ином случае.
     */
    virtual bool isEmpty() = 0;

    /**
     * Возращает размер списка.
     *
     * @return Размер списка.
     */
    virtual int size() = 0;

    /**
     * Позволяет получить итератор на первый элемент.
     *
     * @return Итератор на первый элемент.
     */
    virtual Iterator<List<T>> &begin() = 0;
};

#endif
#ifndef CPP_TASKS_LISTELEMENT_H
#define CPP_TASKS_LISTELEMENT_H

/**
 * Абстрактный класс для элемента структуры данных.
 *
 * @tparam T любой примитивный тип данных, который будет хранить наследуемый класс.
 */
template<typename T>
class ListElement {
public:

    /**
     * Возвращает значение которое хранит элемент.
     *
     * @return значение которое хранит элемент.
     */
    virtual T getValue() const = 0;
};

#endif
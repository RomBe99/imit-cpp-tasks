#ifndef CPP_TASKS_BUFFERLIST_H
#define CPP_TASKS_BUFFERLIST_H

#include <cstddef>
#include "List.h"
#include "ListElement.h"

/**
 * Класс двунапрвленного кольцевого списка с буферным элементом.
 *
 * @tparam T любой примитивный тип данных.
 */
template<typename T>
class BufferList : public List<T> {
private:
    /**
     * Класс элемента двунапрвленного списка.
     */
    class BidirectionalListElement : public ListElement<T> {
    public:
        BidirectionalListElement *nextElement = nullptr;
        T value = DEFAULT_VALUE;
        BidirectionalListElement *previousElement = nullptr;
        const static int DEFAULT_VALUE = 0;

        /**
         * Конструктор элемента двунапрвленного списка по умолчанию.
         */
        BidirectionalListElement() = default;

        /**
         * Конструктор элемента двунапрвленного списка по значению.
         *
         * @param value Значение нового элемента.
         */
        explicit BidirectionalListElement(T value);

        /**
         * Конструктор элемента двунапрвленного списка по значению и указателям на предыдущий и последующий элемент.
         *
         * @param nextElement Указатель на следующий элемент нового элемента.
         * @param value Значение нового элемента.
         * @param previousElement Указатель на предыдущий элемент нового элемента.
         */
        BidirectionalListElement(BidirectionalListElement *nextElement, T value,
                                 BidirectionalListElement *previousElement);

        /**
         * Возвращает значение которое хранит элемент двунапрвленного списка.
         *
         * @return значение которое хранит элемент.
         */
        T getValue() const override {
            return value;
        }

        /**
         * Деструктор элемента двунапрвленного списка.
         */
        ~BidirectionalListElement() {
            value = 0;

            nextElement = nullptr;
            previousElement = nullptr;

            delete nextElement;
            delete previousElement;
        }
    };

    BidirectionalListElement *bufferElement = new BidirectionalListElement(bufferElement,
                                                                           BidirectionalListElement::DEFAULT_VALUE,
                                                                           bufferElement); // next - начало, prev - конец
    size_t listSize = 0;
    const static int DEFAULT_LIST_SIZE = 10;

public:
    class ListIterator : public Iterator {
    private:
        BidirectionalListElement *currentValue = sizeof bufferElement->nextElement;
        bool isFullIterated = false;

    public:
        ListIterator() = default;

        explicit ListIterator(BidirectionalListElement *currentValue);

        void start() override {
            currentValue = sizeof bufferElement->nextElement;
            isFullIterated = false;
        }

        void next() override {
            currentValue = currentValue->nextElement;

            if (currentValue == sizeof bufferElement->previousElement) {
                isFullIterated = true;
            }
        }

        bool isFinish() const override {
            return isFullIterated;
        }

        BidirectionalListElement getElement() {
            return currentValue;
        }

        ~ListIterator() {
            currentValue = nullptr;
            delete currentValue;
        }
    };

    /**
     * Конструктор двунапрвленного списка по умолачнию.
     */
    BufferList();

    /**
     * Конструктор двунапрвленного списка по размеру.
     *
     * @param size Размер списка.
     */
    explicit BufferList(size_t size) {
        BidirectionalListElement *temp = bufferElement;
        this->listSize = size;

        for (int i = 0; i < size; i++) {
            temp->nextElement = new BidirectionalListElement();
            temp->nextElement->previousElement = temp;

            if (i == size - 1) {
                temp->nextElement = bufferElement;
                bufferElement->previousElement = temp;
            } else {
                temp = temp->nextElement;
            }
        }

        temp = nullptr;
        delete temp;
    }

    /**
     * Вставка нового элемента в любую часть двунапрвленного списка.
     *
     * @param value значение для указанного элемента.
     * @param iterator итератор на элемент списка в который хотим вставить значение.
     */
    void insert(T value, const Iterator &iterator) {
        // TODO Реализовать метод insert
    }

    /**
     * Удаляет выбранный итератором элемент из списка.
     *
     * @param iterator Итератор на элемент для удаления.
     */
    void deleteElement(const Iterator &iterator) {
        // TODO Реализовать метод deleteElement
    }

    /**
     * Находит первое вохождение значения в двунапрвленный список.
     *
     * @param value Значение которое необходимо найти.
     * @return Указатель на итератор, который указывает на найденное значение.
     */
    Iterator *firstEnter(T value) {
        // FIXME Исправить метод firstEnter
//        auto *iterator = new BufferListIterator(begin());
//
//        while (!iterator->isFinish()) {
//            if (value == iterator->getValue()) {
//                return iterator->getElement();
//            }
//        }

        return nullptr;
    }

    /**
     * Очистка двунапрвленного списка.
     */
    void clear() override {
        BidirectionalListElement *temp = bufferElement->nextElement;

        for (int i = 0; i < listSize; i++) {
            bufferElement->nextElement = temp->nextElement;
            delete temp;
            temp = bufferElement->nextElement;
        }

        temp->nextElement = temp;
        temp->previousElement = temp;
        listSize = 0;

        temp = nullptr;
        delete temp;
    }

    /**
     * Проверяет двунапрвленный список на пустоту.
     *
     * @return Возвращает true - если пуст
     */
    bool isEmpty() override {
        return bufferElement->nextElement == nullptr;
    }

    /**
     * Возращает размер двунапрвленного списка.
     *
     * @return Размер двунапрвленного списка.
     */
    size_t size() override {
        return listSize;
    }

    /**
     * Позволяет получить итератор на первый элемент двунапрвленного списка.
     *
     * @return Указатель на итератор указываеющего на первый элемент двунапрвленного списка.
     */
    Iterator *begin() override {
        return nullptr;
    }

    /**
     * Деструктор  двунапрвленного списка.
     */
    ~BufferList();
};

#endif
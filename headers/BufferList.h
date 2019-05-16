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
                                 BidirectionalListElement *previousElement) {
            this->nextElement = nextElement;
            this->value = value;
            this->previousElement = previousElement;
        }

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
                                                                           bufferElement);
    size_t listSize = 0;
    const static int DEFAULT_LIST_SIZE = 10;

public:
    /**
     * Класс итератора для двунапрвленного кольцевого списка.
     */
    class ListIterator : public Iterator {
    private:
        BidirectionalListElement *currentElement = nullptr;
        BidirectionalListElement *listBuffer = nullptr;
        bool isFullIterated = false;

    public:
        /**
         * Конструктор итератора двунапрвленного кольцевого списка по буферному элементу
         * .
         * @param listBuffer указатель на буферный элемент двунапрвленного кольцевого списка.
         */
        explicit ListIterator(BidirectionalListElement *listBuffer) {
            this->currentElement = listBuffer->nextElement;
            this->listBuffer = listBuffer;
        }

        /**
         * Устанавливает итератор двунапрвленного кольцевого списка на стартовую позицию.
         */
        void start() override {
            currentElement = listBuffer->nextElement;
            isFullIterated = false;
        }

        /**
         * Перемещает итератор двунапрвленного кольцевого списка на следующую позицию.
         */
        void next() override {
            currentElement = currentElement->nextElement;

            if (currentElement == listBuffer->previousElement) {
                isFullIterated = true;
            }
        }

        /**
         * Метод для проверки окончания итерации двунапрвленного кольцевого списка.
         *
         * @return true - если пройдёны все элементы.
         */
        bool isFinish() const override {
            return isFullIterated;
        }

        /**
         * Получить значение элемента на который указывает итератор двунапрвленного кольцевого списка.
         *
         * @return значение элемента.
         */
        const T getValue() const {
            return currentElement->value;
        }

        /**
         * Деструктор итератора двунапрвленного кольцевого списка.
         */
        ~ListIterator() {
            currentElement = nullptr;
            listBuffer = nullptr;

            delete currentElement;
            delete listBuffer;
        }
    };

    /**
     * Конструктор двунапрвленного кольцевого списка по умолачнию.
     */
    BufferList();

    /**
     * Конструктор двунапрвленного кольцевого списка по размеру.
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
     * Вставка нового элемента в любую часть двунапрвленного кольцевого списка.
     *
     * @param value значение для указанного элемента.
     * @param iterator итератор на элемент списка в который хотим вставить значение.
     */
    void insert(T value, const Iterator &iterator) {
        // TODO Реализовать метод insert
    }

    /**
     * Удаляет выбранный итератором элемент из двунапрвленного кольцевого списка.
     *
     * @param iterator Итератор на элемент для удаления.
     */
    void deleteElement(Iterator &iterator) {
        // TODO Реализовать метод deleteElement
    }

    /**
     * Находит первое вохождение значения в двунапрвленном кольцевом списоке.
     *
     * @param value Значение которое необходимо найти.
     * @return Указатель на итератор, который указывает на найденное значение.
     */
    Iterator *firstEnter(T value) {
        auto iterator = new ListIterator(bufferElement);

        while (!iterator->isFinish()) {
            if (value == iterator->getValue()) {
                return iterator;
            }
        }

        return nullptr;
    }

    /**
     * Очистка двунапрвленного кольцевого списка.
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
     * Проверяет двунапрвленный кольцевой список на пустоту.
     *
     * @return Возвращает true - если пуст
     */
    bool isEmpty() override {
        return bufferElement->nextElement == nullptr;
    }

    /**
     * Возращает размер двунапрвленного кольцевого списка.
     *
     * @return Размер двунапрвленного списка.
     */
    size_t size() override {
        return listSize;
    }

    /**
     * Позволяет получить итератор на первый элемент двунапрвленного кольцевого списка.
     *
     * @return Указатель на итератор указываеющего на первый элемент двунапрвленного кольцевого списка.
     */
    Iterator *begin() override {
        return new ListIterator(bufferElement);
    }

    /**
     * Деструктор  двунапрвленного кольцевого списка.
     */
    ~BufferList();
};

#endif
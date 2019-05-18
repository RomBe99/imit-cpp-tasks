#ifndef CPP_TASKS_BUFFERLIST_H
#define CPP_TASKS_BUFFERLIST_H

#include <cstddef>
#include <cstdio>
#include <iostream>
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
        explicit BidirectionalListElement(T value) : BidirectionalListElement(nullptr, value, nullptr) {}

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

public:
    /**
     * Класс итератора для двунапрвленного кольцевого списка.
     */
    class ListIterator : public Iterator<T> {
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
        const T getValue() const override {
            return currentElement->value;
        }

        /**
         * Получить указатель на класс элемента двунапрвленного списка.
         *
         * @return Указатель на класс элемента двунапрвленного списка.
         */
        BidirectionalListElement *getCurrentElement() override {
            return currentElement;
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
    BufferList() = default;

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
     * Вставка нового значеня в позицию на которую указывает итератор.
     *
     * @param value значение для указанного элемента.
     * @param iterator итератор на элемент двунапрвленного кольцевого списка в который хотим вставить значение.
     */
    void setValue(const T value, Iterator<T> &iterator) override {
        auto temp = new ListIterator(bufferElement);

        while (temp->getCurrentElement() != iterator.getCurrentElement() || !temp->isFinish()) {
            temp->next();
        }

        temp->getCurrentElement()->value = value;
    }

    /**
     * Вставляет новый элемент в двунапрвленный кольцевой список после элемента на который указывает итератор.
     *
     * @param value значение новго элемента.
     * @param iterator итератор на элемент двунапрвленного кольцевого списка после которого хотим вставить новый элемент.
     */
    void insert(const T value, Iterator<T> &iterator) override {
        auto temp = new ListIterator(bufferElement);

        while (temp->getCurrentElement() != iterator.getCurrentElement() || !temp->isFinish()) {
            temp->next();
        }

        auto element = temp->getCurrentElement();
        element->nextElement = new BidirectionalListElement(element->nextElement, value, element->nextElement->previousElement);

        this->listSize += 1;
    }

    /**
     * Удаляет выбранный итератором элемент из двунапрвленного кольцевого списка.
     *
     * @param iterator Итератор на элемент для удаления.
     */
    void deleteElement(Iterator<T> &iterator) {
        if (this->listSize == 0) {
            throw std::exception();
        }

        auto temp = new ListIterator(bufferElement);

        while (temp->getCurrentElement() != iterator.getCurrentElement() || !temp->isFinish()) {
            temp->next();
        }

        auto element = temp->getCurrentElement();
        element->previousElement->nextElement = element->nextElement;
        element->nextElement->previousElement = element->previousElement;

        temp->next();
        this->listSize -= 1;
        delete element;
    }

    /**
     * Находит первое вохождение значения в двунапрвленном кольцевом списоке.
     *
     * @param value Значение которое необходимо найти.
     * @return Указатель на итератор, который указывает на найденное значение.
     */
    Iterator<T> *firstEnter(const T value) override {
        auto iterator = new ListIterator(bufferElement);

        while (!iterator->isFinish()) {
            iterator->next();

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
        return bufferElement->nextElement == bufferElement;
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
    Iterator<T> *begin() override {
        return new ListIterator(bufferElement);
    }

    /**
     * Деструктор  двунапрвленного кольцевого списка.
     */
    ~BufferList() {
        clear();
        delete bufferElement;
    }
};

#endif
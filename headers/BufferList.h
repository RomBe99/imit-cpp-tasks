#ifndef CPP_TASKS_BUFFERLIST_H
#define CPP_TASKS_BUFFERLIST_H

#include <cstddef>
#include "List.h"

/**
 * Класс двунапрвленного кольцевого списка с буферным элементом.
 *
 * @tparam T любой примитивный тип данных.
 */
template<typename T>
class BufferList : public List<T> {
private:

    /**
     * Класс элемента списка.
     */
    class BidirectionalListElement {
    public:
        BidirectionalListElement *nextElement = nullptr;
        T value = DEFAULT_VALUE;
        BidirectionalListElement *previousElement = nullptr;
        const static int DEFAULT_VALUE = 0;

        BidirectionalListElement() = default;

        explicit BidirectionalListElement(T value);

        ~BidirectionalListElement() {
            value = 0;

            nextElement = nullptr;
            previousElement = nullptr;

            delete nextElement;
            delete previousElement;
        }
    };

    BidirectionalListElement *bufferElement = new BidirectionalListElement(); // next - начало, prev - конец
    int listSize = 0;
    const static int DEFAULT_SIZE = 10;

public:

    class BufferListIterator : Iterator<BidirectionalListElement> {
    private:
        BidirectionalListElement *iterator = bufferElement->nextElement;

    public:
        BufferListIterator() = default;

        const BidirectionalListElement *getIterator() const {
            return iterator;
        }

        virtual ~BufferListIterator() = delete; // FIXME Виртуальный ли?
    };

    BufferList();

    explicit BufferList(int size) {
        // FIXME Исправить конструктор BufferList
        this->listSize = size;
        BidirectionalListElement *temp = bufferElement;

        for (int i = 0; i < size; i++) {
            temp->nextElement = new BidirectionalListElement();
        }

        temp->nextElement = bufferElement;
        bufferElement->previousElement = temp;

        temp = nullptr;
        delete temp;
    }

    void insert(T value, const Iterator<T> &iterator) {
        // TODO Реализовать метод insert
    }

    void deleteElement(const Iterator<T> &iterator) {
        // TODO Реализовать метод deleteElement
    }

//    Iterator<T> &firstEnter(T value) {
//        // TODO Приступить к реализации, после создания итератора
//        // TODO Реализовать метод firstEnter
//        return nullptr;
//    }

    void clear() {
        // FIXME Исправить метод clear
        BidirectionalListElement *temp = bufferElement->nextElement;

        for (int i = 0; i < listSize; ++i) {
            temp->value = BidirectionalListElement::DEFAULT_VALUE;
        }

        temp = nullptr;
        delete temp;
    }

    bool isEmpty() {
        return bufferElement->nextElement == nullptr;
    }

    int size() {
        return listSize;
    }

//    Iterator<T> &begin() {
//        // TODO Приступить к реализации, после создания итератора
//        // TODO Реализовать метод begin
//        return nullptr;
//    }

    ~BufferList();
};

#endif
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
     * Класс элемента списка.
     */
    class BidirectionalListElement : public ListElement<T> {
    public:
        BidirectionalListElement *nextElement = nullptr;
        T value = DEFAULT_VALUE;
        BidirectionalListElement *previousElement = nullptr;
        const static int DEFAULT_VALUE = 0;

        BidirectionalListElement() = default;

        explicit BidirectionalListElement(T value);

        BidirectionalListElement(BidirectionalListElement *nextElement, T value,
                                 BidirectionalListElement *previousElement);

        T getValue() const override {
            return value;
        }

        ~BidirectionalListElement() {
            value = 0;

            nextElement = nullptr;
            previousElement = nullptr;

            delete nextElement;
            delete previousElement;
        }
    };

    BidirectionalListElement *bufferElement = new BidirectionalListElement(); // next - начало, prev - конец
    size_t listSize = 0;
    const static int DEFAULT_LIST_SIZE = 10;

public:
    class BufferListIterator : public Iterator<BidirectionalListElement> {
    private:
        BidirectionalListElement *iterator = nullptr;
        bool isFullIterated = false;

    public:
        explicit BufferListIterator(BidirectionalListElement *iterator);

        void start() override;

        BidirectionalListElement *getElement() const override {
            return iterator;
        }

        T getValue() const {
            return iterator->getValue();
        }

        void next() override;

        bool isFinish() const override;

        ~BufferListIterator() {
            iterator = nullptr;
            delete iterator;
        }
    };

    BufferList();

    explicit BufferList(size_t size) {
        // FIXME Исправить конструктор BufferList
        BidirectionalListElement *temp = bufferElement;

        for (int i = 0; i < size; i++) {
            temp->nextElement = new BidirectionalListElement();
            temp->nextElement->previousElement = temp;

            if (i == size - 1) {
                temp = temp->nextElement;
            } else {
                temp->nextElement = bufferElement;
                bufferElement->previousElement = temp;
            }
        }

        temp = nullptr;
        delete temp;
    }

    void insert(T value, const Iterator<T> &iterator) {
        // TODO Реализовать метод insert
    }

    void deleteElement(const Iterator<T> &iterator) {
        // TODO Реализовать метод deleteElement
    }

    BidirectionalListElement *firstEnter(T value) {
        // FIXME Исправить метод firstEnter
        auto *iterator = new BufferListIterator(begin());

        while (!iterator->isFinish()) {
            if (value == iterator->getValue()) {
                return iterator->getElement();
            }
        }

        return nullptr;
    }

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

    size_t size() {
        return listSize;
    }

    BidirectionalListElement *begin() override {
        return bufferElement->nextElement;
    }

    ~BufferList();
};

#endif
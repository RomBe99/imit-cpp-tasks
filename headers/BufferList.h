#ifndef CPP_TASKS_BUFFERLIST_H
#define CPP_TASKS_BUFFERLIST_H

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
        T value = 0;
        BidirectionalListElement *previousElement = nullptr;

        BidirectionalListElement() = default;

        explicit BidirectionalListElement(T value);

        ~BidirectionalListElement();
    };

    BidirectionalListElement *bufferElement = new BidirectionalListElement(); // next - начало, prev - конец
    int listSize = 0;
    const static int DEFAULT_SIZE = 10;

public:
    BufferList();

    explicit BufferList(int size);

    void insert(T value, const Iterator<List<T>> &iterator) override;

    void deleteElement(const Iterator<List<T>> &iterator) override;

    Iterator<T> &firstEnter(T value) override;

    void clear() override;

    bool isEmpty() override;

    int size() override;

    Iterator<T> &begin() override;

    ~BufferList();
};

#endif
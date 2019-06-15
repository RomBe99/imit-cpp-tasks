#ifndef CPP_TASKS_LINKEDHASHTABLE_H
#define CPP_TASKS_LINKEDHASHTABLE_H

#include <vector>
#include <list>

using namespace std;

class LinkedHashTable {
private:
    struct HashElement {
      int key = 0;

      int value = 0;

      HashElement()
              :HashElement(-1, 0) {};

      HashElement(int key, int value);
    };

    struct IteratorsPair {
      size_t layerIterator;

      list<HashElement>::iterator positionIterator;

      IteratorsPair(size_t layerIterator,
              const list<LinkedHashTable::HashElement,
                         std::allocator<LinkedHashTable::HashElement>>::iterator& positionIterator);
    };

    size_t layersCount;

    vector<list<HashElement>> layers;

    list<IteratorsPair> iterators;

    const static size_t DEFAULT_SIZE = 10;

public:
    class HashTableIterator {
    private:
        LinkedHashTable& hashTableForIterate;

        list<IteratorsPair>::iterator iterator;

        bool isFullIterated = false;

    public:
        explicit HashTableIterator(LinkedHashTable& hashTableForIterate);

        void start();

        void next();

        bool isFinish() const;

        const int getValue() const;

        ~HashTableIterator() = default;
    };

    LinkedHashTable()
            :LinkedHashTable(DEFAULT_SIZE) {}

    explicit LinkedHashTable(size_t layersCount);

    void put(int key, int value);

    int deleteElement(int key);

    void clear();

    bool isEmpty() const;

    HashTableIterator begin();

    int intHashCode(int id) const;

    virtual ~LinkedHashTable() = default;
};

#endif
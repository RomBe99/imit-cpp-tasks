#ifndef CPP_TASKS_HASHTABLE_H
#define CPP_TASKS_HASHTABLE_H

#include <vector>

class HashTable {
private:
    struct HashElement {
      int key = 0;

      int value = 0;

      HashElement()
              :HashElement(-1, 0) {};

      HashElement(int key, int value);
    };

    size_t layersCount;

    std::vector<HashElement> layers;

    const static size_t DEFAULT_SIZE = 10;

public:
    class HashTableIterator {
    private:
        HashTable& hashTableForIterate;

        int currentLayer = 0;

        bool isFullIterated = false;

    public:
        explicit HashTableIterator(HashTable& hashTableForIterate);

        void start();

        void next();

        bool isFinish() const;

        const int getValue() const;

        ~HashTableIterator() = default;
    };

    HashTable()
            :HashTable(DEFAULT_SIZE) {}

    explicit HashTable(const size_t layersCount);

    void put(const int key, const int value);

    int deleteElement(const int key);

    void clear();

    bool isEmpty() const;

    HashTableIterator* begin();

    int intHashCode(const int id) const;

    virtual ~HashTable() = default;
};

#endif
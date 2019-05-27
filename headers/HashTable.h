#ifndef CPP_TASKS_HASHTABLE_H
#define CPP_TASKS_HASHTABLE_H

#include <vector>

class HashTable {
private:
    struct HashElement {
      int key = 0;
      int value = 0;

      HashElement(int key, int value);
    };

    size_t layersCount;
    std::vector<HashElement>* layers;
    const static size_t DEFAULT_SIZE = 10;

public:
    HashTable()
            :HashTable(DEFAULT_SIZE) {}

    explicit HashTable(const size_t layersCount);

    void put(const int key, const int value);

    int deleteElement(const int key);

    void clear();

    bool isEmpty() const;

    int intHashCode(const int id) const;

    ~HashTable();
};

#endif
#include "../headers/LinkedHashTable.h"

LinkedHashTable::HashElement::HashElement(int key, int value)
        :key(key), value(value) {}

LinkedHashTable::IteratorsPair::IteratorsPair(size_t layerIterator,
        const list<LinkedHashTable::HashElement,
                   std::allocator<LinkedHashTable::HashElement>>::iterator& positionIterator)
        :layerIterator(layerIterator), positionIterator(positionIterator) {}

LinkedHashTable::LinkedHashTable(const size_t layersCount)
{
    this -> layersCount = layersCount;
    layers = vector<list<HashElement>>(layersCount);

    for (int i = 0; i < layersCount; i++) {
        layers[i] = list<HashElement>();
    }
}

void LinkedHashTable::put(const int key, const int value)
{
    const int KEY_HASH_CODE = intHashCode(key);

    for (auto i : layers[KEY_HASH_CODE]) {
        if (i . key == key) {
            throw exception();
        }
    }

    layers[KEY_HASH_CODE] . push_back(HashElement(key, value));
    IteratorsPair temp(KEY_HASH_CODE, --layers[KEY_HASH_CODE] . end());
    iterators . push_back(temp);
}

int LinkedHashTable::deleteElement(const int key)
{
    int value;

    for (auto i = iterators . begin(); i != iterators . end(); ++i) {
        if (i -> positionIterator -> key == key) {
            value = i -> positionIterator -> value;
            iterators . erase(i);

            return value;
        }
    }

    throw exception();
}

void LinkedHashTable::clear()
{
    for (int i = 0; i < layersCount; i++) {
        layers . clear();
    }

    iterators . clear();
}

bool LinkedHashTable::isEmpty() const
{
    for (const auto& layer : layers) {
        if (!layer . empty()) {
            return false;
        }
    }

    return true;
}

LinkedHashTable::HashTableIterator LinkedHashTable::begin()
{
    return HashTableIterator(*this);
}

int LinkedHashTable::intHashCode(const int id) const
{
    return id % layersCount;
}

LinkedHashTable::HashTableIterator::HashTableIterator(LinkedHashTable& hashTableForIterate)
        :hashTableForIterate(hashTableForIterate)
{
    iterator = hashTableForIterate . iterators . begin();
}

void LinkedHashTable::HashTableIterator::start()
{
    isFullIterated = false;
    iterator = hashTableForIterate . iterators . begin();
}

void LinkedHashTable::HashTableIterator::next()
{
    if (isFullIterated) {
        return;
    }

    ++iterator;

    if (iterator == hashTableForIterate . iterators . end()) {
        isFullIterated = true;
    }
}

bool LinkedHashTable::HashTableIterator::isFinish() const
{
    return isFullIterated;
}

const int LinkedHashTable::HashTableIterator::getValue() const
{
    return iterator -> positionIterator -> value;
}
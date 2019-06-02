#include "../headers/HashTable.h"

HashTable::HashElement::HashElement(int key, int value)
        :key(key), value(value) {}

HashTable::HashTable(const size_t layersCount)
{
    this -> layersCount = layersCount;
    layers = std::vector<HashElement>(layersCount);
}

void HashTable::put(const int key, const int value)
{
    const int KEY_HASH_CODE = intHashCode(key);

    for (HashElement he : layers) {
        if (he . key == KEY_HASH_CODE) {
            throw std::exception();
        }
    }

    auto newElement = HashElement(KEY_HASH_CODE, value);

    layers[KEY_HASH_CODE] = newElement;
}

int HashTable::deleteElement(const int key)
{
    const int KEY_HASH_CODE = intHashCode(key);
    int value;

    for (int i = 0; i < layersCount; i++) {
        if (layers[i] . key == KEY_HASH_CODE) {
            value = layers[i] . value;
            layers[i] = HashElement();

            return value;
        }
    }

    return 0;
}

void HashTable::clear()
{
    for (int i = 0; i < layersCount; i++) {
        layers . clear();
    }
}

bool HashTable::isEmpty() const
{
    for (int i = 0; i < layersCount; i++) {
        if (!layers . empty()) {
            return false;
        }
    }

    return true;
}

HashTable::HashTableIterator* HashTable::begin()
{
    return new HashTableIterator(*this);
}

int HashTable::intHashCode(const int id) const
{
    return id % layersCount;
}

HashTable::HashTableIterator::HashTableIterator(HashTable& hashTableForIterate)
        :hashTableForIterate(hashTableForIterate) {}

void HashTable::HashTableIterator::start()
{
    isFullIterated = false;
    currentLayer = 0;
}

void HashTable::HashTableIterator::next()
{
    if (isFullIterated) {
        return;
    }

    if (currentLayer + 1 < hashTableForIterate . layersCount) {
        currentLayer ++;
    }
    else {
        currentLayer = 0;
        isFullIterated = true;
    }
}

bool HashTable::HashTableIterator::isFinish() const
{
    return isFullIterated;
}

const int HashTable::HashTableIterator::getValue() const
{
    return hashTableForIterate . layers . at(currentLayer) . value;
}
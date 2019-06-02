#include "../headers/HashTable.h"

HashTable::HashElement::HashElement(int key, int value)
        :key(key), value(value) {}

HashTable::HashTable(const size_t layersCount)
{
    this -> layersCount = layersCount;
    layers = std::vector<std::vector<HashElement>>(layersCount);
}

void HashTable::put(const int key, const int value)
{
    const int KEY_HASH_CODE = intHashCode(key);

    for (HashElement he : layers[KEY_HASH_CODE]) {
        if (he . key == KEY_HASH_CODE) {
            throw std::exception();
        }
    }

    auto newElement = HashElement(KEY_HASH_CODE, value);

    layers[KEY_HASH_CODE] . push_back(newElement);
}

int HashTable::deleteElement(const int key)
{
    const int KEY_HASH_CODE = intHashCode(key);
    int value;
    auto iter = layers[KEY_HASH_CODE] . begin();

    for (HashElement he : layers[KEY_HASH_CODE]) {
        if (he . key == KEY_HASH_CODE) {
            value = he . value;
            layers[KEY_HASH_CODE] . erase(iter);
            return value;
        }

        iter++;
    }

    return 0;
}

void HashTable::clear()
{
    for (int i = 0; i < layersCount; i++) {
        layers[i] . clear();
    }
}

bool HashTable::isEmpty() const
{
    for (int i = 0; i < layersCount; i++) {
        if (!layers[i] . empty()) {
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

HashTable::~HashTable()
{
    delete layers;
}

HashTable::HashTableIterator::HashTableIterator(HashTable& hashTableForIterate)
        :hashTableForIterate(hashTableForIterate) {}

void HashTable::HashTableIterator::start()
{
    isFullIterated = false;
    currentLayer = 0;
    currentPosition = 0;
}

void HashTable::HashTableIterator::next()
{
    if (currentPosition + 1 < hashTableForIterate . layers[currentLayer] . size()) {
        currentPosition++;
    }
    else {
        currentPosition = 0;
        currentLayer = currentLayer + 1 < hashTableForIterate . layersCount ? currentLayer + 1 : 0;
    }
}

bool HashTable::HashTableIterator::isFinish() const
{
    return isFullIterated;
}

const int HashTable::HashTableIterator::getValue() const
{
    return hashTableForIterate . layers[currentLayer] . at(currentPosition) . value;
}
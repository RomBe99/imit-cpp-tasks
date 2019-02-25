#include "../headers/Container.h"

Container::Container(const int length, const int width, const int height, const int maxWeight) {
    setLength(length);
    setWidth(width);
    setHeight(height);
    setMaxWeight(maxWeight);

    currentWeight = 0;
}

const vector<Box> &Container::getContainer() const {
    return container;
}

void Container::setLength(int length) {
    Container::length = length;
}

void Container::setWidth(int width) {
    Container::width = width;
}

void Container::setHeight(int height) {
    Container::height = height;
}

void Container::setMaxWeight(int maxWeight) {
    Container::maxWeight = maxWeight;
}

void Container::setCurrentWeight(int currentWeight) {
    Container::currentWeight = currentWeight;
}

int Container::getLength() const {
    return length;
}

int Container::getWidth() const {
    return width;
}

int Container::getHeight() const {
    return height;
}

int Container::getMaxWeight() const {
    return maxWeight;
}

int Container::getCurrentWeight() const {
    return currentWeight;
}

unsigned long Container::boxesNumber() {
    return container.size();
}

Box Container::getBox(unsigned long index) {
    return container.at(index);
}

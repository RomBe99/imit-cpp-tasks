#include "../headers/Container.h"

Container::Container(const int length, const int width, const int height, const double maxWeight) {
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

void Container::setMaxWeight(const double maxWeight) {
    Container::maxWeight = maxWeight;
}

void Container::setCurrentWeight(const double currentWeight) {
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

double Container::getMaxWeight() const {
    return maxWeight;
}

double Container::getCurrentWeight() const {
    return currentWeight;
}

unsigned long Container::boxesNumber() {
    return container.size();
}

Box Container::getBox(unsigned long index) {
    return container.at(index);
}

void Container::setCurrentValue(double currentValue) {
    Container::currentValue = currentValue;
}

void Container::deleteBox(const unsigned long index) {
    container.erase(container.begin() + index);
}

Box Container::operator[](const unsigned int index) {
    return this->getBox(index);
}

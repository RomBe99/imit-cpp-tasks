#include "../headers/Box.h"

Box::Box() : Box(0, 0, 0, 0, 0) {}

Box::Box(int length, int width, int height, double weight, double value) : length(length), width(width), height(height),
                                                                        weight(weight), value(value) {}

void Box::setLength(const int length) {
    Box::length = length;
}

void Box::setWidth(const int width) {
    Box::width = width;
}

void Box::setHeight(const int height) {
    Box::height = height;
}

void Box::setWeight(const double weight) {
    Box::weight = weight;
}

void Box::setValue(const double value) {
    Box::value = value;
}

int Box::getLength() const {
    return length;
}

int Box::getWidth() const {
    return width;
}

int Box::getHeight() const {
    return height;
}

double Box::getWeight() const {
    return weight;
}

double Box::getValue() const {
    return value;
}

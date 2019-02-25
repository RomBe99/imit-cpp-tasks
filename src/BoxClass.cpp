#include "../headers/BoxClass.h"

BoxClass::Box::Box() : Box(0, 0, 0, 0, 0) {}

BoxClass::Box::Box(int length, int width, int height, double weight, double value) : length(length), width(width), height(height),
                                                                           weight(weight), value(value) {}

void BoxClass::Box::setLength(const int length) {
    BoxClass::Box::length = length;
}

void BoxClass::Box::setWidth(const int width) {
    BoxClass::Box::width = width;
}

void BoxClass::Box::setHeight(const int height) {
    BoxClass::Box::height = height;
}

void BoxClass::Box::setWeight(const double weight) {
    BoxClass::Box::weight = weight;
}

void BoxClass::Box::setValue(const double value) {
    BoxClass::Box::value = value;
}

int BoxClass::Box::getLength() const {
    return length;
}

int BoxClass::Box::getWidth() const {
    return width;
}

int BoxClass::Box::getHeight() const {
    return height;
}

double BoxClass::Box::getWeight() const {
    return weight;
}

double BoxClass::Box::getValue() const {
    return value;
}
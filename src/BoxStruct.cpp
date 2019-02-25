#include "../headers/BoxStruct.h"

Box::Box() : Box(0, 0, 0, 0, 0) {}

Box::Box(const int newLength, const int newWidth, const int newHeight, const double newWeight, const int newValue)
        : length(newLength),
          width(newWidth),
          height(newHeight),
          weight(newWeight),
          value(newValue) {}

bool Box::operator==(const Box& firstBox) {
    if (this == &firstBox) {
        return true;
    }

    return this->value == firstBox.value && this->weight == firstBox.weight && this->width == firstBox.width &&
           this->height == firstBox.height && this->length == firstBox.length;
}
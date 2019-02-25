#include "../headers/BoxStruct.h"

Box::Box() : Box(0, 0, 0, 0, 0) {}

Box::Box(const int newLength, const int newWidth, const int newHeight, const double newWeight, const int newValue)
        : length(newLength),
          width(newWidth),
          height(newHeight),
          weight(newWeight),
          value(newValue) {}

bool Box::operator==(const Box firstBox, const Box secondBox) {
    return firstBox.length == secondBox.length && firstBox.height == secondBox.height && firstBox.width == secondBox.width &&
           firstBox.weight == secondBox.weight && firstBox.value == secondBox.value;
}
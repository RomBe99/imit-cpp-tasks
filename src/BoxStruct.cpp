#include "../headers/BoxStruct.h"

BoxStruct::Box::Box()
        :Box(0, 0, 0, 0, 0) {}

BoxStruct::Box::Box(const int newLength, const int newWidth, const int newHeight, const double newWeight,
        const double newValue)
        :length(newLength),
         width(newWidth),
         height(newHeight),
         weight(newWeight),
         value(newValue) {}

bool BoxStruct::operator==(const Box& firstBox, const Box& secondBox)
{
    if (firstBox == secondBox) {
        return true;
    }

    return firstBox . value == secondBox . value && firstBox . weight == secondBox . weight &&
            firstBox . height == secondBox . height && firstBox . width == secondBox . width &&
            firstBox . length == secondBox . length;
}

std::istream& BoxStruct::operator>>(std::istream& in, Box& box)
{
    in >> box . length;
    in >> box . width;
    in >> box . height;
    in >> box . weight;
    in >> box . value;

    return in;
}

std::ostream& BoxStruct::operator<<(std::ostream& out, const Box& box)
{
    out << "Length: " << box . length << '\n' << "Width: " << box . width << '\n' << "Height: " << box . height << '\n'
        << "Weight: " <<
        box . weight << '\n' << "Value: " << box . value << '\n';

    return out;
}

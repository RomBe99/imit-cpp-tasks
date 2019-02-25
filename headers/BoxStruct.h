#ifndef CPP_TASKS_BOXSTRUCT_H
#define CPP_TASKS_BOXSTRUCT_H

#include <iostream>

struct Box {
    int length;
    int width;
    int height;
    double weight; // kg
    int value; // cop

    Box();

    Box(const int newLength, const int newWidth, const int newHeight, const double newWeight, const int newValue);

    friend bool operator==(const Box& firstBox, const Box& secondBox);

    friend std::istream& operator>>(std::istream& in, Box& box);

    friend std::ostream& operator>>(std::ostream& out, const Box& box);
};

#endif

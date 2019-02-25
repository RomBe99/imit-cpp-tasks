#ifndef CPP_TASKS_BOXSTRUCT_H
#define CPP_TASKS_BOXSTRUCT_H

struct Box {
    int length;
    int width;
    int height;
    double weight; // kg
    int value; // cop
    Box();

    Box(const int newLength, const int newWidth, const int newHeight, const double newWeight, const int newValue);

    bool operator==(const Box& firstBox);
};

#endif

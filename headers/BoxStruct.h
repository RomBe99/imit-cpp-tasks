#ifndef CPP_TASKS_BOXSTRUCT_H
#define CPP_TASKS_BOXSTRUCT_H

struct Box {
    int length;
    int width;
    int height;
    double weight; // kg
    int value; // cop
    Box(int newLength, int newWidth, int newHeight, double newWeight, int newValue);
};

#endif

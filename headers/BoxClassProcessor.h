#ifndef CPP_TASKS_BOXCLASSPROCESSOR_H
#define CPP_TASKS_BOXCLASSPROCESSOR_H

#include "../headers/BoxClass.h"

using namespace BoxClass;

class BoxClassProcessor {
    double boxPrice(const int arrSize, const Box boxes[]);

    bool isSizeAllBoxesSmaller(const int arrSize, const Box boxes[], int maxP);

    double maxWeightSmallerMaxW(const int arrSize, const Box *boxes, const double maxV);

    bool isAllBox(const int arrSize, Box boxes[]);

    int calculateVolume(const Box box);
};

#endif
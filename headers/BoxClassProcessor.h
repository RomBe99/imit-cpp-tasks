#ifndef CPP_TASKS_BOXCLASSPROCESSOR_H
#define CPP_TASKS_BOXCLASSPROCESSOR_H

#include "../headers/BoxClass.h"

using namespace BoxClass;

class BoxClassProcessor {
public:
    static double boxPrice(const int arrSize, Box* boxes);

    static bool isSizeAllBoxesSmaller(const int arrSize, const Box* boxes, int maxP);

    static double maxWeightSmallerMaxW(const int arrSize, const Box* boxes, const double maxV);

    static bool isAllBox(const int arrSize, Box* boxes);

    static int calculateVolume(const Box box);
};

#endif
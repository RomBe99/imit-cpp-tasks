#ifndef CPP_TASKS_BOXSTRUCTPROCESSOR_H
#define CPP_TASKS_BOXSTRUCTPROCESSOR_H

#include "BoxStruct.h"

namespace BoxStructProcessor {
    double boxPrice(const int arrSize, const BoxStruct::Box boxes[]);

    bool isSizeAllBoxesSmaller(const int arrSize, const BoxStruct::Box boxes[], int maxP);

    double maxWeightSmallerMaxW(const int arrSize, const BoxStruct::Box *boxes, const double maxV);

    bool isAllBox(const int arrSize, BoxStruct::Box boxes[]);

    int calculateVolume(const BoxStruct::Box box);
}

#endif

#ifndef CPP_TASKS_BOXSTRUCTPROCESSOR_H
#define CPP_TASKS_BOXSTRUCTPROCESSOR_H

#include "BoxStruct.h"

namespace BoxStructProcessor {
    int boxPrice(const int arrSize, const Box boxes[]);

    bool isSizeAllBoxesSmaller(const int arrSize, const Box boxes[], int maxP);

    double maxWeightSmallerMaxW(const int arrSize, const Box *boxes, const double maxV);

    bool isAllBox(const int arrSize, Box boxes[]);

    int calculateVolume(const Box box);
}

#endif

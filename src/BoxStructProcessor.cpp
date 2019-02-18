#include "../headers/BoxStructProcessor.h"

int BoxStructProcessor::boxPrice(const int arrSize, const Box *boxes) {
    int price = 0;

    for (int i = 0; i < arrSize; i++) {
        price += boxes[i].value;
    }

    return price;
}

bool BoxStructProcessor::isSizeAllBoxesSmaller(const int arrSize, const Box *boxes, int maxP) {
    for (int i = 0; i < arrSize; i++) {
        if (boxes[i].width + boxes[i].height + boxes[i].length > maxP) {
            return false;
        }
    }

    return true;
}

double BoxStructProcessor::maxWeightSmallerMaxW(const int arrSize, const Box *boxes, const double maxV) {
    int volume = 0;
    int temp;

    for (int i = 0; i < arrSize; ++i) {
        temp = boxes[i].width * boxes[i].height * boxes[i].length;

        if (temp < maxV) {
            volume += temp;
        }
    }

    return volume;
}
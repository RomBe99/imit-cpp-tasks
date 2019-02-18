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

bool BoxStructProcessor::isAllBox(const int arrSize, Box *boxes) {
    Box temp;

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize - 1; j++) {
            if (calculateVolume(boxes[j]) >= calculateVolume(boxes[j + 1])) {
                temp = boxes[j];
                boxes[j] = boxes[j + 1];
                boxes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < arrSize - 1; ++i) {
        if (boxes[i].height <= boxes[i + 1].height || boxes[i].width <= boxes[i + 1].width ||
            boxes[i].length <= boxes[i + 1].length) {
            return false;
        }
    }

    return true;
}

int BoxStructProcessor::calculateVolume(const Box box) {
    return box.length * box.height * box.width;
}
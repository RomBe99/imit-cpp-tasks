#include "../headers/BoxClassProcessor.h"

double BoxClassProcessor::boxPrice(const int arrSize, Box *boxes) {
    double price = 0;

    for (int i = 0; i < arrSize; i++) {
        price += boxes[i].getValue();
    }

    return price;
}

bool BoxClassProcessor::isSizeAllBoxesSmaller(const int arrSize, const BoxClass::Box *boxes, int maxP) {
    for (int i = 0; i < arrSize; i++) {
        if (boxes[i].getWidth() + boxes[i].getHeight() + boxes[i].getLength() > maxP) {
            return false;
        }
    }

    return true;
}

double BoxClassProcessor::maxWeightSmallerMaxW(const int arrSize, const BoxClass::Box *boxes, const double maxV) {
    int volume = 0;
    int temp;

    for (int i = 0; i < arrSize; i++) {
        temp = boxes[i].getWidth() * boxes[i].getHeight() * boxes[i].getLength();

        if (temp < maxV) {
            volume += temp;
        }
    }

    return volume;
}

bool BoxClassProcessor::isAllBox(const int arrSize, BoxClass::Box *boxes) {
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

    for (int i = 0; i < arrSize - 1; i++) {
        if (boxes[i].getHeight() <= boxes[i + 1].getHeight() || boxes[i].getWidth() <= boxes[i + 1].getWidth() ||
            boxes[i].getLength() <= boxes[i + 1].getLength()) {
            return false;
        }
    }

    return true;
}

int BoxClassProcessor::calculateVolume(const Box box) {
    return box.getLength() * box.getHeight() * box.getWidth();
}

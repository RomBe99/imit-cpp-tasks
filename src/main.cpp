#include "../headers/BoxClass.h"
#include "../headers/BoxClassProcessor.h"
#include <iostream>

int main() {
    const int ARRAY_SIZE = 5;
    const int MAX_P = 1;
    const int MAX_V = 20;

    Box *box1 = new Box(1, 1, 1, 1, 1);
    Box *box2 = new Box(2, 2, 2, 2, 2);
    Box *box3 = new Box(3, 3, 3, 3, 3);
    Box *box4 = new Box(4, 4, 4, 4, 4);
    Box *box5 = new Box(5, 5, 5, 5, 5);
    Box *boxArr = new Box[ARRAY_SIZE];

    boxArr[0] = *box1;
    boxArr[1] = *box2;
    boxArr[2] = *box3;
    boxArr[3] = *box4;
    boxArr[4] = *box5;

//    std::cout << BoxClassProcessor::boxPrice(ARRAY_SIZE, boxArr);
//    std::cout << BoxClassProcessor::isSizeAllBoxesSmaller(ARRAY_SIZE, boxArr, MAX_P);
    std::cout << BoxClassProcessor::maxWeightSmallerMaxW(ARRAY_SIZE, boxArr, MAX_V);
//    std::cout << BoxClassProcessor::isAllBox(ARRAY_SIZE, boxArr);
}
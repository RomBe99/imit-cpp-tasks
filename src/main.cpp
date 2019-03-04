#include "../headers/BoxClass.h"
#include "../headers/BoxClassProcessor.h"
#import <iostream>

int main() {
    Box *box1 = new Box(1, 1, 1, 1, 1);
    Box *box2 = new Box(2, 2, 2, 2, 2);
    Box *box3 = new Box(3, 3, 3, 3, 3);
    Box *box4 = new Box(4, 4, 4, 4, 4);
    Box *box5 = new Box(5, 5, 5, 5, 5);
    Box *boxArr = new Box[5];
    boxArr[0] = *box1;
    boxArr[1] = *box2;
    boxArr[2] = *box3;
    boxArr[3] = *box4;
    boxArr[4] = *box5;
    std::cout << BoxClassProcessor::isAllBox(5, boxArr);
}
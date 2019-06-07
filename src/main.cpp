#include <iostream>

#include "../headers/BinaryTree.h"

int main()
{
    auto bt = new BinaryTree(5);

    const int SIZE_ELEM1 = 1;
    int elem1[] = {0};

    const int SIZE_ELEM3 = 2;
    int elem3[] = {0, 0};

    const int SIZE_ELEM4 = 2;
    int elem4[] = {0, 1};

    const int SIZE_ELEM5 = 2;
    int elem5[] = {1, 0};

    const int SIZE_ELEM7 = 2;
    int elem7[] = {1, 0};

    const int SIZE_ELEM9 = 3;
    int elem9[] = {1, 0, 0};

    const int SIZE_ELEM8 = 2;
    int elem8[] = {1, 1};

    const int SIZE_ELEM2 = 3;
    int elem2[] = {1, 1, 0};

    const int SIZE_ELEM11 = 3;
    int elem11[] = {1, 1, 1};

    const int SIZE_ELEM12 = 4;
    int elem12[] = {1, 1, 1, 0};

    bt -> insert(1, SIZE_ELEM1, elem1);
    bt -> insert(3, SIZE_ELEM3, elem3);
    bt -> insert(4, SIZE_ELEM4, elem4);
    bt -> insert(5, SIZE_ELEM5, elem5);
    bt -> insert(7, SIZE_ELEM7, elem7);
    bt -> insert(9, SIZE_ELEM9, elem9);
    bt -> insert(8, SIZE_ELEM8, elem8);
    bt -> insert(2, SIZE_ELEM2, elem2);
    bt -> insert(11, SIZE_ELEM11, elem11);
    bt -> insert(12, SIZE_ELEM12, elem12);

    bt -> print();

    std::cout << "Tree contains only positive numbers? " << bt -> isPositive() << std::endl;
    std::cout << "Tree average = " << bt -> average() << std::endl;
    std::cout << "Is binary search tree? " << bt -> isBinarySearchTree() << std::endl;

    bt -> deleteAllLeafs();

    bt -> print();

    return 0;
}
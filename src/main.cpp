#include <iostream>
#include <vector>

#include "../headers/BinaryTree.h"

int main()
{
    auto bt = new BinaryTree(10);

    const int SIZE_ELEM9 = 1;
    const int ELEM9[] = {0};

    const int SIZE_ELEM_MINUS20 = 2;
    const int ELEM_MINUS20[] = {0, 0};

    const int SIZE_ELEM_MINUS7 = 2;
    const int ELEM_MINUS7[] = {0, 1};

    const int SIZE_ELEM20 = 2;
    const int ELEM20[] = {1, 0};

    const int SIZE_ELEM11 = 2;
    const int ELEM11[] = {1, 0};

    const int SIZE_ELEM88 = 3;
    const int ELEM88[] = {1, 0, 0};

    const int SIZE_ELEM30 = 2;
    const int ELEM30[] = {1, 1};

    const int SIZE_ELEM77 = 3;
    const int ELEM77[] = {1, 1, 0};

    const int SIZE_ELEM41 = 3;
    const int ELEM41[] = {1, 1, 1};

    const int SIZE_ELEM_MINUS1 = 4;
    const int MINUS1[] = {1, 1, 1, 0};

    bt -> insert(9, SIZE_ELEM9, ELEM9);
    bt -> insert(-20, SIZE_ELEM_MINUS20, ELEM_MINUS20);
    bt -> insert(-7, SIZE_ELEM_MINUS7, ELEM_MINUS7);
    bt -> insert(20, SIZE_ELEM20, ELEM20);
    bt -> insert(11, SIZE_ELEM11, ELEM11);
    bt -> insert(88, SIZE_ELEM88, ELEM88);
    bt -> insert(30, SIZE_ELEM30, ELEM30);
    bt -> insert(77, SIZE_ELEM77, ELEM77);
    bt -> insert(41, SIZE_ELEM41, ELEM41);
    bt -> insert(-1, SIZE_ELEM_MINUS1, MINUS1);

    bt -> print();

    std::cout << "Tree contains only positive numbers? " << bt -> isPositive() << std::endl;
    std::cout << "Tree average = " << bt -> average() << std::endl;
    std::cout << "Is binary search tree? " << bt -> isBinarySearchTree() << std::endl;
    std::cout << "Number of even numbers = " << bt -> numberOfEvenNumbers() << std::endl;

    bt -> deleteAllLeafs();

    bt -> print();

    std::cout << "Tree contains only positive numbers? " << bt -> isPositive() << std::endl;
    std::cout << "Tree average = " << bt -> average() << std::endl;
    std::cout << "Is binary search tree? " << bt -> isBinarySearchTree() << std::endl;
    std::cout << "Number of even numbers = " << bt -> numberOfEvenNumbers() << std::endl;

    for (int i : *bt -> findRoute(11)) {
        std::cout << i << ' ';
    }

    return 0;
}
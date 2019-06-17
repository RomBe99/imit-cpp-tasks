#include <iostream>

#include "../headers/LinkedHashTable.h"
#include "../headers/BinaryWordTree.h"

int main()
{
//    auto ht = new LinkedHashTable();
//
//    std::cout << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;
//
//    ht -> put(0, 11);
//
//    try {
//        ht -> put(0, 55);
//    }
//    catch (exception& e) {
//        std::cout << "Collision" << std::endl;
//    }
//
//    ht -> put(10, 99);
//    ht -> put(1, 12);
//    ht -> put(22, 87);
//    ht -> put(3, 28);
//    ht -> put(8, 44);
//    ht -> put(5, 83);
//    ht -> put(9, 64);
//
//    auto hi = ht -> begin();
//
//    std::cout << "Just listing";
//
//    for (int i = 0; !hi . isFinish(); i++) {
//        hi . next();
//        std::cout << ' ' << i;
//    }
//
//    std::cout << std::endl;
//
//    hi . start();
//
//    ht -> deleteElement(22);
//    ht -> deleteElement(5);
//
//    std::cout << "Linked hash table elements:";
//
//    while (!hi . isFinish()) {
//        std::cout << ' ' << hi.getValue();
//        hi . next();
//    }
//
//    std::cout << std::endl << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;
//
//    ht -> clear();
//
//    std::cout << "Linked hash table is empty? " << ht -> isEmpty() << std::endl;

    const auto ROOT_WORD = "Root";
    const auto S1 = "aa";
    const auto S2 = "Aa";
    const auto S3 = "ba";
    const auto S4 = "ZbBba";
    const auto S5 = "Zbbba";

    auto btw = new BinaryWordTree(ROOT_WORD);

    btw -> addWord(S1);
    btw -> addWord(S1);
    btw -> addWord(S1);
    btw -> addWord(S1);
    btw -> addWord(S1);

    btw -> addWord(S2);

    btw -> addWord(S3);
    btw -> addWord(S3);
    btw -> addWord(S3);

    btw -> addWord(S4);
    btw -> addWord(S4);
    btw -> addWord(S4);

    btw -> addWord(S5);

//    btw -> deleteWord(S5);

//    btw -> deleteWord(S1);
//    btw -> deleteWord(S1);
//    btw -> deleteWord(S1);

//    btw -> deleteWord(S4);
//    btw -> deleteWord(S4);

    btw -> print();

    std::cout << "Tree size = " << btw -> getTreeSize() << std::endl;
    std::cout << "The word " << S1 << " occurs " << btw -> findWordEntries(S1) << " times" << std::endl;

    return 0;
}
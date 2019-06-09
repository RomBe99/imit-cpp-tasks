#ifndef CPP_TASKS_BINARYWORDTREE_H
#define CPP_TASKS_BINARYWORDTREE_H

#include <string>
#include <utility>

class BinaryWordTree {
private:
    class Node {
    public:
        int count = 1;

        std::string word;

        explicit Node(const std::string& word);

        void add();

        virtual ~Node() = default;
    };
};

#endif
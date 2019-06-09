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

        Node* leftLeaf;

        Node* rightLeaf;

        explicit Node(const std::string& word)
                :Node(word, nullptr, nullptr) {};

        explicit Node(const std::string& word, Node* leftLeaf, Node* rightLeaf);

        void add();

        virtual ~Node() = default;
    };

    Node* root = nullptr;

public:
    BinaryWordTree() = default;

    explicit BinaryWordTree(const std::string& rootWord);

    bool isEmpty() const;
};

#endif
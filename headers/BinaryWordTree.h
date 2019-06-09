#ifndef CPP_TASKS_BINARYWORDTREE_H
#define CPP_TASKS_BINARYWORDTREE_H

#include <iostream>

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

        int compare(const std::string& otherString) const;

        static void print(Node*& node);

        static void findNode(Node*& node, bool& isFind, const std::string& word, int& count);

        static void deleteNode(Node*& node);

        virtual ~Node() = default;
    };

    Node* root = nullptr;

    size_t treeSize = 0;

public:
    explicit BinaryWordTree(const std::string& rootWord);

    void print();

    int findWordEntries(const std::string& word);

    bool isEmpty() const;

    size_t getTreeSize() const;

    virtual ~BinaryWordTree();
};

#endif
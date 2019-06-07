#ifndef CPP_TASKS_BINARYTREE_H
#define CPP_TASKS_BINARYTREE_H

#include <iostream>

class BinaryTree {
private:
    class Node {
    public:
        int value;

        Node* rightLeaf;

        Node* leftLeaf;

        explicit Node(int value)
                :Node(value, nullptr, nullptr) {}

        Node(int value, Node* rightLeaf, Node* leftLeaf);

        static void print(const Node* node, long n);

        static bool isPositive(const Node* node);

        static void average(const Node* node, int& sum, int& count);

        static bool check(const Node* node, int min, int max);

        static void deleteNode(Node*& node);

        virtual ~Node() = default;
    };

    Node* root = nullptr;

public:
    BinaryTree() = default;

    explicit BinaryTree(int rootValue);

    void insert(int x, int sequenceSize, const int sequence[]);

    void print() const;

    bool isPositive() const;

    double average() const;

    bool isBinarySearchTree() const;

    bool isEmpty() const;

    virtual ~BinaryTree();
};

#endif
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

        static void print(Node*& node, long n);

        static bool isPositive(Node*& node);

        static void average(Node*& node, int& sum, int& count);

        static bool check(Node*& node, int min, int max);

        static void deleteNode(Node*& node);

        static void deleteAllLeafs(Node*& node);

        virtual ~Node() = default;
    };

    Node* root = nullptr;

public:
    BinaryTree() = default;

    explicit BinaryTree(int rootValue);

    void insert(int x, int sequenceSize, const int sequence[]);

    void print();

    bool isPositive();

    void deleteAllLeafs();

    double average();

    bool isBinarySearchTree();

    bool isEmpty() const;

    virtual ~BinaryTree();
};

#endif
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

        static void numberOfEvenNumbers(Node*& node, int& count);

        static bool isPositive(Node*& node);

        static void deleteNode(Node*& node);

        static void deleteAllLeafs(Node*& node);

        static void average(Node*& node, int& sum, int& count);

        static bool check(Node*& node, const int& min, const int& max);

        virtual ~Node() = default;
    };

    Node* root = nullptr;

public:
    BinaryTree() = default;

    explicit BinaryTree(int rootValue);

    void insert(int x, int sequenceSize, const int sequence[]);

    void print();

    int numberOfEvenNumbers();

    bool isPositive();

    void deleteAllLeafs();

    double average();

    bool isBinarySearchTree();

    bool isEmpty() const;

    virtual ~BinaryTree();
};

#endif
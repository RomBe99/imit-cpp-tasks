#ifndef CPP_TASKS_BINARYTREE_H
#define CPP_TASKS_BINARYTREE_H

#include <iostream>
#include <vector>

class BinaryTree {
private:
    class Node {
    public:
        int value;

        Node* rightLeaf;

        Node* leftLeaf;

        static const int LEFT_DIRECTION_DESIGNATION = 0;

        static const int RIGHT_DIRECTION_DESIGNATION = 1;

        explicit Node(int value)
                :Node(value, nullptr, nullptr) {}

        Node(int value, Node* rightLeaf, Node* leftLeaf);

        static void print(Node*& node, long n);

        static void numberOfEvenNumbers(Node*& node, int& count);

        static bool isPositive(Node*& node);

        static void deleteNode(Node*& node);

        static void deleteAllLeafs(Node*& node);

        static void average(Node*& node, int& sum, int& count);

        static void findRoute(Node*& node, bool& isFind, const int& x, std::vector<int>*& route);

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

    std::vector<int>* findRoute(int x);

    bool isBinarySearchTree();

    bool isEmpty() const;

    virtual ~BinaryTree();
};

#endif
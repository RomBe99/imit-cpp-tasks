#ifndef CPP_TASKS_BINARYTREE_H
#define CPP_TASKS_BINARYTREE_H

class BinaryTree {
private:
    class Node {
    public:
        int value;

        Node* rightLeaf;

        Node* leftLeaf;

        Node(int value)
                :Node(value, nullptr, nullptr) {}

        Node(int value, Node* rightLeaf, Node* leftLeaf);

        virtual ~Node() = default;
    };

    Node* root = nullptr;

public:
    explicit BinaryTree(int rootValue);

    void insert(int x, int sequenceSize, const int sequence[]);

    virtual ~BinaryTree() = default;
};

#endif
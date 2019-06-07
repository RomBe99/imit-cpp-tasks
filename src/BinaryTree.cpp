#include "../headers/BinaryTree.h"

BinaryTree::Node::Node(int value, BinaryTree::Node* rightLeaf, BinaryTree::Node* leftLeaf)
        :value(value), rightLeaf(rightLeaf), leftLeaf(leftLeaf) {}

void BinaryTree::Node::print(const BinaryTree::Node* node, const long n)
{
    if (node == nullptr) return;

    print(node -> rightLeaf, n + 5);

    for (long i = 0; i < n; i++) {
        std::cout << ' ';
    }

    std::cout << node -> value << std::endl;

    print(node -> leftLeaf, n + 5);
}

BinaryTree::BinaryTree(const int rootValue)
{
    root = new Node(rootValue);
}

void BinaryTree::insert(const int x, const int sequenceSize, const int sequence[])
{
    Node* temp = root;

    for (int i = 0; i < sequenceSize; i++) {
        if (sequence[i] == 0) {
            if (temp -> leftLeaf == nullptr) {
                temp -> leftLeaf = new Node(x);

                return;
            }

            temp = temp -> leftLeaf;
        }
        else if (sequence[i] == 1) {
            if (temp -> rightLeaf == nullptr) {
                temp -> rightLeaf = new Node(x);

                return;
            }

            temp = temp -> rightLeaf;

        }
    }

    temp -> value = x;
}

void BinaryTree::print() const
{
    BinaryTree::Node::print(root, 0);
}
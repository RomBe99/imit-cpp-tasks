#include "../headers/BinaryTree.h"

BinaryTree::Node::Node(int value, BinaryTree::Node* rightLeaf, BinaryTree::Node* leftLeaf)
        :value(value), rightLeaf(rightLeaf), leftLeaf(leftLeaf) {}

BinaryTree::BinaryTree(const int rootValue)
{
    root = new Node(rootValue);
}
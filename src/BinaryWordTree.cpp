#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word, Node* leftLeaf, Node* rightLeaf)
{
    this -> word = word;
    this -> leftLeaf = leftLeaf;
    this -> rightLeaf = rightLeaf;
}

void BinaryWordTree::Node::add()
{
    count++;
}

BinaryWordTree::BinaryWordTree(const std::string& rootWord)
{
    root = new Node(rootWord);
}

bool BinaryWordTree::isEmpty() const
{
    return root == nullptr;
}
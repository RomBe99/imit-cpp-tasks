#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word)
{
    this -> word = word;
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
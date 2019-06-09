#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word)
{
    this -> word = word;
}

void BinaryWordTree::Node::add()
{
    count++;
}
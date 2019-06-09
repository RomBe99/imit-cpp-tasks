#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(std::string word)
{
    this -> word = std::move(word);
}

void BinaryWordTree::Node::add()
{
    count++;
}
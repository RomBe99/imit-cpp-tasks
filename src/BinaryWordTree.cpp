#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word, Node* leftLeaf, Node* rightLeaf)
{
    if (word.length() == 0) {
        throw std::exception();
    }

    this -> word = word;
    this -> leftLeaf = leftLeaf;
    this -> rightLeaf = rightLeaf;
}

void BinaryWordTree::Node::add()
{
    count++;
}

void BinaryWordTree::Node::deleteNode(BinaryWordTree::Node*& node)
{
    if (node != nullptr) {
        deleteNode(node -> leftLeaf);
        deleteNode(node -> rightLeaf);
        delete node;
        node = nullptr;
    }
}

int BinaryWordTree::Node::compare(const std::string& otherString) const
{
    if (otherString.length() == 0) {
        throw std::exception();
    }

    return word.compare(otherString);
}

BinaryWordTree::BinaryWordTree(const std::string& rootWord)
{
    root = new Node(rootWord);
    treeSize = 1;
}

bool BinaryWordTree::isEmpty() const
{
    return root == nullptr;
}

BinaryWordTree::~BinaryWordTree()
{
    BinaryWordTree::Node::deleteNode(root);
}
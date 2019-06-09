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

void BinaryWordTree::Node::deleteNode(BinaryWordTree::Node*& node)
{
    if (node != nullptr) {
        deleteNode(node -> leftLeaf);
        deleteNode(node -> rightLeaf);
        delete node;
        node = nullptr;
    }
}

BinaryWordTree::BinaryWordTree(const std::string& rootWord)
{
    root = new Node(rootWord);
}

bool BinaryWordTree::isEmpty() const
{
    return root == nullptr;
}

BinaryWordTree::~BinaryWordTree()
{
    BinaryWordTree::Node::deleteNode(root);
}
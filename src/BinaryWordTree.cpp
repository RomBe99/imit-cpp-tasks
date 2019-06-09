#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word, Node* leftLeaf, Node* rightLeaf)
{
    if (word . length() == 0) {
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

void BinaryWordTree::Node::print(BinaryWordTree::Node*& node, const long& n)
{
    if (node == nullptr) return;

    const int SHIFT = 5;

    print(node -> rightLeaf, n + SHIFT);

    for (long i = 0; i < n; i++) {
        std::cout << ' ';
    }

    std::cout << node -> word << std::endl;

    print(node -> leftLeaf, n + SHIFT);
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
    if (otherString . length() == 0) {
        throw std::exception();
    }

    return word . compare(otherString);
}

BinaryWordTree::BinaryWordTree(const std::string& rootWord)
{
    root = new Node(rootWord);
    treeSize = 1;
}

void BinaryWordTree::print()
{
    if (isEmpty()) {
        std::cout << "Binary tree is empty" << std::endl;
    }
    else {
        BinaryWordTree::Node::print(root, 0);
    }
}

bool BinaryWordTree::isEmpty() const
{
    return root == nullptr;
}

size_t BinaryWordTree::getTreeSize() const
{
    return treeSize;
}

BinaryWordTree::~BinaryWordTree()
{
    BinaryWordTree::Node::deleteNode(root);
}